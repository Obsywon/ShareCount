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
    m_model(m)
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

