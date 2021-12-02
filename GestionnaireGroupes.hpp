#ifndef SHARECOUNT_GESTIONNAIREGROUPES_HPP
#define SHARECOUNT_GESTIONNAIREGROUPES_HPP

#include <unordered_map>
#include <vector>
#include "Groupe.hpp"
#include "Database.hpp"

/**
 * @brief Gestionnaire de groupe
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v9 (Dernière modification)  : type modifé
 */
class GestionnaireGroupes {
private:
/**
 * @brief Collection (hashmap) de groupes identifié par un identifiant
* @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
 */
    std::unordered_map<int, Groupe> m_groupes;

public:
    /**
     * Gère et donne l'accès aux groupes connus par l'utilisateur local
    * @authors Guillaume Vautrin, Louis Jacques
    * @version v6 (Dernière modification)
     */
    GestionnaireGroupes();

    /**
    * Ajoute un groupe à la collection : l'utilisateur local est ajouté à ce groupe
    * @param id identifiant du groupe
    * @param nom Nom du groupe
    * @authors Guillaume Vautrin, Louis Jacques
    * @version v9 (Dernière modification)  : ajout identifiant
    */
    void ajouterGroupe(const int& id, const std::string &nom);

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
    void ajouterEvenemenent(const int& idGroupe, const int& idEvent, const std::string& nom, const std::string& dateDeb, const std::string &dateFin);

    /**
     * Ajout d'un membre à un groupe connu
     * @param idGroupe string identifiant du groupe
     * @param u Utilisateur à ajouter au groupe
     * @version v9 (Dernière modification)  : type modifé
     */
    void ajoutMembreAGroupe(const int& idGroupe, const Utilisateur *u);

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
     * @version v8 (Dernière modification)  : const ajouté
     */
    std::string toString() const;


    /**
     * Récupère le groupe indiqué par l'identifiant
     * @param indice string identifiant
     * @return référence à Groupe
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : type modifé
     */
    GestionnaireGroupes &getGroupe(const int& idGroupe);

    /**
     * @brief liste IDs
     * @return Vector
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : type modifié
     */
    std::vector<int> listeIDs() const;

    /**
     * @brief liste des noms de groupes
     * @return Vector
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
     */
    std::vector<std::string> listeNoms() const;

    /**
     * Récupère l'ensemble des groupes connus
     * @return unordered_map <ID, Groupe>
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : type modifé
     */
    std::unordered_map<int, Groupe> * getTousLesGroupesConnus();

    /**
     * Récupère l'ensemble des groupes connus
     * @return unordered_map <ID, Groupe>
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : type modifé
     */
    std::unordered_map<int, Evenement> * getTousLesEvenementsConnus(const int& identifiant);

    /**
    * Récupère le groupe indiqué par l'identifiant
    * @param db base de données
    * @param id utilisateur
    * @authors Guillaume Vautrin
    * @version v12 (Dernière modification)
    */
    void loadGroupes (const int& id);

};

#endif //SHARECOUNT_GESTIONNAIREGROUPES_HPP
