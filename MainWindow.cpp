#include "MainWindow.hpp"
#include "ui_mainwindow.h"

/**
 * Affiche un message sur la console
 * @param msg string à afficher
 */
/*
void print2(const std::string &msg) {
    QString ps = QString();
    ps = QString::fromStdString(msg);
    qDebug("%s", qUtf8Printable(ps));

}*/

MainWindow::MainWindow(Model* m, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_model(m)
{
    ui->setupUi(this);
    Launch* m_launch = new Launch(m_model, this);
    Connect* m_connect = new Connect(m_model, this);
    Inscription* m_inscription = new Inscription(m_model, this);
    GestionGroupes* m_groupes = new GestionGroupes(m_model, this);
    GestionEvents* m_events = new GestionEvents(m_model, this);
    AjoutGroupe* m_addGroup = new AjoutGroupe (m_model, this);
    AjoutEvent* m_addEvent = new AjoutEvent (m_model, this);


    ui->pages->insertWidget(LAUNCH, m_launch);
    ui->pages->insertWidget(CONNECT, m_connect);
    ui->pages->insertWidget(INSCRIPTION, m_inscription);
    ui->pages->insertWidget(GROUPES, m_groupes);
    ui->pages->insertWidget(EVENTS, m_events);
    ui->pages->insertWidget(ADDGROUP, m_addGroup);
    ui->pages->insertWidget(ADDEVENT, m_addEvent);


    connect(m_launch, SIGNAL(inscrire()), this, SLOT(afficherInscription()));
    connect(m_launch, SIGNAL(connecter()), this, SLOT(afficherConnection()));
    connect(m_inscription, SIGNAL(groupes()), this, SLOT(afficherGroupes()));
    connect(m_connect, SIGNAL(groupes()), this, SLOT(afficherGroupes()));
    connect(m_groupes, SIGNAL(ajoutGroupe()), this, SLOT(afficherAjoutGroupe()));
    connect(m_groupes, SIGNAL(evenement()), this, SLOT(afficherEvenement()));
    connect(m_addGroup, SIGNAL(groupes()), this, SLOT(afficherGroupes()));
    connect(m_events, SIGNAL(addEvent()), this, SLOT(afficherAjoutEvent()));
    connect(m_addEvent, SIGNAL(groupes()), this, SLOT(afficherEvenement()));


    changerPage(LAUNCH);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changerPage (int i){
    ui->pages->setCurrentIndex(i);
    ui->pages->currentWidget()->show();
}
void MainWindow::afficherInscription(){
    changerPage(INSCRIPTION);
}

void MainWindow::afficherConnection(){
    changerPage(CONNECT);
}

void MainWindow::afficherGroupes(){
    changerPage(GROUPES);
}

void MainWindow::afficherAjoutGroupe(){
    changerPage(ADDGROUP);
}

void MainWindow::afficherEvenement(){
    changerPage(EVENTS);
}

void MainWindow::afficherAjoutEvent(){
    changerPage(ADDEVENT);
}


