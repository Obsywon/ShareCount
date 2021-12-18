#ifndef SHARECOUNT_MODEL_HPP
#define SHARECOUNT_MODEL_HPP

#include "GestionnaireGroupes.hpp"
#include "regex"
#include <cctype>

/**
 * @brief Classe facade en interaction avec l'interface et la base de donnée
 * @author Guillaume Vautrin
 * @version v5
 */
class Model {
private:
    Utilisateur m_user;
    GestionnaireGroupes m_groupes;

public:

/**
 * @brief Classe facade en interaction avec l'interface et la base de donnée
 * @author Guillaume Vautrin
 * @version v1
 */
    Model();

/**
 * @brief Vérifie si le mot de passe est valide
 * @param mdp mot de passe
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
 */
    bool estValideMdP (const std::string& mdp);

/**
 * @brief Vérifie si l'e-mail est valide
 * @param email e-mail
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
 */
    bool estValideEmail (const std::string& email);

/**
 * @brief Inscrit l'utilisateur
 * @param pseudo pseudonyme
 * @param email Email
 * @param mdp Mot de passe
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
 */
    bool inscrireUtilisateur (std::string pseudo, std::string email, std::string mdp);

/**
 * @brief Vérifie si le compte existe
 * @param pseudo pseudonyme
 * @param mdp mot de passe
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
 */
    bool compteExiste (const std::string& pseudo, const std::string& mdp);

/**
 * @brief Connecte l'utilisateur
 * @param pseudo pseudonyme
 * @param email email
 * @param mdp mot de passe
 * @return bool
 * @author Guillaume Vautrin
 * @version v5 - modifs
 */
    void connecterUtilisateur (std::string pseudo, std::string email, std::string mdp);

/**
 * @brief Décris l'utilisateur
 * @author Guillaume Vautrin
 * @version v1
 * @return string
 */
    std::string userToString();

/**
 * @brief Décris les groupes connus
 * @author Guillaume Vautrin
 * @version v3
 * @return string
 */
    std::string  groupesToString();

/**
 * @brief Créer un groupe
 * @param nom nom du nouveau groupe
 * @author Guillaume Vautrin
 * @version v3
 * @return string
 */
    void creerGroupe (std::string nom);

/**
* @brief Créer un événement
* @param IDgroupe identifiant groupe
* @param nom nom du groupe
* @param dateDeb date de début
* @param dateFin date de fin
* @author Guillaume Vautrin
* @version v5
* @return string
*/
    void creerEvenement (std::string IDgroupe, std::string nom, std::string dateDeb,std::string dateFin);

/**
* @brief Ajoute un membre à un groupe
* @param idGroupe identifiant du groupe
* @param u utilisateur à ajouter au groupe
* @author Guillaume Vautrin
* @version v5
* @return string
*/
    void ajouterMembreAGroupe(std::string idGroupe,const Utilisateur* u);

/**
 * @brief Décris le modèle
 * @author Guillaume Vautrin
 * @version v5
 * @return string
 */
    std::string toString();

/**
* @brief Créer une liste d'identifants
* @return liste identifiants
* @author Guillaume Vautrin
* @version v6
*/
std::vector <std::string> listeIDs();

/**
* @brief Créer une liste de noms
* @return liste noms
* @author Guillaume Vautrin
* @version v6
*/
std::vector <std::string> listeNoms();

};


#endif //SHARECOUNT_MODEL_HPP
