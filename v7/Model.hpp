#ifndef SHARECOUNT_MODEL_HPP
#define SHARECOUNT_MODEL_HPP

#include "GestionnaireGroupes.hpp"
#include "regex"
#include <cctype>


class Model {
private:
    Utilisateur m_user;
    GestionnaireGroupes m_groupes;

public:

    /**
     * Créer le modèle, classe facade
     */
    Model();

    /**
     * Permet de vérifier la validité du mot de passe
     * @param mdp string
     * @return bool
     */
    bool estValideMdP (const std::string& mdp);

    /**
     * Vérifie si l'e-mail entrée est valide
     * @param email string
     * @return bool
     */
    bool estValideEmail (const std::string& email);

    /**
     * Inscrire un utilisateur
     * @param pseudo pseudo
     * @param email email
     * @param mdp mdp
     * @return bool true si utilisateur est bien inscris
     */
    bool inscrireUtilisateur (std::string pseudo, std::string email, std::string mdp);

    /**
     * Vérifie si un utilisateur existe bien dans la base de données
     * @param pseudo string
     * @param mdp string
     * @return bool
     */
    bool compteExiste (const std::string& pseudo, const std::string& mdp);

    /**
     * Connecte et charge le compte utilisateur indiqué (A RETRAVAILLER!!!
     * lorsqu'un moyen d'enregistrer les données sera implémenté)
     * @param pseudo string
     * @param email string
     * @param mdp string
     */
    void connecterUtilisateur (std::string pseudo, std::string email, std::string mdp);

    /**
     * Détaille les informations connus (sans le mdp) de l'utilisateur local
     * @return string
     */
    std::string userToString();

    /**
     * Détaille les groupes auxquels l'utilisateur local appartient
     * @return string
     */
    std::string  groupesToString();

    /**
     * Créer un nouveau groupe
     * @param nom string nom du groupe
     */
    void creerGroupe (std::string nom);

    /**
     * Créer un événement dans un groupe particulier
     * @param IDgroupe string identifiant du groupe visé
     * @param nom Nom de l'événement
     * @param dateDeb Date de début
     * @param dateFin Date de fin
     */
    void creerEvenement (std::string IDgroupe, std::string nom, std::string dateDeb,std::string dateFin);

    /**
     * Ajoute un utilisateur à un groupe
     * @param idGroupe Identifiant du groupe visé
     * @param u Utilisateur à inscrire au groupe
     */
    void ajouterMembreAGroupe(std::string idGroupe,const Utilisateur* u);


    /**
     * Détaille toutes les informations connues par le modèle
     * @return string
     */
    std::string toString();

    /**
     * @brief Liste des ids du gstionnaire de groupe
     * @return vector
     */
std::vector <std::string> listeIDs();

/**
 * @brief Liste des noms du gstionnaire de groupe
 * @return vector
 */
std::vector <std::string> listeNoms();

};


#endif //SHARECOUNT_MODEL_HPP
