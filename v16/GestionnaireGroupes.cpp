#include "GestionnaireGroupes.hpp"
#include <QtDebug>
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
* @authors Guillaume Vautrin, Louis Jacques
* @version v9 (Dernière modification)  : ajout identifiant
*/
void GestionnaireGroupes::ajouterGroupe(const int& id, const std::string &nom) {
    Groupe g = Groupe(id, nom);
    m_groupes[g.getId()] = g;
}
/**
* Récupère le groupe indiqué par l'identifiant
* @param indice string identifiant
* @return référence à Groupe
* @authors Guillaume Vautrin, Louis Jacques
* @version v8 (Dernière modification)  : const ajouté
*/
Groupe GestionnaireGroupes::getGroupe (const int& idGroupe){
    return m_groupes.at(idGroupe);
}

/**
 * Récupère l'ensemble des groupes connus
 * @return unordered_map <ID, Groupe>
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v9 (Dernière modification)  : type modifé
 */
std::unordered_map<int, Groupe> * GestionnaireGroupes::getTousLesGroupesConnus(){
    return &m_groupes;
}

/**
 * Récupère l'ensemble des groupes connus
 * @return unordered_map <ID, Groupe>
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v9 (Dernière modification)  : type modifé
 */
std::vector<Utilisateur> * GestionnaireGroupes::getTousLesParticipantsConnus(const int& identifiant){
    return m_groupes[identifiant].getTousLesParticipantsConnus();
}

/**
 * Récupère l'ensemble des groupes connus
 * @return unordered_map <ID, Groupe>
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v9 (Dernière modification)  : type modifé
 */
std::unordered_map<int, Evenement> * GestionnaireGroupes::getTousLesEvenementsConnus(const int& identifiant){
    return m_groupes[identifiant].getTousLesEvenementsConnus();
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
void GestionnaireGroupes::ajouterEvenemenent(const int& idGroupe, const int& idEvent, const std::string& nom,
                                             const std::string& dateDeb, const std::string &dateFin){
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
* @brief Charge les caractéristiques de bases des groupes connus pas l'utilisateur
* @param groupes
* @authors Guillaume Vautrin
* @version v14 (Dernière modification) : évite de recréer un objet
*/
void GestionnaireGroupes::chargeGroupes (const std::unordered_map <int, std::string>& groupes){
    for(auto const& key : groupes){
        if (m_groupes.count(key.first) > 0){
            m_groupes[key.first].setNom(key.second);
        }else{
            m_groupes[key.first] = Groupe(key.first, key.second);
        }
    }
}

/**
* @brief Charge les caractéristiques de bases des événements connus pas un groupe
* @param id groupe
* @param collections d'information sur les événements
* @authors Guillaume Vautrin
* @version v14 (Dernière modification)
*/
void GestionnaireGroupes::chargeEvents(const int& group_id, const std::unordered_map <int, std::vector<std::string>>& events){
    m_groupes[group_id].chargeEvents(events);
}

/**
* @brief Charge les caractéristiques de bases des participants connus pas un groupe
* @param id groupe
* @param collections d'information sur les participants d'un groupe
* @authors Guillaume Vautrin
* @version v15 (Dernière modification)
*/
void GestionnaireGroupes::chargeParticipants(const int& group_id, const std::unordered_map <int, std::string>& membres){
    m_groupes[group_id].chargeMembers(membres);
}

