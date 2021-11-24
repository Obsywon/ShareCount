#include "Inscription.hpp"
#include "ui_inscription.h"

Inscription::Inscription(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inscription),
    m_model(m)
{
    ui->setupUi(this);
}

Inscription::~Inscription()
{
    delete ui;
}

void Inscription::on_inscrire_clicked()
{
    emit groupes();

}

