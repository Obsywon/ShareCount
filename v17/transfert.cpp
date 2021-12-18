#include "transfert.hpp"
#include "ui_transfert.h"


/**
 * @brief Interface de génération de transferts pour cagnotte
 * @param m model
 * @param parent
 * @author Guillaume Vautrin
 * @version v17 - ajustement héritage
 */
transfert::transfert(Model* m, QWidget *parent) :
    Page (m, parent),
    ui(new Ui::transfert)
{
    ui->setupUi(this);
}

transfert::~transfert()
{
    delete ui;
}

/**
 * @brief Annule le paiement, retour à l'interface
 * @author Guillaume Vautrin
 * @version v16
 */
void transfert::on_annuler_clicked()
{
    ui->erreur->setText("");
    ui->montant->setText("");
    emit vueCagnotte();
}

/**
 * @brief Effectue un transfert
 * @author Guillaume Vautrin
 * @version v17 - ajustement héritage
 */
void transfert::on_ok_clicked()
{
    bool next = true; // vérifie si les opérations sont à continuer
    double montant = 0;

    ui->erreur->setText("");
    QString valeur = ui->montant->text();
    if (valeur.isEmpty()){
        ui->erreur->setText("Champ vide. Erreur.");
        next = false;
    }

    QRegExp reg("\\d*"); // Vérifie si l'entrée n'est composée que d'entiers
    if (!reg.exactMatch(valeur)){
        ui->erreur->setText("Champ ne doit contenir que des chiffres. Erreur.");
        next = false;
    }

    if (next){
        montant = valeur.toDouble();
        if (ui->retirer->isChecked()){ // Montant sera négatif
            montant = -montant;
        }

        // Transfert a lieu; vérification de l'effectivité du transfert
        if (m_model->transfert(m_groupeID, montant)){
            ui->montant->setText("");
            ui->erreur->setText("");
            emit vueCagnotte();
        }else{
            ui->erreur->setText("Erreur lors du transfert. Vérifier la valeur.");
        }
    }
}

