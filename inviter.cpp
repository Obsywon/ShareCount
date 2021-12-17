#include "inviter.hpp"
#include "ui_inviter.h"


/**
 * @brief demande l'invitation d'un individu au groupe
 * @param m model
 * @param fenêtre parente
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
inviter::inviter(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inviter),
    m_model(m), id_groupe(-1)
{
    ui->setupUi(this);
}

inviter::~inviter()
{
    delete ui;
}
/**
 * @brief attribue l'identifiant du groupe à modifier
 * @param id du groupe
 * @author Guillaume Vautrin
 * @version v15
 */
void inviter::setGroupe(int id){
    id_groupe = id;
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

       bool success = m_model->addMember(id_groupe, pseudo.toStdString());
       if (success){
           m_model->updateMembers(id_groupe);
            emit comptes();
       }else{
           ui->erreur->setText("Erreur : pseudo introuvable");
       }
   }
}

