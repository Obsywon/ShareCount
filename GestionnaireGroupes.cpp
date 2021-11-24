#include "GestionnaireGroupes.hpp"

GestionnaireGroupes::GestionnaireGroupes() {
    m_groupes = std::unordered_map<std::string,Groupe>();
}

void GestionnaireGroupes::ajouterGroupe(std::string nom, const Utilisateur* u) {
    Groupe g = Groupe(nom);
    m_groupes[g.getId()] = g;
}

GestionnaireGroupes& GestionnaireGroupes::getGroupe (std::string idGroupe){
    return reinterpret_cast<GestionnaireGroupes &>(m_groupes.at(idGroupe));
}

std::unordered_map <std::string, Groupe>* GestionnaireGroupes::getTousLesGroupesConnus(){
    return &m_groupes;
}

std::string GestionnaireGroupes::toString() {
    std::string s = "Gestionnaire groupes : \n";

    for (const std::pair<const std::string, Groupe>& it : m_groupes){
        s.append(it.second.toString()).append("\n\n");
    }

    return s;
}

void GestionnaireGroupes::ajouterEvenemenent(std::string idGroupe, std::string nom, std::string dateDeb, std::string dateFin){
    m_groupes[idGroupe].creerEvenement(nom,dateDeb,dateFin);
}

void GestionnaireGroupes::ajoutMembreAGroupe(std::string idGroupe, const Utilisateur *u){
        m_groupes.at(idGroupe).ajouterMembre(u);
}

unsigned long GestionnaireGroupes::taille() {
    return m_groupes.size();
}

std::vector <std::string> GestionnaireGroupes::listeIDs(){
    std::vector <std::string> ids;
    ids.reserve(m_groupes.size());

    for(auto kv : m_groupes) {
        ids.push_back(kv.second.getId());
    }
    return ids;
}

std::vector <std::string> GestionnaireGroupes::listeNoms(){
    std::vector <std::string> ids;
    ids.reserve(m_groupes.size());

    for(auto kv : m_groupes) {
        ids.push_back(kv.second.getNom());
    }
    return ids;
}

