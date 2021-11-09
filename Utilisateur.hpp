//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_UTILISATEUR_HPP
#define SHARECOUNT_UTILISATEUR_HPP

#include <cstdlib>
#include <string>
#include <iostream>


class Utilisateur {
private:
    std::string m_nom;
    std::string m_prenom;
    std::string m_pseudo;
    std::string m_password;
    std::string m_email;
    //double m_valeur;
    //double m_id;

public:

    Utilisateur();
    /**
     * Créer un utilisateur
     * @param pseudo Pseudo utilisé sur l'application
     * @param email E-mail utilisé pour s'enregistrer
     * @param mdp Mot de passe permettant la connection
     */
    Utilisateur(const std::string pseudo, const std::string email, const std::string mdp);
    ~Utilisateur();


    void setNom(std::string n);
    void setPrenom(std::string p);
    void setPseudo (std::string pseudo);
    void setMdp (std::string mdp);

    std::string getNom();
    std::string getPrenom();
    std::string getPseudo();

    std::string toString();

};


#endif //SHARECOUNT_UTILISATEUR_HPP
