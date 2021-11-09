//
// Created by guy on 09/11/2021.
//

#include "Model.hpp"

#include <cctype>
#include <utility>

Model::Model(){}

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

bool Model::estValideEmail(const std::string& email) {
    const std::regex pattern (R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    return std::regex_match(email, pattern);
}

bool Model::inscrireUtilisateur(std::string pseudo, std::string email, std::string mdp) {
    m_user = Utilisateur(std::move(pseudo), std::move(email), std::move(mdp));
    return true;
}

std::string Model::userToString() {
    return m_user.toString();
}

bool Model::compteExiste(const std::string &pseudo, const std::string &mdp) {
    return true; // "Existe toujours" pour le moment
}

void Model::connecterUtilisateur(std::string pseudo, std::string email, std::string mdp) {
    // A RETRAVAILLER lorsqu'un moyen d'enregistrer les données sera implémenter
    m_user = Utilisateur(std::move(pseudo), std::move(email), std::move(mdp));
}

}
