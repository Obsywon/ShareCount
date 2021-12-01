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
     * @param id string
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : changement de type
     */
    void setId(const int& id);
};


#endif //SHARECOUNT_GROUPE_HPP
