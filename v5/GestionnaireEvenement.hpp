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
    GestionnaireEvenement();
    void creerEvenement (std::string nom,std::string dateDebut,std::string dateFin) ;
    std::string toString() const;

    /**
     * Récupère l'evenement indiqué
     * @param indice int
     * @return référence à Evenement
     */
    GestionnaireEvenement& getEvenement(int indice);
};


#endif //SHARECOUNT_GESTIONNAIREEVENEMENT_HPP
