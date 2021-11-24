#ifndef SHARECOUNT_GESTIONNAIREGROUPES_HPP
#define SHARECOUNT_GESTIONNAIREGROUPES_HPP

#include <unordered_map>
#include <vector>
#include "Groupe.hpp"

/**
 * @brief Gestionnaire de groupe
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v6 (Dernière modification)
 */
class GestionnaireGroupes {
private:
/**
 * @brief Collection (hashmap) de groupes identifié par un identifiant
* @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
 */
    std::unordered_map<std::string, Groupe> m_groupes;

public:
    /**
     * Gère et donne l'accès aux groupes connus par l'utilisateur local
    * @authors Guillaume Vautrin, Louis Jacques
    * @version v6 (Dernière modification)
     */
    GestionnaireGroupes();

    /**
     * Ajoute un groupe à la collection : l'utilisateur local est ajouté à ce groupe
     * @param nom Nom du groupe
     * @param u Utilisateur à ajouter
     * * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
    void ajouterGroupe(std::string nom, const Utilisateur *u);

/**
 * @brief Ajoute un événement à un groupe précis
 * @param idGroupe Identifiant du groupe, déjà connu par l'utilisateur
 * @param nom Nom de l'événement
 * @param dateDeb Date de début
 * @param dateFin Date de fin
* @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
*/
    void ajouterEvenemenent(std::string idGroupe, std::string nom, std::string dateDeb, std::string dateFin);

    /**
     * Ajout d'un membre à un groupe connu
     * @param idGroupe string identifiant du groupe
     * @param u Utilisateur à ajouter au groupe
     */
    void ajoutMembreAGroupe(std::string idGroupe, const Utilisateur *u);

    /**
     * Nombre de groupes auxquel l'utilisateur appartient
     * @return unsigned long
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
    unsigned long taille();

    /**
     * Détaille tous les groupes dans lequel l'utilisateur est inscrit
     * @return String
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
    std::string toString();


    /**
     * Récupère le groupe indiqué par l'identifiant
     * @param indice string identifiant
     * @return référence à Groupe
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
    GestionnaireGroupes &getGroupe(std::string idGroupe);

    /**
     * @brief liste IDs
     * @return Vector
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
    std::vector<std::string> listeIDs();

    /**
     * @brief liste des noms de groupes
     * @return Vector
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
    std::vector<std::string> listeNoms();

    /**
     * Récupère l'ensemble des groupes connus
     * @return unordered_map <ID, Groupe>
     * @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
     */
    std::unordered_map<std::string, Groupe> *getTousLesGroupesConnus();

};

#endif //SHARECOUNT_GESTIONNAIREGROUPES_HPP
