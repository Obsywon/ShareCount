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
* @version v1 (Dernière modification)
*/
Model();

/**
 * Permet de vérifier la validité du mot de passe
 * @param mdp string
 * @return bool
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
bool estValideMdP (const std::string& mdp);

/**
 * Vérifie si l'e-mail entrée est valide
 * @param email string
 * @return bool
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
bool estValideEmail (const std::string& email);

/**
 * Inscrire un utilisateur
 * @param pseudo pseudo
 * @param email email
 * @param mdp mdp
 * @return bool true si utilisateur est bien inscris
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
bool inscrireUtilisateur (const std::string& seudo, const std::string& email, const std::string& mdp);

/**
 * Vérifie si un utilisateur existe bien dans la base de données
 * @param pseudo string
 * @param mdp string
 * @return bool
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
bool compteExiste (const std::string& pseudo, const std::string& mdp);

/**
 * Connecte et charge le compte utilisateur indiqué (A RETRAVAILLER!!!
 * lorsqu'un moyen d'enregistrer les données sera implémenté)
 * @param pseudo string
 * @param email string
 * @param mdp string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
void connecterUtilisateur (const std::string& pseudo, const std::string& email, const std::string& mdp);

/**
 * Détaille les informations connus (sans le mdp) de l'utilisateur local
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
std::string userToString() const;

/**
 * Détaille les groupes auxquels l'utilisateur local appartient
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
std::string  groupesToString() const;

/**
 * Créer un nouveau groupe
 * @param nom string nom du groupe
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
void creerGroupe (const std::string& nom);

/**
 * Créer un événement dans un groupe particulier
 * @param IDgroupe string identifiant du groupe visé
 * @param nom Nom de l'événement
 * @param dateDeb Date de début
 * @param dateFin Date de fin
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
void creerEvenement (const std::string& IDgroupe, const std::string& nom, const std::string& dateDeb, const std::string& dateFin);

/**
 * Ajoute un utilisateur à un groupe
 * @param idGroupe Identifiant du groupe visé
 * @param u Utilisateur à inscrire au groupe
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
void ajouterMembreAGroupe(const std::string& idGroupe, const Utilisateur* u);


/**
 * Détaille toutes les informations connues par le modèle
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
 * @version v8 (Dernière modification)  : const ajouté
 */
std::string toString() const;

/**
 * @brief Liste des ids du gstionnaire de groupe
 * @return vector
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v8 (Dernière modification)  : const ajouté
 */
std::vector <std::string> listeIDs() const;

/**
 * @brief Liste des noms du gstionnaire de groupe
 * @return vector
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
     * @version v8 (Dernière modification)  : const ajouté

 */
std::vector <std::string> listeNoms() const;

/**
 * Récupère tous les groupes connus
 * @return Groupes (hashmap)
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v7 (Dernière modification)
 */
std::unordered_map<std::string, Groupe> *getTousLesGroupesConnus();

};


#endif //SHARECOUNT_MODEL_HPP
