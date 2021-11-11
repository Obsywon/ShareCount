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
std::string Groupe::toString() {
    std::string s = m_nom;
    return s;
}
