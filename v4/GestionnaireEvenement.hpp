//
// Created by Louis on 11/11/2021.
//

#ifndef SHARECOUNT_GESTIONNAIREEVENEMENT_HPP
#define SHARECOUNT_GESTIONNAIREEVENEMENT_HPP

#include <vector>
#include "Evenement.hpp"

class Utilisateur;
/**
 * @brief Gère les événements
 * @version v4
 * @author Louis Jacques
 */
class GestionnaireEvenement {
private:
    std::vector<Evenement> m_evenement;
    Utilisateur* user;

public:
    /**
 * @brief Gère les événements
 * @version v4
 * @author Louis Jacques
 */
    GestionnaireEvenement();

    /**
 * @brief Ajoute les événements
 * @param nom string
 * @param dateFin string
 * @param dateDebut string
 * @version v4
 * @author Louis Jacques
 */
    void ajouterEvenement (std::string nom,std::string dateDebut,std::string dateFin) ;

/**
 * @brief Détaille les événements connus
 * @return string
 * @version v4
 * @author Louis Jacques
 */
    std::string toString() const;

/**
 * @brief Récupère les événements
 * @param indice int
 * @return Gestionnaire
 * @version v4
 * @author Louis Jacques
 */
    GestionnaireEvenement& getEvenement(int indice);
};


#endif //SHARECOUNT_GESTIONNAIREEVENEMENT_HPP

