#include "GestionnaireEvenement.hpp"
/**
 * @brief Constructeur de gestionnaire d'événements connus par un groupe
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v6 (Dernière modification)
 */
GestionnaireEvenement::GestionnaireEvenement() {
    m_evenement = std::vector<Evenement>();
}
    /**
     * @brief Génère un événement lié à un groupe de clients
     * @param nom nom de l'évenement
     * @param dateDebut Date de début
     * @param dateFin Date de fin
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
     */
void GestionnaireEvenement::creerEvenement(const std::string& nom, const std::string& dateDebut, const std::string &dateFin) {
    Evenement e = Evenement(nom, dateDebut, dateFin);
    m_evenement.push_back(e);
}
    /**
     * @brief Détaille les événements connus par le gestionnaire
     * @return String
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
     */
GestionnaireEvenement& GestionnaireEvenement::getEvenement(const int& indice){
    return reinterpret_cast<GestionnaireEvenement &>(m_evenement.at(indice));
}
    /**
     * @brief Récupère l'evenement indiqué
     * @param indice int
     * @return référence à Evenement
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
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
