//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_MODEL_HPP
#define SHARECOUNT_MODEL_HPP

#include "Utilisateur.hpp"
#include "regex"
#include <cctype>

/**
 * @brief Classe facade en interaction avec l'interface et la base de donnée
 * @author Guillaume Vautrin
 * @version v1
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
 * @version v2
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


};


#endif //SHARECOUNT_MODEL_HPP
