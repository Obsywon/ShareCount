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
 * @param m model
 * @authors Louis Jacques
 * @version v12 (Dernière modification)
 */
void gestionComptes::afficherComptes(Model* m){
    m_model->updateMembers(m_groupeID);

    ui->listParticipants->clear();
    std::vector<Utilisateur> * arrayList = m->getTousLesParticipantsConnus(m_groupeID);
    for (Utilisateur &u : *arrayList){
        std::string str = u.getPseudo();
        QString qstring = QString::fromStdString(str);
        ui->listParticipants->addItem(qstring);
    }
}

/**
 * @brief set l'ID d'un groupe
 * @param id identifiant du groupe
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
 * @version v15 (Dernière modification) retire id groupe des paramètres
 */
void gestionComptes::on_events_4_clicked()
{
    emit vueEvent();
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

/**
 * @brief demande l'invitation et retourne à fenetre événement si possible
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
void gestionComptes::on_inviter_clicked()
{
    emit vueInvit();
}

/**
 * @brief Demande la page cagnotte
 * @author Guillaume Vautrin
 * @version v16 (Dernière modification)
 */
void gestionComptes::on_cagnotte_4_clicked()
{
    emit vueCagnotte();
}

