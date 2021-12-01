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
        QString nom = ui->nom_event_2->text();

        QString dateDeb = deb.toString("yyyy-MM-dd hh:mm:ss");
        QString dateFin = fin.toString("yyyy-MM-dd hh:mm:ss");
        m_model->creerEvenement(0, nom.toStdString(), dateDeb.toStdString(), dateFin.toStdString());
        emit groupes();
}

