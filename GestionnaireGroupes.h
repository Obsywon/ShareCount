//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_GESTIONNAIREGROUPES_H
#define SHARECOUNT_GESTIONNAIREGROUPES_H

#include <vector>
#include "groupe.hpp"


class GestionnaireGroupes {
private:
    std::vector<Groupe> m_groupes;

public:
    GestionnaireGroupes();
    void ajouterGroupe (std::string nom, const Utilisateur& u) ;
    std::string toString();
};


#endif //SHARECOUNT_GESTIONNAIREGROUPES_H
