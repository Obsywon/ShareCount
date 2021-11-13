#ifndef SHARECOUNT_GESTIONNAIREGROUPES_HPP
#define SHARECOUNT_GESTIONNAIREGROUPES_HPP

#include <unordered_map>
#include "Groupe.hpp"

class GestionnaireGroupes {
private:
    std::unordered_map<std::string,Groupe> m_groupes;

public:
    /**
     * Gère et donne l'accès aux groupes connus par l'utilisateur local
     */
    GestionnaireGroupes();

    /**
     * Ajoute un groupe à la collection : l'utilisateur local est ajouté à ce groupe
     * @param nom Nom du groupe
     * @param u Utilisateur à ajouter
     */
    void ajouterGroupe (std::string nom, const Utilisateur* u) ;

    /**
     * Ajoute un événement à un groupe précis
     * @param idGroupe Identifiant du groupe, déjà connu par l'utilisateur
     * @param nom Nom de l'événement
     * @param dateDeb Date de début
     * @param dateFin Date de fin
     */
    void ajouterEvenemenent (std::string idGroupe,std::string nom, std::string dateDeb,std::string dateFin);

    /**
     * Ajout d'un membre à un groupe connu
     * @param idGroupe string identifiant du groupe
     * @param u Utilisateur à ajouter au groupe
     */
    void ajoutMembreAGroupe(std::string idGroupe,const Utilisateur* u);

    /**
     * Nombre de groupes auxquel l'utilisateur appartient
     * @return unsigned long
     */
    unsigned long taille();

    /**
     * Détaille tous les groupes dans lequel l'utilisateur est inscrit
     * @return String
     */
    std::string toString();


    /**
     * Récupère le groupe indiqué par l'identifiant
     * @param indice string identifiant
     * @return référence à Groupe
     */
    GestionnaireGroupes& getGroupe(std::string idGroupe);
};


#endif //SHARECOUNT_GESTIONNAIREGROUPES_HPP
