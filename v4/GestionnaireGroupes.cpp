#include "GestionnaireGroupes.hpp"
/**
 * @brief Gère les groupes
 * @version v3
 * @author Guillaume Vautrin
 */
GestionnaireGroupes::GestionnaireGroupes() {
    m_groupes = std::vector<Groupe>(20);
}
/**
 * @brief ajoute un groupe
 * @version v3
 * @author Guillaume Vautrin
 */
void GestionnaireGroupes::ajouterGroupe(std::string nom, const Utilisateur* u) {
    Groupe g = Groupe(nom);
    m_groupes.push_back(g);
}
/**
 * @brief description des groupes connus
 * @param indice int
 * @return Groupe
 * @version v4
 * @author Guillaume Vautrin
 */
GestionnaireGroupes& GestionnaireGroupes::getGroupe (int indice){
    return reinterpret_cast<GestionnaireGroupes &>(m_groupes.at(indice));
}
/**
 * @brief description des groupes connus
 * @return string
 * @version v3
 * @author Guillaume Vautrin
 */
std::string GestionnaireGroupes::toString() {
    std::string s = "";
    for (Groupe g: m_groupes){
        s += g.toString();
    }
    return s;
}
