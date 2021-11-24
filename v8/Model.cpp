#include "Model.hpp"

#include <utility>
/**
 * Créer le modèle, classe facade
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
*/
Model::Model(){
    m_groupes = GestionnaireGroupes();
}

/**
 * Permet de vérifier la validité du mot de passe
 * @param mdp string
 * @return bool
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
bool Model::estValideMdP(const std::string& mdp) {
    bool test = true;
    if (!mdp.empty()){
        for (char i : mdp){
            if (std::isblank(i)){
                test = false;
            }
        }
    }
    return test;
}

/**
 * Vérifie si l'e-mail entrée est valide
 * @param email string
 * @return bool
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
bool Model::estValideEmail(const std::string& email) {
    const std::regex pattern (R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    return std::regex_match(email, pattern);
}

/**
 * Inscrire un utilisateur
 * @param pseudo pseudo
 * @param email email
 * @param mdp mdp
 * @return bool true si utilisateur est bien inscris
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
bool Model::inscrireUtilisateur(const std::string& pseudo, const std::string& email, const std::string& mdp) {
    if (m_groupes.taille() > 0){
        m_groupes = GestionnaireGroupes();
    }
    m_user = Utilisateur(pseudo, email, mdp, &m_groupes);
    return true;
}

/**
 * Vérifie si un utilisateur existe bien dans la base de données
 * @param pseudo string
 * @param mdp string
 * @return bool
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
bool Model::compteExiste(const std::string &pseudo, const std::string &mdp) {
    return true; // "Existe toujours" pour le moment
}

/**
 * Connecte et charge le compte utilisateur indiqué (A RETRAVAILLER!!!
 * lorsqu'un moyen d'enregistrer les données sera implémenté)
 * @param pseudo string
 * @param email string
 * @param mdp string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
void Model::connecterUtilisateur(const std::string& pseudo, const std::string& email, const std::string& mdp) {
    // A RETRAVAILLER lorsqu'un moyen d'enregistrer les données sera implémenter
    if (m_groupes.taille() > 0){
        m_groupes = GestionnaireGroupes();
    }
    m_user = Utilisateur(pseudo, email, mdp, &m_groupes);
}

/**
 * Détaille les informations connus (sans le mdp) de l'utilisateur local
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
std::string Model::userToString() const{
    return m_user.toString();
}

/**
 * Détaille les groupes auxquels l'utilisateur local appartient
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
   * @version v8 (Dernière modification)  : const ajouté
 */
std::string Model::groupesToString() const {
    return m_groupes.toString();
}


/**
 * Créer un nouveau groupe
 * @param nom string nom du groupe
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
void Model::creerGroupe(const std::string& nom) {
    m_groupes.ajouterGroupe(nom, &m_user);
}

/**
 * Créer un événement dans un groupe particulier
 * @param IDgroupe string identifiant du groupe visé
 * @param nom Nom de l'événement
 * @param dateDeb Date de début
 * @param dateFin Date de fin
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
void Model::creerEvenement(const std::string& IDgroupe, const std::string& nom, const std::string& dateDeb, const std::string& dateFin) {
    m_groupes.ajouterEvenemenent(IDgroupe, nom, dateDeb, dateFin);
}


/**
 * Ajoute un utilisateur à un groupe
 * @param idGroupe Identifiant du groupe visé
 * @param u Utilisateur à inscrire au groupe
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
void Model::ajouterMembreAGroupe(const std::string& idGroupe, const Utilisateur *u){
    m_groupes.ajoutMembreAGroupe(idGroupe,u);
}

/**
 * Détaille toutes les informations connues par le modèle
 * @return string
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
std::string Model::toString() const{
    std::string temp = userToString();
    temp.append("\n");
    temp.append(m_groupes.toString());
    return temp;
}

/**
 * @brief Liste des ids du gstionnaire de groupe
 * @return vector
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
 * @version v8 (Dernière modification)  : const ajouté
 */
std::vector <std::string> Model::listeIDs() const{
    return m_groupes.listeIDs();
}

/**
 * @brief Liste des noms du gstionnaire de groupe
 * @return vector
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
 * @version v8 (Dernière modification)  : const ajouté
 */
std::vector <std::string> Model::listeNoms() const{
    return m_groupes.listeNoms();
}

/**
 * Récupère tous les groupes connus
 * @return Groupes (hashmap)
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
 */
std::unordered_map<std::string, Groupe> *Model::getTousLesGroupesConnus() {
    return m_groupes.getTousLesGroupesConnus();
}


