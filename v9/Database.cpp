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
    qWarning() << query.lastError();

    // Création de la table groupe, contenant les groupes existants et leurs caractéristiques
    query.prepare("CREATE TABLE IF NOT EXISTS groupe ("
                  "group_id integer PRIMARY KEY AUTOINCREMENT, "
                  "group_nom VARCHAR(50) NOT NULL)");
    query.exec();
    qWarning() << query.lastError();

    // Création de la table participation, qui relie chaque utilisateurs aux groupes auxquels ils participent.
    query.prepare("CREATE TABLE IF NOT EXISTS participation ("
                  "user_id integer NOT NULL, "
                  "group_id integer NOT NULL, "
                  "FOREIGN KEY(user_id) REFERENCES utilisateur(user_id),"
                  "FOREIGN KEY(group_id) REFERENCES groupe(group_id))");


                  //"PRIMARY KEY (user_id, group_id))");
    query.exec();
    qWarning() << query.lastError();

    // Création de la table événement, qui détaille les contenus d'un événement
    query.prepare("CREATE TABLE IF NOT EXISTS evenement ("
                  "event_id integer PRIMARY KEY AUTOINCREMENT, "
                  "group_id integer NOT NULL, "
                  "event_nom VARCHAR(50) NOT NULL, "
                  "date_deb DATETIME default current_timestamp NOT NULL, "
                  "date_fin DATETIME default current_timestamp NOT NULL, "
                  "FOREIGN KEY(group_id) REFERENCES groupe(group_id))");
    query.exec();
    qWarning() << query.lastError();

    query.clear(); // Nettoie la requête
    m_dbb.close(); // Termine la connection avec la base de donnée
}



