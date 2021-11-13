#ifndef GESTIONNAIRECOMPTES_HPP
#define GESTIONNAIRECOMPTES_HPP

#include "Utilisateur.hpp"
#include <vector>


class GestionnaireComptes
{
private:
    std::vector<Utilisateur> m_comptes;

public:
    GestionnaireComptes();

    /**
     * @brief ajouterCompte permet d'ajouter un compte au gestionnaire
     * @param u Utilisateur
     */
    void ajouterCompte(const Utilisateur* u);

    /**
     * Détaille le contenu du gestionnaire de compte
     * @return String
     */
    std::string toString() const;

    /**
     * Liste les pseudos connus par le gestionnaire de compte
     * @return string
     */
    std::vector<std::string> listPseudos();

    /**
     * Liste les e-mails connus par le gestionnaire de compte
     * @return string
     */
    std::vector<std::string> listMails();
};

#endif // GESTIONNAIRECOMPTES_HPP
