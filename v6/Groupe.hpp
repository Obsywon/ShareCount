#ifndef SHARECOUNT_GROUPE_HPP
#define SHARECOUNT_GROUPE_HPP
#include <string>
#include "GestionnaireEvenement.hpp"
#include "GestionnaireComptes.hpp"
#include "FabriqueID.hpp"



class Groupe {
private:
    std::string m_id;
    std::string m_nom;
    GestionnaireEvenement ges;
    GestionnaireComptes gesCom;

public:

    Groupe();

    /**
     * Groupe regroupant l'ensemble de participants, d'événements et diverses informations les concernant
     * @param nom Nom du groupe
     */
    Groupe(std::string nom);

    /**
     * Créer un événement lié à un groupe d'utilisateurs
     * @param nom Nom de l'événement
     * @param dateDeb Date de début de l'évenement
     * @param dateFin Date de fin
     */
    void creerEvenement(std::string nom,std::string dateDeb,std::string dateFin);

    /**
     * Ajoute un membre à un groupe
     * @param u Utilisateur
     */
    void ajouterMembre(const Utilisateur* u);

    /**
     * Détails le contenu d'un groupe
     * @return string
     */
    std::string toString() const;

    /**
     * @return Id d'un groupe
     */
    std::string getId() const;

    /**
     * @return Nom d'un groupe
     */
    std::string getNom() const;

    /**
     * Ajoute un identifiant au groupe
     * @param id string
     */
    void setId(std::string id);
};


#endif //SHARECOUNT_GROUPE_HPP
