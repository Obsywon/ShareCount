#ifndef SHARECOUNT_EVENEMENT_HPP
#define SHARECOUNT_EVENEMENT_HPP

#include <string>
#include <utility>

/**
 * @brief Représente un événement lié à un groupe
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v4 (Dernière modification)
 */
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
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
     */
    Evenement(const std::string& nom, const std::string& dateDeb, const std::string& dateFin);


    /**
     * Détaille le contenu d'un événement
     * @return string
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v8 (Dernière modification) : const ajouté
     */
    std::string toString() const;
};


#endif //SHARECOUNT_EVENEMENT_HPP
