#ifndef SHARECOUNT_GROUPE_HPP
#define SHARECOUNT_GROUPE_HPP
#include <string>
#include "GestionnaireEvenement.hpp"
#include "GestionnaireComptes.hpp"
#include "FabriqueID.hpp"


class Groupe {
private:
/**
* @brief Identifiant du groupe
* @authors Guillaume Vautrin, Louis Jacques
* @version v9 (Dernière modification)  : changement de type
*/
    int m_id;
    /**
 * @brief Nom du groupe
* @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
 */
    std::string m_nom;
    /**
 * @brief Gestionnaire d'évenements du groupe
* @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
 */
    GestionnaireEvenement ges;
/**
 * @brief Gestionnaire des comptes liées au groupe
* @authors Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
 */
    GestionnaireComptes gesCom;

public:

    Groupe();

    /**
     * Groupe regroupant l'ensemble de participants, d'événements et diverses informations les concernant
     * @param id identifiant
     * @param nom Nom du groupe
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : identifiant ajouté
     */
    explicit Groupe(const int& id, const std::string& nom);

    /**
     * Créer un événement lié à un groupe d'utilisateurs
     * @param nom Nom de l'événement
     * @param id identifiant de l'évenement
     * @param dateDeb Date de début de l'évenement
     * @param dateFin Date de fin
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification)  : const ajouté
     */
void creerEvenement(const int& id, const std::string& nom, const std::string& dateDeb, const std::string& dateFin);

    /**
     * Ajoute un membre à un groupe
     * @param u Utilisateur
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification)  : const ajouté
     */
    void ajouterMembre(const Utilisateur* u);

    /**
     * Détails le contenu d'un groupe
     * @return string
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
    std::string toString() const;

    /**
     * @return Id d'un groupe
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : changement de type
     */
    int getId() const;

    /**
     * @return Nom d'un groupe
     * @authors Guillaume Vautrin, Louis Jacques
   * @version v8 (Dernière modification)  : const ajouté
     */
    std::string getNom() const;

    /**
     * Ajoute un identifiant au groupe
     * @param id
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : changement de type
     */
    void setId(const int& id);

    /**
     * Ajoute un nom au groupe
     * @param id string
     * @authors Guillaume Vautrin
     * @version v12 (Dernière modification)
     */
    void setNom(const std::string& nom);


    /**
     * @brief Récupère l'ensemble des evenements connus
     * @return unordered_map <ID, Evenement>
     * @authors Louis Jacques
     * @version v9 (Dernière modification)
     */
    std::unordered_map<int, Evenement> * getTousLesEvenementsConnus();

    /**
     * @brief Récupère l'ensemble des evenements connus
     * @return unordered_map <ID, Evenement>
     * @authors Louis Jacques
     * @version v9 (Dernière modification)
     */
    std::vector<Utilisateur> * getTousLesParticipantsConnus();

    /**
    * @brief Charge les événements disponibles
    * @param events
    * @authors Guillaume Vautrin
    * @version v14 (Dernière modification)
     */
    void chargeEvents(const std::unordered_map <int, std::vector<std::string>>& events);

    /**
    * @brief Charge les caractéristiques de bases des participants connus pas un groupe
    * @param hashmap issue de la base de donnée
    * @authors Guillaume Vautrin
    * @version v15 (Dernière modification)
    */
    void chargeMembers (const std::unordered_map <int, std::string>& membres);
};


#endif //SHARECOUNT_GROUPE_HPP
