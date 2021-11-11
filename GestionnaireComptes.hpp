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

    std::string toString() const;

    std::vector<std::string> listPseudos();
    std::vector<std::string> listMails();
};

#endif // GESTIONNAIRECOMPTES_HPP
