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

    /**
     * Donne un nom à l'utilisateur
     * @param n string nom
     */
    void setNom(std::string n);

    /**
     * Donne un prénom à l'utilisateur
     * @param p string prénom
     */
    void setPrenom(std::string p);

    /**
     * Modifie le pseudo de l'utilisateur
     * @param pseudo String pseudo
     */
    void setPseudo (std::string pseudo);

    /**
     * Modifie le mot de passe de l'utilisateur
     * @param mdp string mot de passe
     */
    void setMdp (std::string mdp);

    /**
     * @return string nom de l'utilisateur
     */
    std::string getNom();

    /**
     * @return string prénom de l'utilisateur
     */
    std::string getPrenom();

    /**
     * @return string pseudo de l'utilisateur
     */
    std::string getPseudo();

    /**
     * @return string email de l'utilisateur
     */
    std::string getEmail();

    /**
     * Détaille les données de l'utilisateur
     * @return string
     */
    std::string toString();
};


#endif //SHARECOUNT_UTILISATEUR_HPP
