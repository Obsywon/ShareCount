//
// Created by guy on 09/11/2021.
//

#include "Groupe.hpp"

Groupe::Groupe() : m_nom(""){
}

Groupe::Groupe(std::string nom):m_nom(nom) {
}

std::string Groupe::toString() {
    std::string s = m_nom;
    return s;
}
