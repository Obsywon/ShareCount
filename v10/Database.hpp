#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>


/**
 * Classe contrôlant la base de données
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
 */
class Database
{

private:
/**
* @brief Base de données SQLite
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    QSqlDatabase m_dbb;

/**
* Vérifie l'existence d'un élément dans une table à partir de son identifiant
* @param id identifiant
* @param table table visée
* @param key nom de la clé dans la table
* @return bool
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    bool existe (const int& id, const QString& table, const QString& key);

public:
/**
* @brief Vérifie la possibilité de se connecter à une base de donnée et prépare celle-ci
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    Database();

/**
* @brief Initialise la base de données avec les tables relationnelles
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    void initialisation();


/**
* @brief Ajoute un utilisateur à la tables des utilisateur de la base de données
* @param pseudo string pseudo de l'utilisateur
* @param email string email de l'utilisateur
* @param mdp string mot de passe
* @return int identifiant de l'utilisateur générée par la base de données
* @authors Guillaume Vautrin
* @version v10 (Dernière modification)
*/
    int ajouterUtilisateur(const std::string& pseudo, const std::string& email, const std::string& mdp);


/**
* Vérifie si un utilisateur existe dans la base de données
* @param email peut-être vide
* @param pseudo
* @param mdp
* @return booléen
* @authors Guillaume Vautrin
* @version v10 (Dernière modification)
*/
    bool existeUtilisateur(const std::string& email, const std::string& pseudo, const std::string& mdp);

/**
* Récupère l'identifiant d'un utilisateur
* @param email peut-être vide
* @param pseudo
* @param mdp
* @return id
* @authors Guillaume Vautrin
* @version v10 (Dernière modification)
*/
    int getUserID(const std::string& pseudo, const std::string& mdp);

};

#endif // DATABASE_HPP
