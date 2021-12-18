//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_UTILISATEUR_HPP
#define SHARECOUNT_UTILISATEUR_HPP

#include <cstdlib>
#include <string>
#include <iostream>

/**
 * @brief Génère un utilisateur
 * @version v2
 * @author Guillaume Vautrin
 */
class Utilisateur {
private:
/**
* @brief nom
* @version v1
* @author Guillaume Vautrin
*/
    std::string m_nom;

    /**
* @brief prénom
* @version v1
* @author Guillaume Vautrin
*/
    std::string m_prenom;

    /**
* @brief pseudo
* @version v1
* @author Guillaume Vautrin
*/
    std::string m_pseudo;
    /**
* @brief mot de passe
* @version v1
* @author Guillaume Vautrin
*/
    std::string m_password;

    /**
* @brief email
* @version v1
* @author Guillaume Vautrin
*/
    std::string m_email;

public:
/**
 * @brief Génère un utilisateur
 * @version v1
 * @author Guillaume Vautrin
 */
    Utilisateur();
/**
 * @brief Génère un utilisateur
 * @param email string
 * @param pseudo string
 * @param mdp string
 * @version v1
 * @author Guillaume Vautrin
 */
    Utilisateur(const std::string pseudo, const std::string email, const std::string mdp);
    ~Utilisateur();

/**
 * @brief attribue un nom
 * @param n nom
 * @version v1
 * @author Guillaume Vautrin
 */
    void setNom(std::string n);

/**
* @brief attribue un prénom
* @param p prénom
* @version v1
* @author Guillaume Vautrin
*/
    void setPrenom(std::string p);

/**
* @brief attribue un pseudo
* @param pseudo
* @version v1
* @author Guillaume Vautrin
*/
    void setPseudo (std::string pseudo);

/**
* @brief attribue un mot de passe
* @param mdp
* @version v1
* @author Guillaume Vautrin
*/
    void setMdp (std::string mdp);
/**
 * @brief récupère un nom
 * @return string
 * @version v1
 * @author Guillaume Vautrin
 */
    std::string getNom();

    /**
* @brief attribue un prénom
* @return string
* @version v1
* @author Guillaume Vautrin
*/
    std::string getPrenom();

    /**
* @brief attribue un pseudo
* @return string
* @version v1
* @author Guillaume Vautrin
*/
    std::string getPseudo();
/**
 * @brief décris l'utilisateur
 * @return string
 * @version v1
 * @author Guillaume Vautrin
 */
    std::string toString();

};


#endif //SHARECOUNT_UTILISATEUR_HPP
