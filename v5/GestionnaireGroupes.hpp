#ifndef SHARECOUNT_GESTIONNAIREGROUPES_HPP
#define SHARECOUNT_GESTIONNAIREGROUPES_HPP

#include <unordered_map>
#include "Groupe.hpp"

class GestionnaireGroupes {
private:
    std::unordered_map<std::string,Groupe> m_groupes;

public:
    GestionnaireGroupes();
    void ajouterGroupe (std::string nom, const Utilisateur* u) ;
    void ajouterEvenemenent (std::string idGroupe,std::string nom, std::string dateDeb,std::string dateFin);
    void ajoutMembreAGroupe(std::string idGroupe,const Utilisateur* u);
    unsigned long taille();
    std::string toString();


    /**
     * Récupère le groupe indiqué
     * @param indice int
     * @return référence à Groupe
     */
    GestionnaireGroupes& getGroupe(std::string idGroupe);
};


#endif //SHARECOUNT_GESTIONNAIREGROUPES_HPP
