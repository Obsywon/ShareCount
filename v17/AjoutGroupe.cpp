#include "AjoutGroupe.hpp"
#include "ui_ajoutgroupe.h"

/**
 * @brief Constructeur de l'interface permettant l'ajout d'un groupe
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 * @author Guillaume Vautrin
 * @version v17 (Dernière modification) Ajustement héritage
 */
AjoutGroupe::AjoutGroupe(Model* m, QWidget *parent) :
        Page (m, parent),
        ui(new Ui::AjoutGroupe)
{
    ui->setupUi(this);
}

AjoutGroupe::~AjoutGroupe()
{
    delete ui;
}

/**
 * @brief déclenche l'ajout d'un groupe dans le modèle et le passage vers la gestion des groupes
  * @authors Guillaume Vautrin
 * @version v9 (Dernière modification)
 */
void AjoutGroupe::on_ok_clicked()
{
    QString nom = ui->nom_groupe->text();
    m_model->creerGroupe(nom.toStdString());
    ui->nom_groupe->setText("");
    emit vueGroupe();
}

/**
* @brief déclenche l'annulation et le retour vers la gestion des groupes
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
void AjoutGroupe::on_annuler_clicked()
{
    ui->nom_groupe->setText("");
    emit vueGroupe();

}

