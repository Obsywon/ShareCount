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
    ui(new Ui::AjoutEvent),
    m_model(m)

{
    ui->setupUi(this);
}

AjoutEvent::~AjoutEvent()
{
    delete ui;
}

/**
 * @brief Action permettant de retourner à l'écran des groupes
 * @author Guillaume Vautrin , Louis Jacques
 * @version v9 (Dernière modification)
 */
void AjoutEvent::on_ok_event_clicked()
{
    QDate deb = ui->dateDeb_2->date();
    QDate fin = ui->dateFin_2->date();
    QString d = deb.toString("yyyy-MM-dd 00:00:01");
    QString f = fin.toString("yyyy-MM-dd 00:00:02");
    QString nom = ui->nom_event_2->text();
    m_model->creerEvenement(1, nom.toStdString(), d.toStdString(), f.toStdString());
    emit groupes();
}

