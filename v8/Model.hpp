#ifndef SHARECOUNT_MODEL_HPP
#define SHARECOUNT_MODEL_HPP

#include "GestionnaireGroupes.hpp"
#include "regex"
#include <cctype>


/**
 * Créer le modèle, classe facade
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
*/
class Model {
private:
/**
 * @brief Utilisateur identifé
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
*/
    Utilisateur m_user;
/**
 * @brief Gestionnaire de groupes
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
*/
    GestionnaireGroupes m_groupes;

public:

/**
 * Créer le modèle, classe facade
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
*/
Model();

/**
 * Permet de vérifier la validité du mot de passe
 * @param mdp string
 * @return bool
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
bool estValideMdP (const std::string& mdp);

/**
 * Vérifie si l'e-mail entrée est valide
 * @param email string
 * @return bool
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
bool estValideEmail (const std::string& email);

/**
 * Inscrire un utilisateur
 * @param pseudo pseudo
 * @param email email
 * @param mdp mdp
 * @return bool true si utilisateur est bien inscris
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
bool inscrireUtilisateur (std::string pseudo, std::string email, std::string mdp);

/**
 * Vérifie si un utilisateur existe bien dans la base de données
 * @param pseudo string
 * @param mdp string
 * @return bool
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
bool compteExiste (const std::string& pseudo, const std::string& mdp);

/**
 * Connecte et charge le compte utilisateur indiqué (A RETRAVAILLER!!!
 * lorsqu'un moyen d'enregistrer les données sera implémenté)
 * @param pseudo string
 * @param email string
 * @param mdp string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
void connecterUtilisateur (std::string pseudo, std::string email, std::string mdp);

/**
 * Détaille les informations connus (sans le mdp) de l'utilisateur local
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
std::string userToString();

/**
 * Détaille les groupes auxquels l'utilisateur local appartient
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
std::string  groupesToString();

/**
 * Créer un nouveau groupe
 * @param nom string nom du groupe
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
void creerGroupe (std::string nom);

/**
 * Créer un événement dans un groupe particulier
 * @param IDgroupe string identifiant du groupe visé
 * @param nom Nom de l'événement
 * @param dateDeb Date de début
 * @param dateFin Date de fin
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
void creerEvenement (std::string IDgroupe, std::string nom, std::string dateDeb,std::string dateFin);

/**
 * Ajoute un utilisateur à un groupe
 * @param idGroupe Identifiant du groupe visé
 * @param u Utilisateur à inscrire au groupe
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
void ajouterMembreAGroupe(std::string idGroupe,const Utilisateur* u);


/**
 * Détaille toutes les informations connues par le modèle
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
std::string toString();

/**
 * @brief Liste des ids du gstionnaire de groupe
 * @return vector
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
std::vector <std::string> listeIDs();

/**
 * @brief Liste des noms du gstionnaire de groupe
 * @return vector
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
std::vector <std::string> listeNoms();

/**
 * Récupère tous les groupes connus
 * @return Groupes (hashmap)
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
std::unordered_map<std::string, Groupe> *getTousLesGroupesConnus();

};


#endif //SHARECOUNT_MODEL_HPP
