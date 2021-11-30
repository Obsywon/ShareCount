#ifndef SHARECOUNT_UTILISATEUR_HPP
#define SHARECOUNT_UTILISATEUR_HPP

#include <cstdlib>
#include <iostream>

class GestionnaireGroupes;

class Utilisateur {
private:

    /**
     * @brief Identifiant de l'utilisateur dans la base de données
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
    * @version v9 (Dernière modification)
     */
    int m_id;
/**
 * @brief Nom de l'utilisateur
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v6 (Dernière modification)
 */
    std::string m_nom;

/**
 * @brief Prénom de l'utilisateur
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v6 (Dernière modification)
*/
    std::string m_prenom;

/**
 * @brief Pseudo de l'utilisateur
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v6 (Dernière modification)
*/
    std::string m_pseudo;

/**
 * @brief Mot de passe de l'utilisateur
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v6 (Dernière modification)
 */
    std::string m_password;

/**
 * @brief Email de l'utilisateur
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v6 (Dernière modification)
 */
    std::string m_email;

/**
 * @brief Collection de groupes
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v6 (Dernière modification)
*/
    GestionnaireGroupes* m_groupes;

public:

    Utilisateur();
    /**
     * Créer un utilisateur
     * @param pseudo Pseudo utilisé sur l'application
     * @param email E-mail utilisé pour s'enregistrer
     * @param mdp Mot de passe permettant la connection
    * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    Utilisateur(const int& id, const std::string& pseudo, const std::string& email, const std::string& mdp, GestionnaireGroupes* gg);
    ~Utilisateur();

    void setId(int& id);


    int getId() const;

    /**
     * Donne un nom à l'utilisateur
     * @param n string nom
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    void setNom(const std::string& n);

    /**
     * Donne un prénom à l'utilisateur
     * @param p string prénom
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    void setPrenom(const std::string& p);

    /**
     * Modifie le pseudo de l'utilisateur
     * @param pseudo String pseudo
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    void setPseudo (const std::string& pseudo);

    /**
     * Modifie le mot de passe de l'utilisateur
     * @param mdp string mot de passe
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    void setMdp (const std::string& mdp);

    /**
     * @return string nom de l'utilisateur
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    std::string getNom();

    /**
     * @return string prénom de l'utilisateur
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    std::string getPrenom();

    /**
     * @return string pseudo de l'utilisateur
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    std::string getPseudo();

    /**
     * @return string email de l'utilisateur
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    std::string getEmail();

    /**
     * Détaille les données de l'utilisateur
     * @return string
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
    std::string toString() const;
};


#endif //SHARECOUNT_UTILISATEUR_HPP
