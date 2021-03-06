#include "GestionnaireComptes.hpp"

GestionnaireComptes::GestionnaireComptes(){
    m_comptes = std::vector<Utilisateur>();
}

void GestionnaireComptes::ajouterCompte (const Utilisateur *u){
    m_comptes.push_back(*u);

}

std::string GestionnaireComptes::toString() const {
    std::string temp = "Comptes du groupe : \n";
    int i = 0;
    for (Utilisateur u: m_comptes) {
        temp.append(" - ");
        temp.append(std::to_string(i)).append(": ").append(u.getPseudo()).append(" - Mail : ").append(u.getEmail());
        temp += "\n";
        i++;
    }

    return temp;
}

std::vector<std::string> GestionnaireComptes::listPseudos(){
    std::vector<std::string> list;
    for (auto & u : m_comptes){
        list.push_back(u.getPseudo());
    }
    return list;
}

std::vector<std::string> GestionnaireComptes::listMails(){
    std::vector<std::string> list;
    for (auto & u : m_comptes){
        list.push_back(u.getEmail());
    }
    return list;
}


