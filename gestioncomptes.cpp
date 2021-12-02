#include "gestioncomptes.hpp"
#include "ui_gestioncomptes.h"

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

void gestionComptes::afficherComptes(Model* m){
    ui->listParticipants->clear();
    std::vector<Utilisateur> * arrayList = m->getTousLesParticipantsConnus(m_groupeID);
        for(int i =0;i<arrayList->size();i++){
            std::string str =arrayList->at(i).getPseudo();
            QString qstring = QString::fromStdString(str);
            ui->listParticipants->addItem(qstring);
        }
}

void gestionComptes::on_ajout_event_clicked()
{
    emit addEvent(m_groupeID);
}

void gestionComptes::setIDGroupe(const int& id)
{
    m_groupeID = id;
}

