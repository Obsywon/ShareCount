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
 * @param id Identifiant de l'événement
 * @param dateDeb Date de début de l'événeement (par défaut, aujourd'hui)
 * @param dateFin Date prévue de fin de l'événement
 * @authors Guillaume Vautrin, Louis Jacques
* @version v9 (Dernière modification)  : ajout identifiant
 */
Evenement::Evenement(const int& id, const std::string &nom, const std::string &dateDeb, const std::string& dateFin):
    m_id(id), m_nom(nom), m_dateDeb(dateDeb), m_dateFin(dateFin) {

}

/**
 * @brief Retourne des informations sur l'événement
 * @return std::string 
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v8 (Dernière modification) : const ajouté
 */
std::string Evenement::toString() const {
    std::string temp = m_nom;
    temp.append(" ").append(m_dateDeb).append(" - ").append(m_dateFin);
    return temp;
}

/**
 * @brief Récupère l'id de l'événement
 * @param nom Nom de l'événement
 * @authors Guillaume Vautrin
* @version v9 (Dernière modification)  : ajout identifiant
 */
int Evenement::getId() const{
    return m_id;
}


/**
 * @brief Récupère le nom de l'événement
 * @authors Guillaume Vautrin
 * @return nom
 * @version v9 (Dernière modification)  : ajout identifiant
 */
std::string Evenement::getNom() const{
    return m_nom;
}


