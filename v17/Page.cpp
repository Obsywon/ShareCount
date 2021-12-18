#include "Page.hpp"

/**
 * @brief Classe mère rassemblant les points communs entre les différentes interfaces (et signaux)
 * @param m model
 * @param parent
 * @author Guillaume Vautrin
 * @version v17
 */
Page::Page(Model* m,QWidget *parent) : QWidget(parent), m_model(m)
{}

/**
 * @brief set l'ID d'un groupe
 * @param id identifiant du groupe
 * @author Guillaume Vautrin
 * @version v16 (Dernière modification)
 */
void Page::setIDGroupe(const int& id)
{
    m_groupeID = id;
}

/**
 * @brief Met à jour l'interface
 * @author Guillaume Vautrin
 * @version v17
 */
void Page::update(){

}
