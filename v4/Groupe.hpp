//
// Created by guy on 09/11/2021.
//

#ifndef SHARECOUNT_GROUPE_HPP
#define SHARECOUNT_GROUPE_HPP
#include <string>



class Groupe {
private:
    std::string m_nom;


public:

    Groupe();
    Groupe(std::string nom);

    std::string toString();
};


#endif //SHARECOUNT_GROUPE_HPP
