#include "Utilisateur.hpp"

Utilisateur::Utilisateur() : m_id(), m_nom(""), m_prenom(""), m_pseudo(""), m_password(""), m_email(""), m_groupes(nullptr){
}

    /**
     * Créer un utilisateur
     * @param pseudo Pseudo utilisé sur l'application
     * @param email E-mail utilisé pour s'enregistrer
     * @param mdp Mot de passe permettant la connection
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v9 (Dernière modification): ajout ID
     */
Utilisateur::Utilisateur(const int& id, const std::string& pseudo, const std::string& email, const std::string& mdp, GestionnaireGroupes* gg):
m_id(id), m_pseudo(pseudo), m_password(mdp), m_email(email), m_groupes(gg){
}

Utilisateur::~Utilisateur(){
    //std::cout << "Utilisateur détruit \n";
}

void Utilisateur::setId(int& id){
    m_id = id;
}


int Utilisateur::getId() const{
    return m_id;
}


    /**
     * Donne un nom à l'utilisateur
     * @param n string nom
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
void Utilisateur::setNom(const std::string& n){
    m_nom = n;
}

    /**
     * Donne un prénom à l'utilisateur
     * @param p string prénom
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
void Utilisateur::setPrenom(const std::string& p){
    m_prenom = p;
}

    /**
     * @return string nom de l'utilisateur
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
std::string Utilisateur::getNom(){
    return m_nom;
}

    /**
     * @return string prénom de l'utilisateur
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
std::string Utilisateur::getPrenom(){
    return m_prenom;
}

/**
 * @return string email de l'utilisateur
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
 * @version v6 (Dernière modification)
 */
std::string Utilisateur::getEmail(){
    return m_email;
}

    /**
     * Modifie le pseudo de l'utilisateur
     * @param pseudo String pseudo
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
void Utilisateur::setPseudo(const std::string& pseudo) {
    m_pseudo = pseudo;
}

    /**
     * Modifie le mot de passe de l'utilisateur
     * @param mdp string mot de passe
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
void Utilisateur::setMdp(const std::string& mdp) {
    m_password = mdp;
}

    /**
     * @return string pseudo de l'utilisateur
     * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v6 (Dernière modification)
     */
std::string Utilisateur::getPseudo() {
    return m_pseudo;
}

/**
 * Détaille les données de l'utilisateur
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
 * @version v6 (Dernière modification)
 */
std::string Utilisateur::toString() const {
    std::string temp = m_pseudo;
    temp.append(" ");
    temp.append(m_prenom).append(" ").append(m_nom).append(" ").append("\n");
    temp.append("mail: ").append(m_email);
    return temp;
}









