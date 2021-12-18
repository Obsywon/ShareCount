#include "Evenement.hpp"

/**
 * @brief Génère un événement
 * @version v4
 * @author Guillaume Vautrin
 */
Evenement::Evenement() = default;

/**
 * @brief Génère un événement
 * @param dateFin date de fin
 * @param dateDeb date de début
 * @param nom nom de l'événement
 * @version v4
 * @author Guillaume Vautrin
 */
Evenement::Evenement(std::string nom, std::string dateDeb, std::string dateFin): m_nom(std::move(nom)), m_dateDeb(std::move(dateDeb)), m_dateFin(std::move(dateFin)) {

}

/**
 * @brief Génère une description d'un événément
 * @return string
 * @version v4
 * @author Guillaume Vautrin
 */
std::string Evenement::toString() {
    std::string temp = m_nom;
    temp.append(" ").append(m_dateDeb).append(m_dateFin);
    return temp;
}


