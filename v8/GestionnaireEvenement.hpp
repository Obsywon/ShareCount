#ifndef SHARECOUNT_GESTIONNAIREEVENEMENT_HPP
#define SHARECOUNT_GESTIONNAIREEVENEMENT_HPP

#include <vector>
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
 * @brief Collection d'événemetns
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v6 (Dernière modification)
 */
    std::vector<Evenement> m_evenement;
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
 * @version v6 (Dernière modification)
 */
    GestionnaireEvenement();

    /**
     * @brief Génère un événement lié à un groupe de clients
     * @param nom nom de l'évenement
     * @param dateDebut Date de début
     * @param dateFin Date de fin
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    void creerEvenement (std::string nom,std::string dateDebut,std::string dateFin) ;

    /**
     * @brief Détaille les événements connus par le gestionnaire
     * @return String
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    std::string toString() const;

    /**
     * @brief Récupère l'evenement indiqué
     * @param indice int
     * @return référence à Evenement
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    GestionnaireEvenement& getEvenement(int indice);
};


#endif //SHARECOUNT_GESTIONNAIREEVENEMENT_HPP

