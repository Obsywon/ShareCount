#include "MainWindow.hpp"
#include "ui_mainwindow.h"


MainWindow::MainWindow(Model* m, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_model(m)
{
    ui->setupUi(this);


    // Génération des interfaces
    m_launch = new Launch(m_model, this);
    m_connection = new Connect(m_model, this);
    m_inscription = new Inscription(m_model, this);
    m_groupes = new GestionGroupes(m_model, this);
    m_events = new GestionEvents(m_model, this);
    m_addGroup = new AjoutGroupe (m_model, this);
    m_addEvent = new AjoutEvent (m_model, this);
    m_comptes = new gestionComptes(m_model,this);
    m_invit = new inviter(m_model, this);
    m_cagnotte = new cagnotte(m_model, this);
    m_transfert = new transfert(m_model, this);


    // Insertion des interfaces dans la collection de la fenêtre principale
    ui->pages->insertWidget(LAUNCH, m_launch);
    ui->pages->insertWidget(CONNECT, m_connection);
    ui->pages->insertWidget(INSCRIPTION, m_inscription);
    ui->pages->insertWidget(GROUPES, m_groupes);
    ui->pages->insertWidget(EVENTS, m_events);
    ui->pages->insertWidget(ADDGROUP, m_addGroup);
    ui->pages->insertWidget(ADDEVENT, m_addEvent);
    ui->pages->insertWidget(COMPTES, m_comptes);
    ui->pages->insertWidget(INVITER, m_invit);
    ui->pages->insertWidget(CAGNOTTE, m_cagnotte);
    ui->pages->insertWidget(TRANSFERT, m_transfert);


    // Signaux / slots permettant de changer d'interface
    connect(m_launch, SIGNAL(inscrire()), this, SLOT(afficherInscription()));
    connect(m_launch, SIGNAL(connecter()), this, SLOT(afficherConnection()));
    connect(m_inscription, SIGNAL(groupes()), this, SLOT(afficherGroupes()));
    connect(m_inscription, SIGNAL(connecter()), this, SLOT(afficherConnection()));
    connect(m_connection, SIGNAL(groupes()), this, SLOT(afficherGroupes()));
    connect(m_connection, SIGNAL(inscrire()), this, SLOT(afficherInscription()));
    connect(m_groupes, SIGNAL(ajoutGroupe()), this, SLOT(afficherAjoutGroupe()));
    connect(m_groupes, SIGNAL(evenements(int)), this, SLOT(afficherEvenement(int)));
    connect(m_addGroup, SIGNAL(groupes()), this, SLOT(afficherGroupes()));
    connect(m_events, SIGNAL(addEvent()), this, SLOT(afficherAjoutEvent()));
    connect(m_events, SIGNAL(groupes()), this, SLOT(afficherGroupes()));
    connect(m_addEvent, SIGNAL(evenements()), this, SLOT(afficherEvenement()));
    connect(m_events, SIGNAL(vueCompte()),this,SLOT(afficherComptes()));
    connect(m_comptes,SIGNAL(vueEvent()), this, SLOT(afficherEvenement()));
    connect(m_comptes,SIGNAL(vueGroupe()), this, SLOT(afficherGroupes()));

    connect (m_comptes, SIGNAL(vueInvit()), this, SLOT(afficherInvit()));
    connect (m_invit, SIGNAL(annuler()), this, SLOT(afficherComptes()));
    connect (m_invit, SIGNAL(comptes()), this, SLOT(afficherComptes()));

    connect (m_comptes, SIGNAL(vueCagnotte()), this, SLOT(afficherCagnotte()));
    connect (m_events, SIGNAL(vueCagnotte()), this, SLOT(afficherCagnotte()));
    connect (m_cagnotte, SIGNAL(vueTransfert()), this, SLOT(afficherTransaction()));

    connect (m_cagnotte, SIGNAL(vueComptes()), this, SLOT(afficherComptes()));
    connect (m_cagnotte, SIGNAL(vueEvent()), this, SLOT(afficherEvenement()));
    connect (m_cagnotte, SIGNAL(vueGroupes()), this, SLOT(afficherGroupes()));

    connect (m_transfert, SIGNAL(vueCagnotte()), this, SLOT(afficherCagnotte()));

    // Afficher le choix entre se connecter et s'inscrire
    changerPage(LAUNCH);
}

MainWindow::~MainWindow()
{
    delete ui;
}
    /**
     * @brief Affiche l'interface indiqué
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
void MainWindow::changerPage (int i){
    ui->pages->setCurrentIndex(i);
    ui->pages->currentWidget()->show();
}

    /**
     * @brief Affiche l'inscription
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
void MainWindow::afficherInscription(){
    changerPage(INSCRIPTION);
}

    /**
     * @brief Affiche la connection
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
void MainWindow::afficherConnection(){
    changerPage(CONNECT);
}
    /**
     * @brief Affiche les groupes
     * @author Guillaume Vautrin , Louis Jacques
     * @version v9 (Dernière modification)
     */
void MainWindow::afficherGroupes(){
    m_model->updateGroupes();
    m_groupes->afficherGroupe(m_model);
    changerPage(GROUPES);
}

    /**
     * @brief AFfiche l'ajout de groupes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
void MainWindow::afficherAjoutGroupe(){
    changerPage(ADDGROUP);
}

/**
 * @brief Affiche les événements
 * @param id du groupe auquel appartient l'événement
 * @author Guillaume Vautrin , Louis Jacques
 * @version v16 (Dernière modification) - ajout transfert / cagnotte
 */
void MainWindow::afficherEvenement(int id){
    // Paramètre toutes les interfaces suivantes avec cet identifiant
    m_events->setIdGroupe(id);
    m_comptes->setIDGroupe(id);
    m_invit->setGroupe(id);
    m_addEvent->setIdGroupe(id);
    m_cagnotte->setGroupeId(id);
    m_transfert->setGroupeId(id);
    // affiche les événements connus
    m_events->afficherEvent();
    changerPage(EVENTS);
}


/**
 * @brief Affiche les événements
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
void MainWindow::afficherEvenement(){
    // Paramètre toutes les interfaces suivantes avec cet identifiant
    m_events->afficherEvent();
    changerPage(EVENTS);
}

/**
 * @brief Affiche les Comptes
 * @author Louis Jacques
 * @version v15 (Dernière modification) retire id groupe des paramètres
 */
void MainWindow::afficherComptes(){
    m_comptes->afficherComptes(m_model);
    changerPage(COMPTES);
}


/**
 * @brief Affiche l'ajout d'événements
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification) retire id groupe des paramètres
 */
void MainWindow::afficherAjoutEvent(){
    changerPage(ADDEVENT);
}

/**
 * @brief Affiche la fenêtre d'invitation
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
void MainWindow::afficherInvit (){
    changerPage(INVITER);
}

/**
 * @brief Affiche la fenêtre de cagnotte
 * @author Guillaume Vautrin
 * @version v16 (Dernière modification)
 */
void MainWindow::afficherCagnotte (){
    m_cagnotte->updateHistorique();
    changerPage(CAGNOTTE);

}

/**
 * @brief Affiche la fenêtre de transaction
 * @author Guillaume Vautrin
 * @version v16 (Dernière modification)
 */
void MainWindow::afficherTransaction(){
    changerPage(TRANSFERT);

}



