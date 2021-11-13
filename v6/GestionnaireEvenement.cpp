#include "GestionnaireEvenement.hpp"

GestionnaireEvenement::GestionnaireEvenement() {
    m_evenement = std::vector<Evenement>();
}

void GestionnaireEvenement::creerEvenement(std::string nom, std::string dateDebut, std::string dateFin) {
    Evenement e = Evenement(nom, dateDebut, dateFin);
    m_evenement.push_back(e);
}

GestionnaireEvenement& GestionnaireEvenement::getEvenement(int indice){
    return reinterpret_cast<GestionnaireEvenement &>(m_evenement.at(indice));
}

std::string GestionnaireEvenement::toString() const {
    std::string s = "Gestionnaire événements : \n";
    for (Evenement e: m_evenement){
        s += "- ";
        s += e.toString();
        s += "\n";
    }
    return s;
}
