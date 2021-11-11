#include "GestionnaireComptes.hpp"

GestionnaireComptes::GestionnaireComptes(){
    m_comptes = std::vector<Utilisateur>(20);
}




void GestionnaireComptes::ajouterCompte (Utilisateur u){
    m_comptes.push_back(u);

}

std::string GestionnaireComptes::toString(){
    /*
    int i = 0;
    std::string temp = "";
    for (Utilisateur u: m_comptes) {
        temp += ("%d - Pseudo : %s - e-mail : %s",i, u.getPseudo(), u.getEmail());
        i++;
    }
    */
    return "";
}
