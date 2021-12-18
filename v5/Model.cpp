#include "Model.hpp"

#include <utility>
/**
 * @brief Classe facade en interaction avec l'interface et la base de donnée
 * @author Guillaume Vautrin
 * @version v1
 */
Model::Model(){
    m_groupes = GestionnaireGroupes();
}

/**
 * @brief Vérifie si le mot de passe est valide
 * @param mdp mot de passe
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
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
 * @brief Vérifie si l'e-mail est valide
 * @param email e-mail
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
 */
bool Model::estValideEmail(const std::string& email) {
    const std::regex pattern (R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    return std::regex_match(email, pattern);
}

/**
 * @brief Inscrit l'utilisateur
 * @param pseudo pseudonyme
 * @param email Email
 * @param mdp Mot de passe
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
 */
bool Model::inscrireUtilisateur(std::string pseudo, std::string email, std::string mdp) {
    if (m_groupes.taille() > 0){
        m_groupes = GestionnaireGroupes();
    }
    m_user = Utilisateur(std::move(pseudo), std::move(email), std::move(mdp), &m_groupes);
    return true;
}

/**
 * @brief Décris l'utilisateur
 * @author Guillaume Vautrin
 * @version v1
 * @return string
 */
std::string Model::userToString() {
    return m_user.toString();
}

/**
 * @brief Vérifie si le compte existe
 * @param pseudo pseudonyme
 * @param mdp mot de passe
 * @return bool
 * @author Guillaume Vautrin
 * @version v1
 */
bool Model::compteExiste(const std::string &pseudo, const std::string &mdp) {
    return true; // "Existe toujours" pour le moment
}

/**
 * @brief Connecte l'utilisateur
 * @param pseudo pseudonyme
 * @param email email
 * @param mdp mot de passe
 * @return bool
 * @author Guillaume Vautrin
 * @version v5 - modifs
 */
void Model::connecterUtilisateur(std::string pseudo, std::string email, std::string mdp) {
    // A RETRAVAILLER lorsqu'un moyen d'enregistrer les données sera implémenter
    if (m_groupes.taille() > 0){
        m_groupes = GestionnaireGroupes();
    }
    m_user = Utilisateur(std::move(pseudo), std::move(email), std::move(mdp), &m_groupes);
}

/**
 * @brief Décris les groupes connus
 * @author Guillaume Vautrin
 * @version v3
 * @return string
 */
std::string Model::groupesToString() {
    return m_groupes.toString();
}

/**
 * @brief Décris le modèle
 * @author Guillaume Vautrin
 * @version v5
 * @return string
 */
std::string Model::toString(){
    std::string temp = userToString();
    temp.append("\n");
    temp.append(m_groupes.toString());
    return temp;
}

/**
 * @brief Créer un groupe
 * @param nom nom du nouveau groupe
 * @author Guillaume Vautrin
 * @version v3
 * @return string
 */
void Model::creerGroupe(std::string nom) {
    m_groupes.ajouterGroupe(nom, &m_user);
}

/**
* @brief Ajoute un membre à un groupe
* @param idGroupe identifiant du groupe
* @param u utilisateur à ajouter au groupe
* @author Guillaume Vautrin
* @version v5
* @return string
*/
void Model::ajouterMembreAGroupe(std::string idGroupe, const Utilisateur *u){
    m_groupes.ajoutMembreAGroupe(idGroupe,u);
}
/**
* @brief Créer un événement
* @param IDgroupe identifiant groupe
* @param nom nom du groupe
* @param dateDeb date de début
* @param dateFin date de fin
* @author Guillaume Vautrin
* @version v5
* @return string
*/
void Model::creerEvenement(std::string IDgroupe, std::string nom, std::string dateDeb,std::string dateFin) {
    m_groupes.ajouterEvenemenent(IDgroupe, nom, dateDeb, dateFin);
}


