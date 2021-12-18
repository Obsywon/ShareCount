#include "GestionEvents.hpp"
#include "ui_gestionevents.h"

/**
 * @brief Constructeur de l'interface de gestion d'événements dans un groupe
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 * @author Guillaume Vautrin
 * @version v17 (Dernière modification)
 */
GestionEvents::GestionEvents(Model* m, QWidget *parent) :
    Page (m, parent),
    ui(new Ui::GestionEvents)
{
    ui->setupUi(this);
}

GestionEvents::~GestionEvents()
{
    delete ui;
}


/**
 * @brief Affiche les evenements d'un groupe
 * @authors Louis Jacques
 * @version v7 (Dernière modification)
 */
void GestionEvents::update(){
    ui->listEvent->clear();
    std::unordered_map<int, Evenement> * hashMap = m_model->getTousLesEvenementsConnus(m_groupeID);

    for(auto const& key : *hashMap){
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
    emit addEvent();
}

/**
 * Permet le retour aux groupes groupe
 * @author Guillaume Vautrin
 * @version v9 (Ajout)
 */
void GestionEvents::on_retour_groupes_clicked()
{
    emit vueGroupe();
}

/**
 * Permet l'acces aux participants
 * @author Louis Jacques
 * @version v12 (Ajout)
 */
void GestionEvents::on_participants_4_clicked()
{
    emit vueCompte();
}

/**
 * @brief Demande la page cagnotte
 * @author Guillaume Vautrin
 * @version v16 (Dernière modification)
 */
void GestionEvents::on_cagnotte_4_clicked()
{
    emit vueCagnotte();
}

