#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <vector>
#include "Groupe.hpp"


class Groupe;

/**
 * Classe contrôlant la base de données
* @authors Guillaume Vautrin
* @version v12 (Dernière modification)
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
* @brief Charge les caractéristiques de bases des groupes connus pas l'utilisateur
* @param user_id identifiant de l'utilisateur connecté
* @authors Guillaume Vautrin
* @version v13 (Dernière modification)
*/
    const std::unordered_map<int, std::string> load_groupes(const int& user_id);


/**
* @brief Initialise la base de données avec les tables relationnelles
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    void initialisation();

/**
* @brief Ajoute un groupe à la base de donnée sur les tables groupe et participations
* @param id_user identifiant de l'utilisateur qui participe à ce groupe
* @param nom nom du groupe
* @return int entier correspondant à l'identifiant du nouveau groupe
* @authors Guillaume Vautrin
* @version v11 (Dernière modification)
*/
    int ajouterGroupe(const int& id_user, const std::string& nom);

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
 * Ajoute un événement à la base de données
 * @param id_groupe identifiant du groupe
 * @param nom Nom de l'événement
 * @param dateDeb date de début de l'événement
 * @param dateFin date de fin de l'événement
 * @return identifiant de l'événement
 * @authors Guillaume Vautrin
 * @version v12 (Dernière modification)
 */
    int ajouterEvenement (const int& id_groupe, const std::string& nom, const std::string& dateDeb, const std::string& dateFin);

/**
* Vérifie si un utilisateur existe basé sur son identifiant
* @param id int identifant
* @return booléen
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    bool existeUtilisateur(const int& id);

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
* Vérifie si un groupe existe basé sur son identifiant
* @param id int identifiant
* @return booléen
* @authors Guillaume Vautrin
* @version v11 (Dernière modification)
*/
    bool existeGroupe(const int& id);
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
