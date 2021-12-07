#include "Database.hpp"


/**
 * @brief Vérifie la possibilité de se connecter à une base de donnée et prépare celle-ci
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
 */
Database::Database()
{
    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER)){
        qWarning() << "Erreur : La base de données a un problème de driver.";
        exit(EXIT_FAILURE);
    }
    m_dbb = QSqlDatabase::addDatabase(DRIVER);
    m_dbb.setDatabaseName("ShareCount.db");

    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }

}


/**
* @brief Initialise la base de données avec les tables relationnelles
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
void Database::initialisation(){
    QSqlQuery query; // Génère les requêtes

    // Création de la table Utilisateurs, contenant les profils d'utilisateurs
    query.prepare("CREATE TABLE IF NOT EXISTS utilisateur "
                  "(user_id integer PRIMARY KEY AUTOINCREMENT, "
                  "nom VARCHAR(50), "
                  "prenom VARCHAR(50), "
                  "email VARCHAR(100) NOT NULL UNIQUE, "
                  "pseudo VARCHAR(100) NOT NULL UNIQUE, "
                  "password VARCHAR(32) NOT NULL)");
    query.exec();
    //qWarning() << query.lastError();

    // Création de la table groupe, contenant les groupes existants et leurs caractéristiques
    query.prepare("CREATE TABLE IF NOT EXISTS groupe ("
                  "group_id integer PRIMARY KEY AUTOINCREMENT, "
                  "group_nom VARCHAR(50) NOT NULL)");
    query.exec();
    //qWarning() << query.lastError();

    // Création de la table participation, qui relie chaque utilisateurs aux groupes auxquels ils participent.
    query.prepare("CREATE TABLE IF NOT EXISTS participation ("
                  "user_id integer NOT NULL, "
                  "group_id integer NOT NULL, "
                  "FOREIGN KEY(user_id) REFERENCES utilisateur(user_id),"
                  "FOREIGN KEY(group_id) REFERENCES groupe(group_id))");

    query.exec();
    //qWarning() << query.lastError();

    // Création de la table événement, qui détaille les contenus d'un événement
    query.prepare("CREATE TABLE IF NOT EXISTS evenement ("
                  "event_id integer PRIMARY KEY AUTOINCREMENT, "
                  "group_id integer NOT NULL, "
                  "event_nom VARCHAR(50) NOT NULL, "
                  "date_deb DATETIME default current_timestamp NOT NULL, "
                  "date_fin DATETIME default current_timestamp NOT NULL, "
                  "FOREIGN KEY(group_id) REFERENCES groupe(group_id))");
    query.exec();
    //qWarning() << query.lastError();

    query.clear(); // Nettoie la requête
    m_dbb.close(); // Termine la connection avec la base de donnée
}


/**
* @brief Charge les caractéristiques de bases des événements liés à un groupe
* @param group_id identifiant du groupe sélectionné
* @authors Guillaume Vautrin
* @version v14 (Dernière modification)
*/
const std::unordered_map <int, std::vector<std::string>> Database::load_events(const int& group_id){
    std::unordered_map <int, std::vector<std::string>> events;


    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }

    QSqlQuery query;
    query.prepare("SELECT e.event_id, e.event_nom, e.date_deb, e.date_fin FROM groupe g, evenement e"
                  " WHERE g.group_id = e.group_id AND g.group_id = :id");
    query.bindValue(":id", group_id);
    query.exec();

    int id;
    //std::string content[3];

    // Construit la map contenant les données nominatives du groupes
    while (query.next()) {
        std::vector <std::string> content;
         id = query.value(0).toInt();
         content.push_back(query.value(1).toString().toStdString());
         content.push_back(query.value(2).toString().toStdString());
         content.push_back(query.value(3).toString().toStdString());
         events[id] = std::vector<std::string> ();
         events[id] = content;

         //qWarning() <<  QString::fromStdString(content.at(1));
     }


    query.clear();
    m_dbb.close();

    return events;

}

