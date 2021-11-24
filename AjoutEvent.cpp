#include "AjoutEvent.hpp"
#include "ui_ajoutevent.h"

AjoutEvent::AjoutEvent(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjoutEvent)
{
    ui->setupUi(this);
}

AjoutEvent::~AjoutEvent()
{
    delete ui;
}

void AjoutEvent::on_ok_event_clicked()
{
    emit groupes();
}

