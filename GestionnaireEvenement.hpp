#ifndef SHARECOUNT_GESTIONNAIREEVENEMENT_HPP
#define SHARECOUNT_GESTIONNAIREEVENEMENT_HPP

#include <unordered_map>
#include "Evenement.hpp"

class Utilisateur;

/**
 * @brief Appartient à un groupe: permet de renseigner
 * sur tous les événements connus par ce groupe
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v6 (Dernière modification)
 */
class GestionnaireEvenement {
private:
/**
 * @brief Collection d'événements identifiés
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v9 (Dernière modification)
 */
    std::unordered_map<int, Evenement> m_evenement;
/**
 * @brief Utilisateur 
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v6 (Dernière modification) 
 */
    Utilisateur* user;

public:
/**
 * @brief Constructeur de gestionnaire d'événements connus par un groupe
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v9 (Dernière modification) génère une map
 */
    GestionnaireEvenement();

    /**
     * @brief Génère un événement lié à un groupe de clients
     * @param id identifiant
     * @param nom nom de l'évenement
     * @param dateDebut Date de début
     * @param dateFin Date de fin
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : ajout identifiant
     */
    void creerEvenement(const int& id, const std::string& nom, const std::string& dateDebut, const std::string &dateFin);

    /**
     * @brief Détaille les événements connus par le gestionnaire
     * @return String
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
     */
    std::string toString() const;

    /**
    * @brief Détaille les événements connus par le gestionnaire
    * @param id
    * @return Evenement
    * @authors Guillaume Vautrin, Louis Jacques
    * @version v9 (Dernière modification)  : Récupère événement
    */
    Evenement getEvenement(const int& indice);
};


#endif //SHARECOUNT_GESTIONNAIREEVENEMENT_HPP

