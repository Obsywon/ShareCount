//
// Created by guy on 09/11/2021.
//

#include "GestionnaireGroupes.hpp"

GestionnaireGroupes::GestionnaireGroupes() {
    m_groupes = std::vector<Groupe>(20);
}

void GestionnaireGroupes::ajouterGroupe(std::string nom, const Utilisateur* u) {
    Groupe g = Groupe(nom);
    m_groupes.push_back(g);
}

GestionnaireGroupes& GestionnaireGroupes::getGroupe (int indice){
    return reinterpret_cast<GestionnaireGroupes &>(m_groupes.at(indice));
}

std::string GestionnaireGroupes::toString() {
    std::string s = "";
    for (Groupe g: m_groupes){
        s += g.toString();
    }
    return s;
}
