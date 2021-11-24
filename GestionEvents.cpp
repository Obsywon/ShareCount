#include "GestionEvents.hpp"
#include "ui_gestionevents.h"

GestionEvents::GestionEvents(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionEvents),
    m_model(m)
{
    ui->setupUi(this);
}

GestionEvents::~GestionEvents()
{
    delete ui;
}

void GestionEvents::on_ajout_event_clicked()
{
    emit addEvent();
}

