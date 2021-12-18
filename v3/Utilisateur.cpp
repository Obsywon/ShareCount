//
// Created by guy on 09/11/2021.
//

#include "Utilisateur.hpp"
/**
 * @brief Génère un utilisateur
 * @version v3
 * @author Guillaume Vautrin
 */
Utilisateur::Utilisateur() : m_nom(""), m_prenom(""), m_email(""), m_pseudo(""), m_password(""){
    m_groupes = GestionnaireGroupes();

}

/**
 * @brief Génère un utilisateur
 * @param email string
 * @param pseudo string
 * @param mdp string
 * @version v3
 * @author Guillaume Vautrin
 */
Utilisateur::Utilisateur(const std::string pseudo, const std::string email, const std::string mdp):
m_pseudo(pseudo), m_email(email), m_password(mdp){
    m_groupes = GestionnaireGroupes();
}

Utilisateur::~Utilisateur(){
    //std::cout << "Utilisateur détruit \n";
}
/**
 * @brief attribue un nom
 * @param n nom
 * @version v1
 * @author Guillaume Vautrin
 */
void Utilisateur::setNom(const std::string n){
    m_nom = n;
}
/**
 * @brief attribue un prénom
 * @return string
 * @version v1
 * @author Guillaume Vautrin
 */
void Utilisateur::setPrenom(const std::string p){
    m_prenom = p;
}
/**
 * @brief récupère un nom
 * @return string
 * @version v1
 * @author Guillaume Vautrin
 */
std::string Utilisateur::getNom(){
    return m_nom;
}
/**
 * @brief récupère un prénom
 * @return string
 * @version v1
 * @author Guillaume Vautrin
 */
std::string Utilisateur::getPrenom(){
    return m_prenom;
}
/**
 * @brief attribue un pseudo
 * @param pseudo
 * @version v1
 * @author Guillaume Vautrin
 */
void Utilisateur::setPseudo(std::string pseudo) {
    m_pseudo = pseudo;
}
/**
 * @brief attribue un mot de passe
 * @param mdp
 * @version v1
 * @author Guillaume Vautrin
 */
void Utilisateur::setMdp(std::string mdp) {
    m_password = mdp;
}
/**
* @brief attribue un pseudo
* @return string
* @version v1
* @author Guillaume Vautrin
*/
std::string Utilisateur::getPseudo() {
    return std::string();
}
/**
 * @brief décris l'utilisateur
 * @return string
 * @version v1
 * @author Guillaume Vautrin
 */
std::string Utilisateur::toString(){
    std::string temp = m_pseudo;
    temp.append(" ");
    temp.append(m_prenom).append(" ").append(m_nom).append(" ").append("\n");
    temp.append("mail: ").append(m_email);
    return temp;
}
/**
* @brief récupère le gestionnaire de groupe lié à l'utilisateur
* @return Gestionnaire de groupes
* @version v3
* @author Guillaume Vautrin
*/
GestionnaireGroupes* Utilisateur::getGestionnaire() {
    GestionnaireGroupes* ptr = &m_groupes;
    return ptr;
}








