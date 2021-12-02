#include "GestionEvents.hpp"
#include "ui_gestionevents.h"

/**
 * @brief Constructeur de l'interface de gestion d'événements dans un groupe
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
GestionEvents::GestionEvents(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionEvents),
    m_model(m),
    m_groupeId(-1)
{
    ui->setupUi(this);
}

GestionEvents::~GestionEvents()
{
    delete ui;
}

/**
 * Attribue l'identifiant d'un groupe
 * @param id identifiant
 * @author Guillaume Vautrin
 * @version v9 (Ajout)
 */
void GestionEvents::setIdGroupe(const int& id){
    m_groupeId = id;
}


/**
 * @brief Affiche les evenements d'un groupe
 * @authors Louis Jacques
 * @version v9 (Dernière modification)
 */
void GestionEvents::afficherEvent(Model* m){
    ui->listEvent->clear();
    std::unordered_map<int, Evenement> * hashMap = m->getTousLesEvenementsConnus(m_groupeId);
        for(auto const& key : *hashMap){
            std::cout << key.first;
            std::string nom = key.second.getNom();
            QString qString = QString::fromStdString(nom);
            ui->listEvent->addItem(qString);
        }
}

/**
 * @brief Réaction à un clique pour ajouter un événement :
 * Déclenche l'envoi d'un signal vers la fenêtre principale 
 * pour afficher l'écran d'ajout d'événement
 * @author Guillaume Vautrin
 * @version v9 (Dernière modification)
 */
void GestionEvents::on_ajout_event_clicked()
{
    emit addEvent(m_groupeId);
}

/**
 * Permet le retour aux groupes groupe
 * @author Guillaume Vautrin
 * @version v9 (Ajout)
 */
void GestionEvents::on_retour_groupes_clicked()
{
    emit groupes();
}

