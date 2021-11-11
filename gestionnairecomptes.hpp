#ifndef GESTIONNAIRECOMPTES_HPP
#define GESTIONNAIRECOMPTES_HPP

#include "Utilisateur.hpp"

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
    void ajouterCompte(Utilisateur u);

    std::string toString();
};

#endif // GESTIONNAIRECOMPTES_HPP
