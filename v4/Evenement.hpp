//
// Created by guy on 11/11/2021.
//

#ifndef SHARECOUNT_EVENEMENT_HPP
#define SHARECOUNT_EVENEMENT_HPP
#include <string>
#include <utility>
/**
 * @brief Génère un événement
 * @version v4
 * @author Guillaume Vautrin
 */
class Evenement {

private:

    /**
 * @brief nom de l'événement
 * @version v4
 * @author Guillaume Vautrin
 */
    std::string m_nom;

    /**
 * @brief Date de début
 * @version v4
 * @author Guillaume Vautrin
 */
    std::string m_dateDeb;

    /**
 * @brief Date de fin
 * @version v4
 * @author Guillaume Vautrin
 */
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
 * @version v4
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
