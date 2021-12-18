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
    m_model(m),
    m_idGroupe(-1)

{
    ui->setupUi(this);
}

AjoutEvent::~AjoutEvent()
{
    delete ui;
}

/**
 * @brief Action permettant de retourner à l'écran des groupes après ajout d'un événement
 * @author Guillaume Vautrin , Louis Jacques
 * @version v9 (Dernière modification)
 */
void AjoutEvent::on_ok_event_clicked()
{
    QDate deb = ui->dateDeb_2->date();
    QDate fin = ui->dateFin_2->date();
    QLineEdit *nom = ui->nom_event_2;

    if (!deb.isValid() || !fin.isValid() || deb.isNull() || fin.isNull() || nom->text().isEmpty()){
        ui->erreur->setText("Date(s) ou nom invalide(s)/vide(s)...");
    }

    if (deb<fin){ // Si la date de début de l'évenement est inférieur on continue l'opération d'ajout
        QString d = deb.toString("yyyy-MM-dd 00:00:01");
        QString f = fin.toString("yyyy-MM-dd 00:00:02");
        QString nom = ui->nom_event_2->text();
        m_model->creerEvenement(m_idGroupe, nom.toStdString(), d.toStdString(), f.toStdString());

        // Remise à zéro des champs:
        reset();
        emit evenements();
    }else{ // Sinon on bloque en expliquant l'erreur
        ui->erreur->setText("La date de fin doit être plus récente que l'autre.");
    }
}

/**
 * @brief Annule l'ajout
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
void AjoutEvent::on_annuler_clicked()
{
    reset();
    emit evenements();

}

void AjoutEvent::reset(){
    // Remise à zéro des champs:
    ui->dateDeb_2->date().setDate(2000, 1, 1);
    ui->dateFin_2->date().setDate(2000, 1, 1);
    ui->nom_event_2->setText("");
    ui->erreur->setText("");
}

void AjoutEvent::setIdGroupe(int id){
   m_idGroupe = id;
}

