#include "Groupe.hpp"

/**
* @brief Groupe
* @author Guillaume Vautrin
* @version v3
*/
Groupe::Groupe() : m_nom(""){
}

/**
* @brief Groupe
 * @param nom
* @author Guillaume Vautrin
* @version v3
*/
Groupe::Groupe(std::string nom):m_nom(nom) {
}

/**
* @brief décris un groupe
 * @return string
* @author Guillaume Vautrin
* @version v3
*/
std::string Groupe::toString() {
    std::string s = m_nom;
    return s;
}
