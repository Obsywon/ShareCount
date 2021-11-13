#include "Groupe.hpp"

Groupe::Groupe() : m_nom(""){
}

Groupe::Groupe(std::string nom):m_nom(nom) {
}

void Groupe::creerEvenement(std::string nom, std::string dateDeb, std::string dateFin){
    ges.creerEvenement(nom,dateDeb,dateFin);
}

void Groupe::ajouterMembre(const Utilisateur* u){
       gesCom.ajouterCompte(u);
}


std::string Groupe::toString() const {
    std::string s = "Groupe ";
    s.append(m_nom).append(" : \n");
    s.append(gesCom.toString()).append("\n");
    s.append(ges.toString()).append("\n");
    return s;
}


std::string Groupe::getId() const {
    return m_id;
}

void Groupe::setId(std::string id) {
    m_id = id;
}

