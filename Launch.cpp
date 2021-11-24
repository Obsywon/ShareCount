#include "Launch.hpp"
#include "ui_launch.h"

Launch::Launch(Model* m, QWidget *parent) :  QWidget(parent), ui(new Ui::Launch), m_model (m)
{
    ui->setupUi(this);
}

Launch::~Launch()
{
    delete ui;
}

void Launch::on_sinscrire_clicked()
{
    emit inscrire();
}


void Launch::on_seconnecter_clicked()
{
    emit connecter();

}

