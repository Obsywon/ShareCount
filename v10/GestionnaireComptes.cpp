#include "GestionnaireComptes.hpp"

/**
 * @brief Constructeur du gestionnaire
 * @author Guillaume Vautrin, Louis Jacques
 * @version v6 (Dernière modification)
 */
GestionnaireComptes::GestionnaireComptes(){
    m_comptes = std::vector<Utilisateur>();
}

/**
 * @brief ajouterCompte permet d'ajouter un compte au gestionnaire
 * @param u Utilisateur
 * @author Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
 */
void GestionnaireComptes::ajouterCompte (const Utilisateur *u){
    m_comptes.push_back(*u);

}

/**
 * @brief le contenu du gestionnaire de compte
 * @return String
 * @author Guillaume Vautrin, Louis Jacques
 * @version v8 (Dernière modification) : const ajouté
 */
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

/**
 * Liste les pseudos connus par le gestionnaire de compte
 * @return string
 * @author Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : typage auto ajouté
 */
std::vector<std::string> GestionnaireComptes::listPseudos(){
    std::vector<std::string> list;
    for (auto & u : m_comptes){
        list.push_back(u.getPseudo());
    }
    return list;
}

/**
 * Liste les e-mails connus par le gestionnaire de compte
 * @return string
 * @author Guillaume Vautrin, Louis Jacques
 * @version v6 (Dernière modification)
 */
std::vector<std::string> GestionnaireComptes::listMails() {
    std::vector<std::string> list;
    for (auto & u : m_comptes){
        list.push_back(u.getEmail());
    }
    return list;
}


