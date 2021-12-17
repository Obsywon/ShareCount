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

    // Création de la table participation, qui relie chaque utilisateurs aux groupes auxquels ils participent.
    query.prepare("CREATE TABLE IF NOT EXISTS participation ("
                  "user_id integer NOT NULL, "
                  "group_id integer NOT NULL, "
                  "FOREIGN KEY(user_id) REFERENCES utilisateur(user_id),"
                  "FOREIGN KEY(group_id) REFERENCES groupe(group_id),"
                  "UNIQUE (user_id, group_id))");

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

    // Création de la table cagnotte
    query.prepare("CREATE TABLE IF NOT EXISTS cagnotte ("
                  "cagnotte_id integer PRIMARY KEY AUTOINCREMENT, "
                  "group_id integer NOT NULL UNIQUE, "
                  "objectif integer DEFAULT 0.00, "
                  "FOREIGN KEY(group_id) REFERENCES groupe(group_id))");

    query.exec();
    // Création de la table transaction
    query.prepare("CREATE TABLE IF NOT EXISTS transac ("
                  "transaction_id integer PRIMARY KEY AUTOINCREMENT, "
                  "cagnotte_id integer NOT NULL, "
                  "user_id integer NOT NULL, "
                  "montant integer DEFAULT 0.00, "
                  "FOREIGN KEY(cagnotte_id) REFERENCES cagnotte(cagnotte_id), "
                  "FOREIGN KEY(user_id) REFERENCES utilisateur(user_id))");

    query.exec();

    // Création d'une vue représentant la somme totale de la cagnotte
    query.prepare("CREATE VIEW IF NOT EXISTS total_cagnotte as "
                  "SELECT t.cagnotte_id, SUM(t.montant) as somme_cagnotte DEFAULT 0.00 "
                   "FROM transac t, cagnotte c "
                   "WHERE c.cagnotte_id = t.cagnotte_id "
                   "GROUP BY t.cagnotte_id");
    query.exec();
    //qWarning() << query.lastError();




    query.clear(); // Nettoie la requête
    m_dbb.close(); // Termine la connection avec la base de donnée
}


/**
* @brief Récupère l'historique des transferts des utilisateurs d'une cagnotte
* @param group_id identifiant du groupe sélectionné
* @return hashmap
* @authors Guillaume Vautrin
* @version v16 (Dernière modification)
*/
const std::unordered_map <int, double> Database::historiqueTransfertsCagnotte (const int& id_group){
    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }

    std::unordered_map <int, double> historique;

    // Récupère la somme total d'une cagnotte
    QSqlQuery query;
    query.prepare("SELECT u.user_id, t.montant FROM cagnotte c, transac t, utilisateur u WHERE u.user_id = t.user_id AND group_id = ?");
    query.addBindValue(id_group);
    query.exec();

    double montant = 0;
    int id = 0;
    while (query.next()) {
        id = query.value(0).toInt();
         montant = query.value(1).toDouble();
         historique[id] = montant;
     }


    query.clear();
    m_dbb.close();
    return historique;
}

/**
* @brief Ajoute une transaction
* @param group_id identifiant du groupe sélectionné
* @return somme total de la cagnotte du groupe
* @authors Guillaume Vautrin
* @version v16 (Dernière modification)
*/
bool Database::effectueTransfert (const int& group_id, const int& user_id, const double& montant){
    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }
    bool success = false;

    // Sélectionne la cagnotte
    QSqlQuery query, query2;
    query.prepare("SELECT cagnotte_id FROM cagnotte WHERE group_id = ?");
    query.addBindValue(group_id);
    query.exec();

    // Récupère l'id de la cagnotte
    int cagnotte_id = -1;
    while (query.next()) {
         cagnotte_id = query.value(0).toDouble();
     }


    if (cagnotte_id > -1){ // Si valide, vérifie
        query.prepare("SELECT somme_cagnotte FROM total_cagnotte "
                      " WHERE cagnotte_id = ?");
        query.addBindValue(cagnotte_id);
        query.exec();

        // Par défaut cette valeur est 0
        double somme = 0;
        while (query.next()) {
             somme = query.value(0).toDouble();
         }

        if ((somme + montant) > 0){     // Ajoute une transaction
            success = true;
            query2.prepare("INSERT INTO transac(cagnotte_id, user_id, montant) "
                          "VALUES (?, ?, ?)");
            query2.addBindValue(cagnotte_id);
            query2.addBindValue(user_id);
            query2.addBindValue(montant);
            query2.exec();
        }
    }
    query.clear();
    query2.clear();
    m_dbb.close();
    return success;
}

