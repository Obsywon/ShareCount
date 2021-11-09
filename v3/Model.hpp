//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_MODEL_HPP
#define SHARECOUNT_MODEL_HPP

#include "Utilisateur.hpp"
#include "regex"
#include <cctype>


class Model {
private:
    Utilisateur m_user;
    GestionnaireGroupes m_groupes;

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
    bool estValideMdP (const std::string& mdp);

    /**
     * Vérifie si l'e-mail entrée est valide
     * @param email string
     * @return bool
     */
    bool estValideEmail (const std::string& email);

    /**
     * Inscrire un utilisateur
     * @param pseudo pseudo
     * @param email email
     * @param mdp mdp
     * @return bool true si utilisateur est bien inscris
     */
    bool inscrireUtilisateur (std::string pseudo, std::string email, std::string mdp);

    /**
     * Vérifie si un utilisateur existe bien dans la base de données
     * @param pseudo string
     * @param mdp string
     * @return bool
     */
    bool compteExiste (const std::string& pseudo, const std::string& mdp);

    /**
     * Connecte et charge le compte utilisateur indiqué (A RETRAVAILLER!!!
     * lorsqu'un moyen d'enregistrer les données sera implémenté)
     * @param pseudo string
     * @param email string
     * @param mdp string
     */
    void connecterUtilisateur (std::string pseudo, std::string email, std::string mdp);

    std::string userToString();
    std::string  groupesToString();

    void creerGroupe (std::string nom);


};


#endif //SHARECOUNT_MODEL_HPP
