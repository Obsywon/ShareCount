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
    /**
 * @brief Génère un événement
 * @version v4
 * @author Guillaume Vautrin
 */
    Evenement();
/**
 * @brief Génère un événement
 * @param dateFin date de fin
 * @param dateDeb date de début
 * @param nom nom de l'événement
 * @version v6
 * @author Guillaume Vautrin
 */
    Evenement(std::string nom, std::string dateDeb, std::string dateFin);


/**
 * @brief Génère une description d'un événément
 * @return string
 * @version v4
 * @author Guillaume Vautrin
 */
    std::string toString();
};


#endif //SHARECOUNT_EVENEMENT_HPP
