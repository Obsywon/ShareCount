#include "GestionGroupes.hpp"
#include "ui_gestiongroupes.h"

/**
 * @brief Constructeur de l'interface de gestion de groupes
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 */
GestionGroupes::GestionGroupes(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionGroupes),
    m_model(m)
{
    ui->setupUi(this);
}

GestionGroupes::~GestionGroupes()
{
    delete ui;
}

/**
 * @brief Réaction au bouton d'ajout d'un groupe
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
void GestionGroupes::on_ajout_groupe_clicked()
{
    emit ajoutGroupe();
}

/**
 * @brief Réaction au bouton pour créer un événement
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
void GestionGroupes::on_b_groupes_clicked()
{
    emit evenement();
}

