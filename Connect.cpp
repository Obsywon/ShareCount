#include "Connect.hpp"
#include "ui_connect.h"

/**
 * @brief Constructeur de l'interface de connexion
 * Permet à un utilisateur de se connecter
 * Alterne le modèle pour permettre la connection, 
 * si l'utilisateur est reconnu
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
Connect::Connect(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connect),
    m_model (m)

{
    ui->setupUi(this);
}

Connect::~Connect()
{
    delete ui;
}

/**
 * @brief Vérifie l'existence du compte renseigné et effectue, si possible
 * la connexion. Envoie vers l'écran de gestion des groupes
 * @author Guillaume Vautrin
 * @version v9 (Dernière modification) : ajout base de données
 */
void Connect::on_connecter_clicked()
{
    QString QMdp = ui->co_mdp->text();
    QString QPseudo = ui->co_pseudo->text();
    QString error = QString("Erreur : ");
    if (QPseudo.isEmpty() || QMdp.isEmpty()){
        error.append("Champs vides. ");
        ui->co_err->setText(error);
        ui->co_err->setVisible(true);
    }else{
        ui->co_err->setVisible(false);
        bool connect = m_model->compteExiste(QPseudo.toStdString(), QMdp.toStdString());
        if (connect){
            m_model->connecterUtilisateur(QPseudo.toStdString(), "" ,QMdp.toStdString());
            //print2(m_model->toString());
            emit groupes();

        }else{
            error.append("Erreur lors de la connection.");
            ui->co_err->setText(error);
            ui->co_err->setVisible(true);
        }
    }

}

