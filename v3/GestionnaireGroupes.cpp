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

std::string GestionnaireGroupes::toString() {
    std::string s = "Gestionnaire groupes : \n";
    for (Groupe g: m_groupes){
        s += g.toString();
    }
    return s;
}