/**
* @brief Récupère la somme de la cagnotte
* @param group_id identifiant du groupe sélectionné
* @return somme total de la cagnotte du groupe
* @authors Guillaume Vautrin
* @version v16 (Dernière modification)
*/
double Database::getSommeGroupe (const int& group_id) {
    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }

    // Récupère la somme total d'une cagnotte
    QSqlQuery query;
    query.prepare("SELECT tg.somme_cagnotte FROM total_cagnotte tg, cagnotte g "
                  " WHERE tg.cagnotte_id = g.cagnotte_id AND g.group_id = ?");
    query.addBindValue(group_id);
    query.exec();

    // Par défaut cette valeur est 0
    double montant = 0;
    while (query.next()) {
         montant = query.value(0).toDouble();
     }


    query.clear();
    m_dbb.close();
    return montant;
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
* @version v16 (Dernière modification) : ajout cagnotte
*/
int Database::ajouterGroupe(const int& id_user, const std::string& nom){
    if (!m_dbb.open()){
        qWarning() << "Erreur : " << m_dbb.lastError();
    }
    //m_dbb.open(); // Ouvre la connection à la base de données

    QSqlQuery query, query2, query3;
    query.prepare("INSERT INTO groupe(group_nom) VALUES (:groupe_nom)");
    query.bindValue(":groupe_nom", QString::fromStdString(nom));
    query.exec();

    // Récupère la clé du groupe
    int id = query.lastInsertId().toInt();


    // Génère une cagnotte sans objectif
    query3.prepare ("INSERT INTO cagnotte(group_id) VALUES (:id)");
    query3.bindValue(":id", id);
    query3.exec();


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

/**
 * Ajoute un membre au groupe si il existe et n'est pas déjà dans ce groupe
 * @param id identifiant du groupe
 * @param pseudo du compte
 * @return boolean
 * @authors Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
bool Database::inviterMembre(const int& id_groupe, const std::string& pseudo){
    bool aFonctionne = false;
    if (!m_dbb.open()){ // ouverture de la connexion à la base de données
        qWarning() << "Erreur : " << m_dbb.lastError();
    }

    QString pseudon = QString::fromStdString(pseudo);
    QSqlQuery query;
    query.prepare("SELECT user_id FROM utilisateur WHERE pseudo LIKE ?");
    query.addBindValue(pseudon);
    query.exec();

    // Recherche de l'identifiant de l'utilisateur correspondant à ce pseudo
    int cmpt=0;
    int id_user;
    while (query.next()){
        id_user = query.value(0).toInt();
        cmpt++;
    }
    query.clear();

    if (cmpt == 1) { // Ajout, si possible, d'un utilisateur à la table de participation lié au groupe
        query.prepare("INSERT OR IGNORE INTO participation(group_id, user_id) VALUES (?, ?)");

        query.addBindValue(id_groupe);
        query.addBindValue(id_user);
        query.exec();
        aFonctionne = true;
    } // Sinon, on n'effectue pas l'ajout et on signale une erreur.

    // Nettoie les requêtes et ferme la base de donnée
    query.clear();
    m_dbb.close();
    return aFonctionne;
}

/**
 * Récupère les données pertinentes liées aux participants d'un groupe
 * @param id identifiant du groupe
 * @return bool hashmap
 * @authors Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
const std::unordered_map <int, std::string> Database::load_members (const int& id_group){
    std::unordered_map <int, std::string> membres;
    if (!m_dbb.open()){ // ouverture de la connexion à la base de données
        qWarning() << "Erreur : " << m_dbb.lastError();
    }

    // Récupération des identifiants et pseudo des membres d'un groupe
    QSqlQuery query;
    query.prepare("SELECT u.user_id, u.pseudo FROM utilisateur u, participation p "
                  "WHERE p.group_id = ? AND u.user_id = p.user_id");
    query.addBindValue(id_group);
    query.exec();

    // Stockage des informations récupérées dans une hashmap
    int id_user;
    std::string nom;
    //qWarning() << query.size();
    while (query.next()){

        id_user = query.value(0).toInt();
        //qWarning() << id_user;
        nom = query.value(1).toString().toStdString();
        membres[id_user] = nom;
    }

    // Fermeture de la connexion et retour hashmap
    query.clear();
    m_dbb.close();
    return membres;
}
