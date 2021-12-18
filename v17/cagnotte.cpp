#include "cagnotte.hpp"
#include "ui_cagnotte.h"


/**
 * @brief Gestion de la cagnotte (interface)
 * @param m Model
 * @param parent
 * @author Guillaume Vautrin
 * @version v17 - ajustement héritage
 */
cagnotte::cagnotte(Model *m, QWidget *parent) :
    Page (m, parent),
    ui(new Ui::cagnotte)
{
    ui->setupUi(this);
}

cagnotte::~cagnotte()
{
    delete ui;
}

/**
 * @brief Met à jour l'historique des transferts
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v17 - ajustement héritage
 */
void cagnotte::update(){
    const std::vector <std::pair <std::string, double>> historique = m_model->updateHistorique(m_groupeID);
    ui->historique->clear();

    double sommeActu = m_model->getTotalCagnotte(m_groupeID);
    QString texte = "Votre cagnotte s'élève à ";
    texte.append(QString::number(sommeActu));
    texte.append("€");
    ui->txtsum->setText(texte);


    if (historique.size() > 0){
        std::string pseudo;
        double montant = 0;
        QString temp, qString;
        for(auto const& key : historique){
            pseudo = key.first;
            montant = key.second;

            qString = QString::fromStdString(pseudo.append("     "));
            temp = QString::number(montant);
            qString.append(temp);
            qString.append("€");
            ui->historique->addItem(qString);
        }
    }
}


/**
 * @brief Demande l'affichage des événements
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v16
 */
void cagnotte::on_events_clicked()
{
    emit vueEvent();
}

/**
 * @brief Demande l'affichage des participants
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v16
 */
void cagnotte::on_participants_clicked()
{
    emit vueCompte();
}

/**
 * @brief Demande l'affichage des groupes
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v16
 */
void cagnotte::on_retour_groupes_clicked()
{
    emit vueGroupe();
}

/**
 * @brief Demande l'affichage des transferts
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v16
 */
void cagnotte::on_ajout_transfert_clicked()
{
    emit vueTransfert();
}

