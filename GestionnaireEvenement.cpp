//
// Created by guy on 11/11/2021.
//

#include "GestionnaireEvenement.hpp"

GestionnaireEvenement::GestionnaireEvenement() {
    m_evenement = std::vector<Evenement>(20);
}

void GestionnaireEvenement::creerEvenement(std::string nom, std::string dateDebut, std::string dateFin) {
    Evenement e = Evenement(nom, dateDebut, dateFin);
    m_evenement.push_back(e);
}

GestionnaireEvenement& GestionnaireEvenement::getEvenement(int indice){
    return reinterpret_cast<GestionnaireEvenement &>(m_evenement.at(indice));
}

std::string GestionnaireEvenement::toString() {
    std::string s = "";
    for (Evenement e: m_evenement){
        s += e.toString();
    }
    return s;
}
