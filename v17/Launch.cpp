#include "Launch.hpp"
#include "ui_launch.h"

/**
 * @brief Lancement de l'application
 * @param m Model
 * @param parent
 * @version v17 - ajustement héritage
 */
Launch::Launch(Model* m, QWidget *parent) : Page(m, parent), ui(new Ui::Launch)
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

