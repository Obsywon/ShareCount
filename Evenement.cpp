//
// Created by guy on 11/11/2021.
//

#include "Evenement.hpp"

Evenement::Evenement(): m_nom(""), m_dateDeb(""), m_dateFin("") {

}
Evenement::Evenement(std::string nom, std::string dateDeb, std::string dateFin): m_nom(nom), m_dateDeb(dateDeb), m_dateFin(dateFin){
}

std::string Evenement::toString() {
    return std::string();
}
