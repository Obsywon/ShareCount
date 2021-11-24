#include "AjoutGroupe.hpp"
#include "ui_ajoutgroupe.h"

AjoutGroupe::AjoutGroupe(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjoutGroupe),
    m_model(m)
{
    ui->setupUi(this);
}

AjoutGroupe::~AjoutGroupe()
{
    delete ui;
}

void AjoutGroupe::on_ok_clicked()
{
    emit groupes();
}

