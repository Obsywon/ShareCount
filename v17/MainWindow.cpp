#include "MainWindow.hpp"
#include "ui_mainwindow.h"

/**
 * @brief Fenêtre principal concentrant l'interaction entre les interfaces et l'utilisateurs
 * @param m model
 * @param parent
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v17 - Ajustement héritage
 */
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
    connect(m_inscription, SIGNAL(vueGroupe()), this, SLOT(afficherGroupes()));
    connect(m_inscription, SIGNAL(connecter()), this, SLOT(afficherConnection()));
    connect(m_connection, SIGNAL(vueGroupe()), this, SLOT(afficherGroupes()));
    connect(m_connection, SIGNAL(inscrire()), this, SLOT(afficherInscription()));
    connect(m_groupes, SIGNAL(ajoutGroupe()), this, SLOT(afficherAjoutGroupe()));
    connect(m_groupes, SIGNAL(vueEvent(int)), this, SLOT(afficherEvenement(int)));
    connect(m_addGroup, SIGNAL(vueGroupe()), this, SLOT(afficherGroupes()));
    connect(m_events, SIGNAL(addEvent()), this, SLOT(afficherAjoutEvent()));
    connect(m_events, SIGNAL(vueGroupe()), this, SLOT(afficherGroupes()));
    connect(m_addEvent, SIGNAL(vueEvent()), this, SLOT(afficherEvenement()));
    connect(m_events, SIGNAL(vueCompte()),this,SLOT(afficherComptes()));
    connect(m_comptes,SIGNAL(vueEvent()), this, SLOT(afficherEvenement()));
    connect(m_comptes,SIGNAL(vueGroupe()), this, SLOT(afficherGroupes()));

    connect (m_comptes, SIGNAL(vueInvit()), this, SLOT(afficherInvit()));
    connect (m_invit, SIGNAL(annuler()), this, SLOT(afficherComptes()));
    connect (m_invit, SIGNAL(vueCompte()), this, SLOT(afficherComptes()));

    connect (m_comptes, SIGNAL(vueCagnotte()), this, SLOT(afficherCagnotte()));
    connect (m_events, SIGNAL(vueCagnotte()), this, SLOT(afficherCagnotte()));
    connect (m_cagnotte, SIGNAL(vueTransfert()), this, SLOT(afficherTransaction()));

    connect (m_cagnotte, SIGNAL(vueCompte()), this, SLOT(afficherComptes()));
    connect (m_cagnotte, SIGNAL(vueEvent()), this, SLOT(afficherEvenement()));
    connect (m_cagnotte, SIGNAL(vueGroupe()), this, SLOT(afficherGroupes()));

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
     * @authors Guillaume Vautrin, Louis Jacques
     * @version v17 (Dernière modification) - Ajustement héritage
     */
void MainWindow::afficherGroupes(){
    m_model->updateGroupes();
    m_groupes->update();
    changerPage(GROUPES);
}

    /**
     * @brief Affiche l'ajout de groupes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
void MainWindow::afficherAjoutGroupe(){
    changerPage(ADDGROUP);
}

/**
 * @brief Affiche les événements
 * @param id du groupe auquel appartient l'événement
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v17 (Dernière modification) - ajustement héritage
 */
void MainWindow::afficherEvenement(int id){
    // Paramètre toutes les interfaces suivantes avec cet identifiant
    m_events->setIDGroupe(id);
    m_comptes->setIDGroupe(id);
    m_invit->setIDGroupe(id);
    m_addEvent->setIDGroupe(id);
    m_cagnotte->setIDGroupe(id);
    m_transfert->setIDGroupe(id);
    // affiche les événements connus
    m_events->update();
    changerPage(EVENTS);
}


/**
 * @brief Affiche les événements
 * @author  Vautrin Guillaume
 * @version v17 (Dernière modification) - Ajustement héritage
 */
void MainWindow::afficherEvenement(){
    // Paramètre toutes les interfaces suivantes avec cet identifiant
    m_events->update();
    changerPage(EVENTS);
}

/**
 * @brief Affiche les Comptes
 * @authors Louis Jacques, Vautrin Guillaume
 * @version v17 (Dernière modification) - Ajustement héritage
 */
void MainWindow::afficherComptes(){
    m_comptes->update();
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
 * @version v17 (Dernière modification) - ajustement héritage
 */
void MainWindow::afficherCagnotte (){
    m_cagnotte->update();
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



