//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_MODEL_HPP
#define SHARECOUNT_MODEL_HPP

#include "Utilisateur.hpp"
#include "regex"

class Model {
private:
    Utilisateur m_user;



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
    bool estValideMdP (const std::string mdp);

/**
 * @brief Vérifie si l'e-mail est valide
 * @param email e-mail
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
 */
    bool estValideEmail (const std::string email);

/**
 * @brief Inscrit l'utilisateur
 * @param pseudo pseudonyme
 * @param email Email
 * @param mdp Mot de passe
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
 */
    bool inscrireUtilisateur (const std::string pseudo, const std::string email, const std::string mdp);

    /**
 * @brief Décris le modèle
 * @author Guillaume Vautrin
 * @version v1
 * @return string
 */
    const std::string userToString();

};


#endif //SHARECOUNT_MODEL_HPP
