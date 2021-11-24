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
* @version v6 (Dernière modification)
 */
    std::string m_id;
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
     * @param nom Nom du groupe
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    Groupe(std::string nom);

    /**
     * Créer un événement lié à un groupe d'utilisateurs
     * @param nom Nom de l'événement
     * @param dateDeb Date de début de l'évenement
     * @param dateFin Date de fin
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    void creerEvenement(std::string nom,std::string dateDeb,std::string dateFin);

    /**
     * Ajoute un membre à un groupe
     * @param u Utilisateur
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    void ajouterMembre(const Utilisateur* u);

    /**
     * Détails le contenu d'un groupe
     * @return string
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    std::string toString() const;

    /**
     * @return Id d'un groupe
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    std::string getId() const;

    /**
     * @return Nom d'un groupe
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    std::string getNom() const;

    /**
     * Ajoute un identifiant au groupe
     * @param id string
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    void setId(std::string id);
};


#endif //SHARECOUNT_GROUPE_HPP
