#include "Model.hpp"

#include <cctype>
#include <utility>

/**
 * @brief Classe facade en interaction avec l'interface et la base de donnée
 * @author Guillaume Vautrin
 * @version v1
 */
Model::Model(){}
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
    m_user = Utilisateur(std::move(pseudo), std::move(email), std::move(mdp));
    return true;
}
/**
 * @brief Décris les utilisateurs
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
 * @version v1
 */
void Model::connecterUtilisateur(std::string pseudo, std::string email, std::string mdp) {
    // A RETRAVAILLER lorsqu'un moyen d'enregistrer les données sera implémenter
    m_user = Utilisateur(std::move(pseudo), std::move(email), std::move(mdp));
}
