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
 * @brief Récupère tous les participants connus
 * @return vecteur
 * @author Louis Jacques
 * @version v13 (Dernière modification)
 */
std::vector<Utilisateur> * GestionnaireComptes::getTousLesParticipantsConnus(){
    return &m_comptes;
}

/**
 * @brief Ajoute tous les membres du groupes depuis la base de données
 * @param membres hashmap
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
void GestionnaireComptes::chargeMembres(const std::unordered_map <int, std::string>& membres){
    m_comptes.clear();
    for(auto const& key : membres){
        const Utilisateur user = Utilisateur(key.first, key.second);
        m_comptes.push_back(user);
    }
}


