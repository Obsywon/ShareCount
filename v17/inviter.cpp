#include "inviter.hpp"
#include "ui_inviter.h"


/**
 * @brief demande l'invitation d'un individu au groupe
 * @param m model
 * @param fenêtre parente
 * @author Guillaume Vautrin
 * @version v17 - ajustement héritage
 */
inviter::inviter(Model* m, QWidget *parent) :
    Page (m, parent),
    ui(new Ui::inviter)
{
    ui->setupUi(this);
}

inviter::~inviter()
{
    delete ui;
}


/**
 * @brief demande l'annulation
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
void inviter::on_annuler_clicked()
{
    ui->pseudo_invit->setText("");
    ui->erreur->setText("");
    emit annuler();
}

/**
 * @brief demande l'invitation d'un individu au groupe
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
void inviter::on_ok_clicked()
{
    ui->erreur->setText("");
   QString pseudo = ui->pseudo_invit->text();

   if (pseudo.isEmpty()){
       ui->erreur->setText("Pseudo manquant");
   }else {

       bool success = m_model->addMember(m_groupeID, pseudo.toStdString());
       if (success){
           m_model->updateMembers(m_groupeID);
            emit vueCompte();
       }else{
           ui->erreur->setText("Erreur : pseudo introuvable");
       }
   }
}

