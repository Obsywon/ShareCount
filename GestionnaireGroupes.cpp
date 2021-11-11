//
// Created by guy on 09/11/2021.
//

#include "GestionnaireGroupes.hpp"

GestionnaireGroupes::GestionnaireGroupes() {
    m_groupes = std::unordered_map<std::string,Groupe>(20);
}

void GestionnaireGroupes::ajouterGroupe(std::string nom, const Utilisateur* u) {
    Groupe g = Groupe(nom);
    m_groupes[nom] = g;
}

GestionnaireGroupes& GestionnaireGroupes::getGroupe (std::string idGroupe){
    return reinterpret_cast<GestionnaireGroupes &>(m_groupes.at(idGroupe));
}

std::string GestionnaireGroupes::toString() {
    std::string s = "";
    std::unordered_map<std::string,Groupe>::iterator it = m_groupes.begin();
    while (it != m_groupes.end()){
       s.append(it->second.toString());
    }
    return s;
}

void GestionnaireGroupes::ajouterEvenemenent(std::string idGroupe, std::string nom, std::string dateDeb, std::string dateFin){
    m_groupes.at(idGroupe).creerEvenement(nom,dateDeb,dateFin);
}

void GestionnaireGroupes::ajoutMembreAGroupe(std::string idGroupe, const Utilisateur *u){
        m_groupes.at(idGroupe).ajouterMembre(u);
}
