#include "Evenement.hpp"

/**
 * @brief Constructeur par défault : événement vide 
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v4 (Dernière modification)
 */
Evenement::Evenement() = default;

/**
 * @brief Construit un événement 
 * 
 * @param nom Nom de l'événement
 * @param dateDeb Date de début de l'événeement (par défaut, aujourd'hui)
 * @param dateFin Date prévue de fin de l'événement
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v4 (Dernière modification)
 */
Evenement::Evenement(std::string nom, std::string dateDeb, std::string dateFin): m_nom(std::move(nom)), m_dateDeb(std::move(dateDeb)), m_dateFin(std::move(dateFin)) {

}

/**
 * @brief Retourne des informations sur l'événement
 * @return std::string 
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v4 (Dernière modification)
 */
std::string Evenement::toString() {
    std::string temp = m_nom;
    temp.append(" ").append(m_dateDeb).append(" - ").append(m_dateFin);
    return temp;
}


