//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_GESTIONNAIREGROUPES_HPP
#define SHARECOUNT_GESTIONNAIREGROUPES_HPP

#include <vector>
#include "Groupe.hpp"

class Utilisateur;

class GestionnaireGroupes {
private:
    std::vector<Groupe> m_groupes;
    Utilisateur* user;

public:
    GestionnaireGroupes();
    void ajouterGroupe (std::string nom, const Utilisateur* u) ;
    std::string toString();
};


#endif //SHARECOUNT_GESTIONNAIREGROUPES_HPP
