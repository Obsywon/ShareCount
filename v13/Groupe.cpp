#include "Groupe.hpp"
    /**
     * Groupe regroupant l'ensemble de participants, d'événements et diverses informations les concernant
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
Groupe::Groupe() : m_id(0), m_nom(""){
}
    /**
     * Groupe regroupant l'ensemble de participants, d'événements et diverses informations les concernant
     * @param id identifiant du groupe
     * @param nom Nom du groupe
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : identifiant ajouté
     */
Groupe::Groupe(const int& id, const std::string& nom):m_id(id), m_nom(nom) {
}
    /**
     * Créer un événement lié à un groupe d'utilisateurs
     * @param nom Nom de l'événement
     * @param id identifiant de l'évenement
     * @param dateDeb Date de début de l'évenement
     * @param dateFin Date de fin
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
void Groupe::creerEvenement(const int& id, const std::string& nom, const std::string& dateDeb, const std::string& dateFin){
    ges.creerEvenement(id, nom,dateDeb,dateFin);
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
     * @version v9 (Dernière modification)  : changement de type
     */
int Groupe::getId() const {
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
     * @param id
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : changement de type
     */
void Groupe::setId(const int& id) {
    m_id = id;
}

/**
 * Ajoute un nom au groupe
 * @param id string
 * @authors Guillaume Vautrin
 * @version v12 (Dernière modification)
 */
void Groupe::setNom(const std::string& nom){
    m_nom = nom;
}

/**
 * @brief Récupère l'ensemble des evenements connus
 * @return unordered_map <ID, Evenement>
 * @authors Louis Jacques
 * @version v9 (Dernière modification)
 */
std::unordered_map<int, Evenement> * Groupe::getTousLesEvenementsConnus() {
    return ges.getTousLesEvenementsConnus();
}

/**
 * @brief Récupère l'ensemble des participants connus
 * @return unordered_map <ID, Evenement>
 * @authors Louis Jacques
 * @version v9 (Dernière modification)
 */
std::vector<Utilisateur> * Groupe::getTousLesParticipantsConnus() {
    return gesCom.getTousLesParticipantsConnus();
}


