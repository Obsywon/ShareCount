#ifndef SHARECOUNT_GESTIONNAIREGROUPES_HPP
#define SHARECOUNT_GESTIONNAIREGROUPES_HPP

#include <vector>
#include "Groupe.hpp"

class Utilisateur;

class GestionnaireGroupes {
private:
    /**
 * @brief liste de groupes
 * @version v3
 * @author Guillaume Vautrin
 */
    std::vector<Groupe> m_groupes;

    /**
 * @brief Utilisateur
 * @version v3
 * @author Guillaume Vautrin
 */
    Utilisateur* user;

public:
/**
* @brief Gère les groupes
* @version v3
* @author Guillaume Vautrin
*/
    GestionnaireGroupes();

/**
* @brief ajoute un groupe
* @version v3
* @author Guillaume Vautrin
*/
    void ajouterGroupe (std::string nom, const Utilisateur* u) ;

    /**
 * @brief description des groupes connus
 * @return string
 * @version v3
 * @author Guillaume Vautrin
 */
    std::string toString();
};


#endif //SHARECOUNT_GESTIONNAIREGROUPES_HPP
