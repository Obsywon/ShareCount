#include "Evenement.hpp"

Evenement::Evenement() = default;

Evenement::Evenement(std::string nom, std::string dateDeb, std::string dateFin): m_nom(std::move(nom)), m_dateDeb(std::move(dateDeb)), m_dateFin(std::move(dateFin)) {

}

std::string Evenement::toString() {
    std::string temp = m_nom;
    temp.append(" ").append(m_dateDeb).append(" - ").append(m_dateFin);
    return temp;
}


