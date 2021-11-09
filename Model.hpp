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
     * Créer le modèle, classe facade
     */
    Model();

    /**
     * Permet de vérifier la validité du mot de passe
     * @param mdp string
     * @return bool
     */
    bool estValideMdP (const std::string mdp);

    /**
     * Vérifie si l'e-mail entrée est valide
     * @param email string
     * @return bool
     */
    bool estValideEmail (const std::string email);

    /**
     * Inscrire un utilisateur
     * @param pseudo pseudo
     * @param email email
     * @param mdp mdp
     * @return bool true si utilisateur est bien inscris
     */
    bool inscrireUtilisateur (const std::string pseudo, const std::string email, const std::string mdp);

    const std::string userToString();






};


#endif //SHARECOUNT_MODEL_HPP