/**
* @brief Charge les caractéristiques de bases des groupes connus pas l'utilisateur
* @param user_id identifiant de l'utilisateur connecté
* @authors Guillaume Vautrin
* @version v13 (Dernière modification)
*/
const std::unordered_map <int, std::string> Database::load_groupes(const int& user_id){
    std::unordered_map <int, std::string> groupes;

    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }

    QSqlQuery query;
    query.prepare("SELECT p.group_id, g.group_nom FROM participation p, groupe g WHERE p.user_id = :id AND p.group_id = g.group_id");
    query.bindValue(":id", user_id);
    query.exec();

    int id;
    std::string nom;

    // Construit la map contenant les données nominatives du groupes
    while (query.next()) {
         id = query.value(0).toInt();
         nom = query.value(1).toString().toStdString();
         groupes[id] = nom;
     }

    query.clear();
    m_dbb.close();

    return groupes;
}

/**
* @brief Ajoute un groupe à la base de donnée sur les tables groupe et participations
* @param id_user identifiant de l'utilisateur qui participe à ce groupe
* @param nom nom du groupe
* @return int entier correspondant à l'identifiant du nouveau groupe
* @authors Guillaume Vautrin
* @version v11 (Dernière modification)
*/
int Database::ajouterGroupe(const int& id_user, const std::string& nom){
    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }
    //m_dbb.open(); // Ouvre la connection à la base de données

    QSqlQuery query, query2;
    query.prepare("INSERT INTO groupe(group_nom) VALUES (:groupe_nom)");
    query.bindValue(":groupe_nom", QString::fromStdString(nom));
    query.exec();

    // Récupère la clé du groupe
    int id = query.lastInsertId().toInt();

    // Actualise la table de participation pour connaître quel groupe connaît quel utilisateur
    query2.prepare("INSERT INTO participation(group_id, user_id) VALUES (:g, :u)");
    query2.bindValue(":u", id_user);
    query2.bindValue(":g", id);
    query2.exec();

    // Nettoie les requêtes et ferme la base de donnée
    query.clear();
    query2.clear();
    m_dbb.close();
    return id;  // Retourne l'identifiant de l'utilisateur (permet de le donner à l'utilisateur)
}

/**
 * @brief Ajoute un utilisateur à la tables des utilisateur de la base de données
 * @param pseudo string pseudo de l'utilisateur
 * @param email string email de l'utilisateur
 * @param mdp string mot de passe
 * @return int identifiant de l'utilisateur générée par la base de données
* @authors Guillaume Vautrin
* @version v10 (Dernière modification)
 */
int Database::ajouterUtilisateur(const std::string& pseudo, const std::string& email, const std::string& mdp){
    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }
    //m_dbb.open(); // Ouvre la connection à la base de données
    QSqlQuery query;

    // Execution de la requête (insertion d'un utilisateur dans la base de données)
    query.prepare("INSERT INTO utilisateur(pseudo, email, password) VALUES (:pseudo, :email, :password)");
    query.bindValue(":pseudo", QString::fromStdString(pseudo));
    query.bindValue(":email", QString::fromStdString(email));
    query.bindValue(":password", QString::fromStdString(mdp));
    query.exec();

    // Récupère la clé de l'utilisateur
    int id = query.lastInsertId().toInt();
    query.clear(); // Nettoie la requête
    m_dbb.close();
    return id;  // Retourne l'identifiant de l'utilisateur (permet de le donner à l'utilisateur)

}

/**
 * Vérifie l'existence d'un élément dans une table à partir de son identifiant
 * @param id identifiant
 * @param table table visée
 * @param key nom de la clé dans la table
 * @return bool
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
 */
bool Database::existe (const int& id, const QString& table, const QString& key){
    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }
    bool existe; // Renseigne sur l'existence d'un utilisateur
    int nbExistant = 0; // Nombre d'éléments correspondant
    m_dbb.open(); // Ouvre la connection à la base de données

    // Compte le nombre d'éléments correspondant à l'id sur la table renseignée
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM " + table +" WHERE " + key +" = :id");
    query.bindValue(":id", id);
    query.exec();
    while (query.next()) {
         nbExistant = query.value(0).toInt();
     }
    if (nbExistant != 0){
        existe = true;
    }else{
        existe = false;
    }

    query.clear(); // Nettoie la requête
    m_dbb.close();
    return existe;
}


