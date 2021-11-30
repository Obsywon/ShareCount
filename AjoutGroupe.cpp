#include "AjoutGroupe.hpp"
#include "ui_ajoutgroupe.h"

/**
 * @brief Constructeur de l'interface permettant l'ajout d'un groupe
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
AjoutGroupe::AjoutGroupe(Model* m, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::AjoutGroupe),
        m_model (m)
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
    emit groupes();
}

