#include "GestionnaireEvenement.hpp"
/**
 * @brief Gère les événements
 * @version v4
 * @author Louis Jacques
 */
GestionnaireEvenement::GestionnaireEvenement() {
    m_evenement = std::vector<Evenement>();
}
/**
 * @brief Ajoute les événements
 * @param nom string
 * @param dateFin string
 * @param dateDebut string
 * @version v4
 * @author Louis Jacques
 */
void GestionnaireEvenement::creerEvenement(std::string nom, std::string dateDebut, std::string dateFin) {
    Evenement e = Evenement(nom, dateDebut, dateFin);
    m_evenement.push_back(e);
}
/**
 * @brief Récupère les événements
 * @param indice int
 * @return Gestionnaire
 * @version v4
 * @author Louis Jacques
 */
GestionnaireEvenement& GestionnaireEvenement::getEvenement(int indice){
    return reinterpret_cast<GestionnaireEvenement &>(m_evenement.at(indice));
}
/**
 * @brief Détaille les événements connus
 * @return string
 * @version v5
 * @author Louis Jacques
 */
std::string GestionnaireEvenement::toString() const {
    std::string s = "Gestionnaire événements : \n";
    for (Evenement e: m_evenement){
        s += "- ";
        s += e.toString();
        s += "\n";
    }
    return s;
}
