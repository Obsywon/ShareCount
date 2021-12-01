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
    int m_id;
    std::string m_nom;
    std::string m_dateDeb;
    std::string m_dateFin;

public:
    Evenement();
    /**
     * Instance d'un événement d'un groupe
     * @param id identifiant de l'événement
     * @param nom Nom d'un groupe
     * @param dateDeb Date de début de l'événement
     * @param dateFin Date de fin
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v9 (Dernière modification)  : ajout identifiant
     */
    Evenement(const int& id, const std::string& nom, const std::string& dateDeb, const std::string& dateFin);


    /**
     * Détaille le contenu d'un événement
     * @return string
     * @authors Guillaume Vautrin, Louis Jacques
     * @return id
     * @version v8 (Dernière modification) : const ajouté
     */
    std::string toString() const;


    /**
     * @brief Récupère l'id de l'événement
     * @authors Guillaume Vautrin
    * @version v9 (Dernière modification)  : ajout getter
     */
    int getId() const;

    /**
     * @brief Récupère le nom de l'événement
     * @authors Guillaume Vautrin
     * @return nom
     * @version v9 (Dernière modification)  : ajout getter
     */
    std::string getNom() const;

};


#endif //SHARECOUNT_EVENEMENT_HPP
