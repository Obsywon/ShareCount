//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_GROUPE_HPP
#define SHARECOUNT_GROUPE_HPP
#include <string>


/**
* @brief Groupe
* @author Guillaume Vautrin
* @version v3
*/
class Groupe {
private:
    std::string m_nom;


public:
/**
* @brief Groupe
* @author Guillaume Vautrin
* @version v3
*/
    Groupe();

    /**
* @brief Groupe
 * @param nom
* @author Guillaume Vautrin
* @version v3
*/
    Groupe(std::string nom);
/**
* @brief décris un groupe
 * @return string
* @author Guillaume Vautrin
* @version v3
*/
    std::string toString();
};


#endif //SHARECOUNT_GROUPE_HPP
