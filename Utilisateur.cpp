//
// Created by guy on 09/11/2021.
//

#include "Utilisateur.hpp"

Utilisateur::Utilisateur() : m_nom(""), m_prenom(""), m_email(""), m_pseudo(""), m_password(""){}

/**
 * Représente un compte utilisateur
 * @param n string Nom
 * @param p string Prénom
 */
Utilisateur::Utilisateur(const std::string pseudo, const std::string email, const std::string mdp):
m_pseudo(pseudo), m_email(email), m_password(mdp){}

Utilisateur::~Utilisateur(){
    //std::cout << "Utilisateur détruit \n";
}

void Utilisateur::setNom(const std::string n){
    m_nom = n;
}

void Utilisateur::setPrenom(const std::string p){
    m_prenom = p;
}

std::string Utilisateur::getNom(){
    return m_nom;
}

std::string Utilisateur::getPrenom(){
    return m_prenom;
}

void Utilisateur::setPseudo(std::string pseudo) {
    m_pseudo = pseudo;
}

void Utilisateur::setMdp(std::string mdp) {
    m_password = mdp;
}


std::string Utilisateur::toString(){
    std::string temp = m_pseudo;
    temp.append(" ");
    temp.append(m_prenom).append(" ").append(m_nom).append(" ").append("\n");
    temp.append("mail: ").append(m_email);
    return temp;
}

std::string Utilisateur::getPseudo() {
    return std::string();
}






