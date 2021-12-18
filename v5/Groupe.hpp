#ifndef SHARECOUNT_GROUPE_HPP
#define SHARECOUNT_GROUPE_HPP
#include <string>
#include "GestionnaireEvenement.hpp"
#include "GestionnaireComptes.hpp"


/**
* @brief Groupe
* @author Guillaume Vautrin
* @version v5
*/
class Groupe {
private:
/**
* @brief nom du groupe
* @author Guillaume Vautrin
* @version v3
*/
    std::string m_nom;

    /**
* @brief Evenements
* @author Louis Jacques
* @version v5
*/
    GestionnaireEvenement ges;

    /**
* @brief Participants
* @author Louis Jacques
* @version v5
*/
    GestionnaireComptes gesCom;

public:
/**
* @brief Groupe
* @author Guillaume Vautrin
* @version v3
*/
    Groupe();

    /**
* @brief Groupe
* @param nom
* @author Guillaume Vautrin
* @version v3
*/
    Groupe(std::string nom);

    /**
* @brief Créer un événement
* @param string nom
 * @param dateFin date de fin
 * @param dateDeb date de début
* @author Guillaume Vautrin
* @version v5
*/
    void creerEvenement(std::string nom,std::string dateDeb,std::string dateFin);

    /**
* @brief décris un groupe
* @param string
* @author Guillaume Vautrin
* @version v5
*/
    void ajouterMembre(const Utilisateur* u);

    /**
* @brief décris un groupe
* @return string
* @author Guillaume Vautrin
* @version v5
*/
    std::string toString() const;
};


#endif //SHARECOUNT_GROUPE_HPP
