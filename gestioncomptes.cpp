#include "gestioncomptes.hpp"
#include "ui_gestioncomptes.h"

/**
 * @brief Constructeur de l'interface de gestion de Comptes dans un groupe
 *
 * @param m Modèle de données
 * @param parent Fenêtre principale
 * @author Louis Jacques
 * @version v12 (Dernière modification)
 */
gestionComptes::gestionComptes(Model* m,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestionComptes),
    m_model(m),
    m_groupeID(-1)
{
    ui->setupUi(this);
}

gestionComptes::~gestionComptes()
{
    delete ui;
}


/**
 * @brief Affiche les participants d'un groupe
 * @authors Louis Jacques
 * @version v12 (Dernière modification)
 */
void gestionComptes::afficherComptes(Model* m){
    ui->listParticipants->clear();
    std::vector<Utilisateur> * arrayList = m->getTousLesParticipantsConnus(m_groupeID);
        for(int i =0;i<arrayList->size();i++){
            std::string str =arrayList->at(i).getPseudo();
            QString qstring = QString::fromStdString(str);
            ui->listParticipants->addItem(qstring);
        }
}

/**
 * @brief set l'ID d'un groupe
 * @authors Louis Jacques
 * @version v12 (Dernière modification)
 */
void gestionComptes::setIDGroupe(const int& id)
{
    m_groupeID = id;
}

/**
 * @brief permet l'acces aux evenements
 * @authors Louis Jacques
 * @version v12 (Dernière modification)
 */
void gestionComptes::on_events_4_clicked()
{
    emit vueEvent(m_groupeID);
}


/**
 * @brief permet le retour aux groupes
 * @authors Louis Jacques
 * @version v12 (Dernière modification)
 */
void gestionComptes::on_retour_groupes_clicked()
{
    emit vueGroupe();
}

