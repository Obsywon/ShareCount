//
// Created by guy on 09/11/2021.
//

#include "Model.hpp"
#include <cctype>
#include <QString>

Model::Model(){}

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

bool Model::estValideEmail(const std::string email) {
    const std::regex pattern (R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    return std::regex_match(email, pattern);
}

bool Model::inscrireUtilisateur(const std::string pseudo, const std::string email, const std::string mdp) {
    m_user = Utilisateur(pseudo, email, mdp);
    return false;
}

const std::string Model::userToString() {
    return m_user.toString();
}



