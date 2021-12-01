#include "GestionnaireGroupes.hpp"
/**
* Gère et donne l'accès aux groupes connus par l'utilisateur local
* @authors Guillaume Vautrin, Louis Jacques
* @version v9 (Dernière modification)  : type modifé
*/
GestionnaireGroupes::GestionnaireGroupes() {
    m_groupes = std::unordered_map<int,Groupe>();
}
/**
* Ajoute un groupe à la collection : l'utilisateur local est ajouté à ce groupe
* @param id identifiant du groupe
* @param nom Nom du groupe
* @param u Utilisateur à ajouter
* * @authors Guillaume Vautrin, Louis Jacques
* @version v9 (Dernière modification)  : ajout identifiant
*/
void GestionnaireGroupes::ajouterGroupe(const int& id, const std::string &nom, const Utilisateur* u) {
    Groupe g = Groupe(id, nom);
    g.setId(id);
    m_groupes[g.getId()] = g;
}
/**
* Récupère le groupe indiqué par l'identifiant
* @param indice string identifiant
* @return référence à Groupe
* @authors Guillaume Vautrin, Louis Jacques
* @version v8 (Dernière modification)  : const ajouté
*/
GestionnaireGroupes& GestionnaireGroupes::getGroupe (const int& idGroupe){
    return reinterpret_cast<GestionnaireGroupes &>(m_groupes.at(idGroupe));
}

/**
 * Récupère l'ensemble des groupes connus
 * @return unordered_map <ID, Groupe>
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v9 (Dernière modification)  : type modifé
 */
std::unordered_map<int, Groupe> * GestionnaireGroupes::getTousLesGroupesConnus() {
    return &m_groupes;
}

/**
 * Détaille tous les groupes dans lequel l'utilisateur est inscrit
 * @return String
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v8 (Dernière modification)  : const ajouté
 */
std::string GestionnaireGroupes::toString() const {
    std::string s = "Gestionnaire groupes : \n";

    for (const std::pair<const int, Groupe>& it : m_groupes){
        s.append(it.second.toString()).append("\n\n");
    }

    return s;
}
/**
 * @brief Ajoute un événement à un groupe précis
 * @param idGroupe Identifiant du groupe, déjà connu par l'utilisateur
 * @param idEvent identifiant du nouvel événement
 * @param nom Nom de l'événement
 * @param dateDeb Date de début
 * @param dateFin Date de fin
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v9 (Dernière modification)  : id event ajouté
*/
void GestionnaireGroupes::ajouterEvenemenent(const int& idGroupe, const int& idEvent, const std::string& nom, const std::string& dateDeb, const std::string &dateFin){
    m_groupes[idGroupe].creerEvenement(idEvent, nom,dateDeb,dateFin);
}
/**
* Ajout d'un membre à un groupe connu
* @param idGroupe string identifiant du groupe
* @param u Utilisateur à ajouter au groupe
* @version v8 (Dernière modification)  : const ajouté
*/
void GestionnaireGroupes::ajoutMembreAGroupe(const int& idGroupe, const Utilisateur *u){
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
 * @version v9 (Dernière modification)  : type modifié
 */
std::vector <int> GestionnaireGroupes::listeIDs() const {
    std::vector <int> ids;
    ids.reserve(m_groupes.size());

    for(const auto& kv : m_groupes) {
        ids.push_back(kv.second.getId());
    }
    return ids;
}

/**
* @brief liste des noms de groupes
* @return Vector
* @authors Guillaume Vautrin, Louis Jacques
* @version v8 (Dernière modification)  : const ajouté
*/
std::vector <std::string> GestionnaireGroupes::listeNoms() const {
    std::vector <std::string> ids;
    ids.reserve(m_groupes.size());

    for(const auto& kv : m_groupes) {
        ids.push_back(kv.second.getNom());
    }
    return ids;
}

