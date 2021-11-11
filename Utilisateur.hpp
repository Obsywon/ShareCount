#ifndef SHARECOUNT_UTILISATEUR_HPP
#define SHARECOUNT_UTILISATEUR_HPP

#include <cstdlib>
#include <iostream>

class GestionnaireGroupes;

class Utilisateur {
private:
    std::string m_nom;
    std::string m_prenom;
    std::string m_pseudo;
    std::string m_password;
    std::string m_email;
    GestionnaireGroupes* m_groupes;

public:

    Utilisateur();
    /**
     * Créer un utilisateur
     * @param pseudo Pseudo utilisé sur l'application
     * @param email E-mail utilisé pour s'enregistrer
     * @param mdp Mot de passe permettant la connection
     */
    Utilisateur(const std::string pseudo, const std::string email, const std::string mdp, GestionnaireGroupes* gg);
    ~Utilisateur();

    void setNom(std::string n);
    void setPrenom(std::string p);
    void setPseudo (std::string pseudo);
    void setMdp (std::string mdp);

    GestionnaireGroupes* getGestionnaire();
    std::string getNom();
    std::string getPrenom();
    std::string getPseudo();
    std::string getEmail();
    std::string toString();
};


#endif //SHARECOUNT_UTILISATEUR_HPP
