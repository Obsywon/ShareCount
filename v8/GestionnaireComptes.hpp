#ifndef GESTIONNAIRECOMPTES_HPP
#define GESTIONNAIRECOMPTES_HPP

#include "Utilisateur.hpp"
#include <vector>

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
     * @version v6 (Dernière modification)
     */
    void ajouterCompte(const Utilisateur* u);

    /**
     * @brief le contenu du gestionnaire de compte
     * @return String
     * @author Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    std::string toString() const;

    /**
     * Liste les pseudos connus par le gestionnaire de compte
     * @return string
     * @author Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    std::vector<std::string> listPseudos();

    /**
     * Liste les e-mails connus par le gestionnaire de compte
     * @return string
     * @author Guillaume Vautrin, Louis Jacques
     * @version v6 (Dernière modification)
     */
    std::vector<std::string> listMails();
};

#endif // GESTIONNAIRECOMPTES_HPP
