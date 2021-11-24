#include "Launch.hpp"
#include "ui_launch.h"

Launch::Launch(Model* m, QWidget *parent) :  QWidget(parent), ui(new Ui::Launch), m_model (m)
{
    ui->setupUi(this);
}

Launch::~Launch()
{
    delete ui;
}

/**
 * @brief Récepteur du bouton 's'inscrire'
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
void Launch::on_sinscrire_clicked()
{
    emit inscrire();
}

/**
 * @brief Récepteur du bouton 'se connecter
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
void Launch::on_seconnecter_clicked()
{
    emit connecter();

}

