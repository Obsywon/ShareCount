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
    Evenement(std::string nom, std::string dateDeb, std::string dateFin);


    std::string toString();
};


#endif //SHARECOUNT_EVENEMENT_HPP
