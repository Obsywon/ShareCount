#include "GestionGroupes.hpp"
#include "ui_gestiongroupes.h"

GestionGroupes::GestionGroupes(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionGroupes),
    m_model(m)
{
    ui->setupUi(this);
}

GestionGroupes::~GestionGroupes()
{
    delete ui;
}

void GestionGroupes::on_ajout_groupe_clicked()
{
    emit ajoutGroupe();
}


void GestionGroupes::on_b_groupes_clicked()
{
    emit evenement();
}

