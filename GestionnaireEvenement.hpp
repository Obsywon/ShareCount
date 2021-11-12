#ifndef SHARECOUNT_GESTIONNAIREEVENEMENT_HPP
#define SHARECOUNT_GESTIONNAIREEVENEMENT_HPP

#include <vector>
#include "Evenement.hpp"

class Utilisateur;

class GestionnaireEvenement {
private:
    std::vector<Evenement> m_evenement;
    Utilisateur* user;

public:
    /**
     * Collection d'événements connus par un groupe
     */
    GestionnaireEvenement();

    /**
     * Génère un événement lié à un groupe de clients
     * @param nom nom de l'évenement
     * @param dateDebut Date de début
     * @param dateFin Date de fin
     */
    void creerEvenement (std::string nom,std::string dateDebut,std::string dateFin) ;

    /**
     * Détaille les événements connus par le gestionnaire
     * @return String
     */
    std::string toString() const;

    /**
     * Récupère l'evenement indiqué
     * @param indice int
     * @return référence à Evenement
     */
    GestionnaireEvenement& getEvenement(int indice);
};


#endif //SHARECOUNT_GESTIONNAIREEVENEMENT_HPP

