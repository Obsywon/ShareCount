#include "Groupe.hpp"
    /**
     * Groupe regroupant l'ensemble de participants, d'événements et diverses informations les concernant
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
Groupe::Groupe() : m_nom(""){
}
    /**
     * Groupe regroupant l'ensemble de participants, d'événements et diverses informations les concernant
     * @param nom Nom du groupe
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
Groupe::Groupe(const std::string& nom):m_nom(nom) {
    m_id = FabriqueID::getInstance()->getId();
}
    /**
     * Créer un événement lié à un groupe d'utilisateurs
     * @param nom Nom de l'événement
     * @param dateDeb Date de début de l'évenement
     * @param dateFin Date de fin
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
void Groupe::creerEvenement(const std::string& nom, const std::string& dateDeb, const std::string& dateFin){
    ges.creerEvenement(nom,dateDeb,dateFin);
}
    /**
     * Ajoute un membre à un groupe
     * @param u Utilisateur
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
void Groupe::ajouterMembre(const Utilisateur* u){
       gesCom.ajouterCompte(u);
}

    /**
     * Détails le contenu d'un groupe
     * @return string
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
std::string Groupe::toString() const {
    std::string s = "Groupe ";
    s.append(m_nom).append(" : \n");
    s.append(gesCom.toString()).append("\n");
    s.append(ges.toString()).append("\n");
    return s;
}

    /**
     * @return Id d'un groupe
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
std::string Groupe::getId() const {
    return m_id;
}
    /**
     * @return Nom d'un groupe
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
std::string Groupe::getNom() const {
    return m_nom;
}
    /**
     * Ajoute un identifiant au groupe
     * @param id string
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
void Groupe::setId(const std::string& id) {
    m_id = id;
}

