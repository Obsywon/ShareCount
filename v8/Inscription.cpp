#include "Inscription.hpp"
#include "ui_inscription.h"

/**
 * @brief Constructeur de l'interface d'inscription
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
Inscription::Inscription(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inscription),
    m_model(m)
{
    ui->setupUi(this);
}

Inscription::~Inscription()
{
    delete ui;
}
/**
 * @brief réaction au bouton 'inscription'
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
void Inscription::on_inscrire_clicked()
{
    emit groupes();

}

