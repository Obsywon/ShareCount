#include "GestionnaireEvenement.hpp"
/**
 * @brief Constructeur de gestionnaire d'événements connus par un groupe
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v6 (Dernière modification)
 */
GestionnaireEvenement::GestionnaireEvenement() {
    m_evenement = std::unordered_map <int, Evenement>();
}
    /**
     * @brief Génère un événement lié à un groupe de clients
     * @param id identifiant
     * @param nom nom de l'évenement
     * @param dateDebut Date de début
     * @param dateFin Date de fin
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : ajout identifiant
     */
void GestionnaireEvenement::creerEvenement(const int& id, const std::string& nom, const std::string& dateDebut, const std::string &dateFin) {
    Evenement e = Evenement(id, nom, dateDebut, dateFin);
    m_evenement[id] = e;
}
/**
* @brief Détaille les événements connus par le gestionnaire
* @return Evenement
* @authors Guillaume Vautrin, Louis Jacques
* @version v9 (Dernière modification)  : Récupère événement
*/
Evenement GestionnaireEvenement::getEvenement(const int& indice){
    return m_evenement[indice];
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
    for (auto const& key : m_evenement){
        s+= "- ";
        s+= key.second.toString();
        s+= "\n";
    }
    return s;
}
