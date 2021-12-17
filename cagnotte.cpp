#include "cagnotte.hpp"
#include "ui_cagnotte.h"

cagnotte::cagnotte(Model *m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cagnotte),
    m_model(m)
{
    ui->setupUi(this);
}

cagnotte::~cagnotte()
{
    delete ui;
}

/**
 * @brief identifie le groupe
 * @param id identifiant
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v16
 */
void cagnotte::setGroupeId(const int& id){
    m_id = id;
}

/**
 * @brief Met à jour l'historique des transferts
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v16
 */
void cagnotte::updateHistorique(){
    const std::unordered_map <std::string, double> historique = m_model->updateHistorique(m_id);
    ui->historique->clear();

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
    emit vueComptes();
}

/**
 * @brief Demande l'affichage des groupes
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v16
 */
void cagnotte::on_retour_groupes_clicked()
{
    emit vueGroupes();
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

