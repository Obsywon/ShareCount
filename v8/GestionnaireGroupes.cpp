#include "GestionnaireGroupes.hpp"
    /**
     * Gère et donne l'accès aux groupes connus par l'utilisateur local
    * @authors Guillaume Vautrin, Louis Jacques
    * @version v6 (Dernière modification)
     */
GestionnaireGroupes::GestionnaireGroupes() {
    m_groupes = std::unordered_map<std::string,Groupe>();
}
    /**
     * Ajoute un groupe à la collection : l'utilisateur local est ajouté à ce groupe
     * @param nom Nom du groupe
     * @param u Utilisateur à ajouter
     * * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
void GestionnaireGroupes::ajouterGroupe(std::string nom, const Utilisateur* u) {
    Groupe g = Groupe(nom);
    m_groupes[g.getId()] = g;
}
    /**
     * Récupère le groupe indiqué par l'identifiant
     * @param indice string identifiant
     * @return référence à Groupe
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
GestionnaireGroupes& GestionnaireGroupes::getGroupe (std::string idGroupe){
    return reinterpret_cast<GestionnaireGroupes &>(m_groupes.at(idGroupe));
}

/**
 * Récupère l'ensemble des groupes connus
 * @return unordered_map <ID, Groupe>
 * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
*/
std::unordered_map <std::string, Groupe>* GestionnaireGroupes::getTousLesGroupesConnus(){
    return &m_groupes;
}
    /**
     * Détaille tous les groupes dans lequel l'utilisateur est inscrit
     * @return String
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
std::string GestionnaireGroupes::toString() {
    std::string s = "Gestionnaire groupes : \n";

    for (const std::pair<const std::string, Groupe>& it : m_groupes){
        s.append(it.second.toString()).append("\n\n");
    }

    return s;
}
/**
 * @brief Ajoute un événement à un groupe précis
 * @param idGroupe Identifiant du groupe, déjà connu par l'utilisateur
 * @param nom Nom de l'événement
 * @param dateDeb Date de début
 * @param dateFin Date de fin
* @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
*/
void GestionnaireGroupes::ajouterEvenemenent(std::string idGroupe, std::string nom, std::string dateDeb, std::string dateFin){
    m_groupes[idGroupe].creerEvenement(nom,dateDeb,dateFin);
}
    /**
     * Ajout d'un membre à un groupe connu
     * @param idGroupe string identifiant du groupe
     * @param u Utilisateur à ajouter au groupe
     */
void GestionnaireGroupes::ajoutMembreAGroupe(std::string idGroupe, const Utilisateur *u){
        m_groupes.at(idGroupe).ajouterMembre(u);
}
    /**
     * Nombre de groupes auxquel l'utilisateur appartient
     * @return unsigned long
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
unsigned long GestionnaireGroupes::taille() {
    return m_groupes.size();
}

    /**
     * @brief liste IDs
     * @return Vector
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
std::vector <std::string> GestionnaireGroupes::listeIDs(){
    std::vector <std::string> ids;
    ids.reserve(m_groupes.size());

    for(auto kv : m_groupes) {
        ids.push_back(kv.second.getId());
    }
    return ids;
}

    /**
     * @brief liste des noms de groupes
     * @return Vector
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
std::vector <std::string> GestionnaireGroupes::listeNoms(){
    std::vector <std::string> ids;
    ids.reserve(m_groupes.size());

    for(auto kv : m_groupes) {
        ids.push_back(kv.second.getNom());
    }
    return ids;
}

