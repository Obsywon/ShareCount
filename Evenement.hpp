#ifndef SHARECOUNT_EVENEMENT_HPP
#define SHARECOUNT_EVENEMENT_HPP

#include <string>
#include <utility>

class Evenement {

private:
    std::string m_nom;
    std::string m_dateDeb;
    std::string m_dateFin;

public:
    Evenement();
    /**
     * Instance d'un événement d'un groupe
     * @param nom Nom d'un groupe
     * @param dateDeb Date de début de l'événement
     * @param dateFin Date de fin
     */
    Evenement(std::string nom, std::string dateDeb, std::string dateFin);


    /**
     * Détaille le contenu d'un événement
     * @return string
     */
    std::string toString();
};


#endif //SHARECOUNT_EVENEMENT_HPP
