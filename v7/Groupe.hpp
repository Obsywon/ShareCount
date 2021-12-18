#ifndef SHARECOUNT_GROUPE_HPP
#define SHARECOUNT_GROUPE_HPP
#include <string>
#include "GestionnaireEvenement.hpp"
#include "GestionnaireComptes.hpp"
#include "FabriqueID.hpp"



class Groupe {
private:

/**
* @brief identifiant du groupe
* @author Guillaume Vautrin
* @version v6
*/
    std::string m_id;
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
     * Groupe regroupant l'ensemble de participants, d'événements et diverses informations les concernant
     * @param nom Nom du groupe
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

/**
* @brief retourne idenfiant du groupe
* @return string id
* @author Guillaume Vautrin
* @version v6
*/
    std::string getId() const;
/**
* @brief retourne nom du groupe
* @return string
* @author Guillaume Vautrin
* @version v6
*/
    std::string getNom() const;

/**
* @brief applique nouvel idenfiant du groupe
* @return string id
* @author Guillaume Vautrin
* @version v6
*/
    void setId(std::string id);
};


#endif //SHARECOUNT_GROUPE_HPP
