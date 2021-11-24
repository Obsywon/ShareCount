#include "AjoutEvent.hpp"
#include "ui_ajoutevent.h"

/**
 * @brief Interface permettant de configurer un événement 
 * à ajouter à un groupe 
 * @param m Model de données
 * @param parent Widget parent
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
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

/**
 * @brief Action permettant de retourner à l'écran des groupes
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
void AjoutEvent::on_ok_event_clicked()
{
    emit groupes();
}

