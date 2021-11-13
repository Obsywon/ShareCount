#include "Model.hpp"

#include <utility>

Model::Model(){
    m_groupes = GestionnaireGroupes();
}

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
    if (m_groupes.taille() > 0){
        m_groupes = GestionnaireGroupes();
    }
    m_user = Utilisateur(std::move(pseudo), std::move(email), std::move(mdp), &m_groupes);
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
    if (m_groupes.taille() > 0){
        m_groupes = GestionnaireGroupes();
    }
    m_user = Utilisateur(std::move(pseudo), std::move(email), std::move(mdp), &m_groupes);
}

std::string Model::groupesToString() {
    return m_groupes.toString();
}

std::string Model::toString(){
    std::string temp = userToString();
    temp.append("\n");
    temp.append(m_groupes.toString());
    return temp;
}

void Model::creerGroupe(std::string nom) {
    m_groupes.ajouterGroupe(nom, &m_user);
}

void Model::ajouterMembreAGroupe(std::string idGroupe, const Utilisateur *u){
    m_groupes.ajoutMembreAGroupe(idGroupe,u);
}

void Model::creerEvenement(std::string IDgroupe, std::string nom, std::string dateDeb,std::string dateFin) {
    m_groupes.ajouterEvenemenent(IDgroupe, nom, dateDeb, dateFin);
}