/**
* Vérifie si un utilisateur existe basé sur son identifiant
* @param id int identifant
* @return booléen
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
bool Database::existeUtilisateur(const int& id){
    QString table = QString("utilisateur");
    QString key = QString("user_id");
    return existe(id, table, key);
}

/**
* Vérifie si un groupe existe basé sur son identifiant
* @param id int identifiant
* @return booléen
* @authors Guillaume Vautrin
* @version v11 (Dernière modification)
*/
bool Database::existeGroupe(const int& id){
    QString table = QString("groupe");
    QString key = QString("group_id");
    return existe(id, table, key);
}

/**
 * Vérifie si un utilisateur existe dans la base de données
 * @param email peut-être vide
 * @param pseudo
 * @param mdp
 * @return booléen
 * @authors Guillaume Vautrin
 * @version v10 (Dernière modification)
 */
bool Database::existeUtilisateur(const std::string& email, const std::string& pseudo, const std::string& mdp){
    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }
    bool existe;
    int nbExistant = 0; // Nombre d'éléments correspondant
    // Compte le nombre d'éléments correspondant à l'id sur la table renseignée
    QSqlQuery query;
    if (!email.empty()){
        query.prepare("SELECT COUNT(*) FROM utilisateur WHERE pseudo = :pseudo AND "
                      "email = :mail AND password = :mdp");
        query.bindValue(":pseudo", QString::fromStdString(pseudo));
        query.bindValue(":mail", QString::fromStdString(email));
        query.bindValue(":mdp", QString::fromStdString(mdp));
    }else{
        query.prepare("SELECT COUNT(*) FROM utilisateur WHERE pseudo = :pseudo AND password = :mdp");
        query.bindValue(":pseudo", QString::fromStdString(pseudo));
        query.bindValue(":mdp", QString::fromStdString(mdp));
    }

    query.exec();

    // Parcours des réponses
    while (query.next()) {
         nbExistant = query.value(0).toInt();
     }
    if (nbExistant != 0){
        existe = true;
    }else{
        existe = false;
    }

    query.clear(); // Nettoie la requête
    m_dbb.close();

    return existe;
}

/**
 * Récupère l'identifiant d'un utilisateur
 * @param email peut-être vide
 * @param pseudo
 * @param mdp
 * @return id
 * @authors Guillaume Vautrin
 * @version v10 (Dernière modification)
 */
int Database::getUserID(const std::string& pseudo, const std::string& mdp){
    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }

    QSqlQuery query;
    query.prepare("SELECT user_id FROM utilisateur WHERE pseudo = :pseudo AND password = :mdp");
    query.bindValue(":pseudo", QString::fromStdString(pseudo));
    query.bindValue(":mdp", QString::fromStdString(mdp));
    query.exec();
    int id = 0;
    // Parcours des réponses
    while (query.next()) {
         id = query.value(0).toInt();
     }
    query.clear(); // Nettoie la requête
    m_dbb.close();
    return id;
}


/**
 * Ajoute un événement à la base de données
 * @param id_groupe identifiant du groupe
 * @param nom Nom de l'événement
 * @return identifiant de l'événement
 * @authors Guillaume Vautrin
 * @version v12 (Dernière modification)
 */
int Database::ajouterEvenement (const int& id_groupe, const std::string& nom, const std::string& dateDeb, const std::string& dateFin)
{
    if (!m_dbb.open()){ // ouverture de la connexion à la base de données
        qWarning() << "Erreur : " << m_dbb.lastError();
    }
    QString n, d, f;
    n = QString::fromStdString(nom);
    d = QString::fromStdString(dateDeb);
    f = QString::fromStdString(dateFin);

    QSqlQuery query;
    query.clear();
    query.prepare("INSERT INTO evenement(group_id, event_nom, date_deb, date_fin) VALUES (?, ?, ?, ?)");

    query.addBindValue(id_groupe);
    query.addBindValue(n);
    query.addBindValue(d);
    query.addBindValue(f);
    query.exec();

    // Récupère la clé du groupe
    int id = query.lastInsertId().toInt();


    // Nettoie les requêtes et ferme la base de donnée
    query.clear();
    m_dbb.close();
    return id;  // Retourne l'identifiant de l'utilisateur (permet de le donner à l'utilisateur)
}

