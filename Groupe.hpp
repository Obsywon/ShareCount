//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_GROUPE_HPP
#define SHARECOUNT_GROUPE_HPP
#include <string>
#include "GestionnaireEvenement.hpp"
#include "GestionnaireComptes.hpp"



class Groupe {
private:
    std::string m_nom;
    GestionnaireEvenement ges;
    GestionnaireComptes gesCom;

public:

    Groupe();
    Groupe(std::string nom);
    void creerEvenement(std::string nom,std::string dateDeb,std::string dateFin);
    void ajouterMembre(const Utilisateur* u);
    std::string toString();
};


#endif //SHARECOUNT_GROUPE_HPP
