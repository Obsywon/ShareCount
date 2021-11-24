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
        m_model (m),
        QWidget(parent),
        ui(new Ui::AjoutGroupe)
{
    ui->setupUi(this);
}

AjoutGroupe::~AjoutGroupe()
{
    delete ui;
}

void AjoutGroupe::on_ok_clicked()
{
    emit groupes();
}

