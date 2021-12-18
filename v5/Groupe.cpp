#include "Groupe.hpp"
/**
* @brief Groupe
* @author Guillaume Vautrin
* @version v3
*/
Groupe::Groupe() : m_nom(""){
}
/**
* @brief Groupe
* @param nom
* @author Guillaume Vautrin
* @version v3
*/
Groupe::Groupe(std::string nom):m_nom(nom) {
}
/**
* @brief Créer un événement
* @param string nom
* @param dateFin date de fin
* @param dateDeb date de début
* @author Guillaume Vautrin
* @version v5
*/
void Groupe::creerEvenement(std::string nom, std::string dateDeb, std::string dateFin){
    ges.creerEvenement(nom,dateDeb,dateFin);
}

/**
* @brief décris un groupe
* @param string
* @author Guillaume Vautrin
* @version v5
*/
void Groupe::ajouterMembre(const Utilisateur* u){
       gesCom.ajouterCompte(u);
}

/**
* @brief décris un groupe
* @return string
* @author Guillaume Vautrin
* @version v5
*/
std::string Groupe::toString() const {
    std::string s = "Groupe ";
    s.append(m_nom).append(" : \n");
    s.append(gesCom.toString()).append("\n");
    s.append(ges.toString()).append("\n");
    return s;
}
