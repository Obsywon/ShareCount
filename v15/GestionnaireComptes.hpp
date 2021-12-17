#ifndef GESTIONNAIRECOMPTES_HPP
#define GESTIONNAIRECOMPTES_HPP

#include "Utilisateur.hpp"
#include <vector>
#include <unordered_map>

/**
 * @brief Gestionnaire des comptes des utilisateurs invités à un groupe
 * @author Guillaume Vautrin, Louis Jacques
 * @version v6 (Dernière modification)
 */
class GestionnaireComptes
{
private:
/**
 * @brief Collection d'utilisateurs
* @author Guillaume Vautrin, Louis Jacques
* @version v6 (Dernière modification)
 */
    std::vector<Utilisateur> m_comptes;

public:
    /**
     * @brief Constructeur du gestionnaire
     * @author Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    GestionnaireComptes();

    /**
     * @brief ajouterCompte permet d'ajouter un compte au gestionnaire
     * @param u Utilisateur
     * @author Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
     */
    void ajouterCompte(const Utilisateur* u);

    /**
     * @brief le contenu du gestionnaire de compte
     * @return String
     * @author Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
     */
    std::string toString() const;

    /**
     * @brief Récupère tous les participants connus
     * @return vecteur
     * @author Louis Jacques
     * @version v13 (Dernière modification)
     */
    std::vector<Utilisateur>* getTousLesParticipantsConnus();

    /**
     * @brief Ajoute tous les membres du groupes depuis la base de données
     * @param membres hashmap
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    void chargeMembres(const std::unordered_map <int, std::string>& membres);
};

#endif // GESTIONNAIRECOMPTES_HPP
