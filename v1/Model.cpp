#include "Model.hpp"
#include <cctype>
#include <QString>

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
bool Model::estValideMdP(const std::string mdp) {
    bool test = false;
    if (!mdp.empty()){
        for (char i : mdp){
            if (std::isspace(i) || std::isblank(i)){
                test = true;
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
bool Model::estValideEmail(const std::string email) {
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
bool Model::inscrireUtilisateur(const std::string pseudo, const std::string email, const std::string mdp) {
    m_user = Utilisateur(pseudo, email, mdp);
    return false;
}

/**
 * @brief Décris le modèle
 * @author Guillaume Vautrin
 * @version v1
 * @return string
 */
const std::string Model::userToString() {
    return m_user.toString();
}



