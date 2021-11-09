//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_UTILISATEUR_H
#define SHARECOUNT_UTILISATEUR_H

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
    Utilisateur(std::string n, std::string p);

    ~Utilisateur();


    void setNom(std::string n);
    void setPrenom(std::string p);
    void setPseudo (std::string pseudo);
    void setMdp (std::string mdp);

    bool verifID ();

    std::string getNom();
    std::string getPrenom();
    std::string getPseudo();

    std::string toString();

    Utilisateur(const std::string pseudo, const std::string email, const std::string mdp);
};


#endif //SHARECOUNT_UTILISATEUR_H
