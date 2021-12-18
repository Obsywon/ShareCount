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
    QTableWidget *table = ui->historique; // Récupération pointeur vers table

    // Reset table
    table->clear();
    QStringList header = QStringList(); // Prépare le header
    header.append("Pseudo");
    header.append("Montant");
    table->setHorizontalHeaderLabels(header);

    // Récupération de la valeur total de la cagnotte du groupe et affichage
    double sommeActu = m_model->getTotalCagnotte(m_groupeID);
    QString texte = "Votre cagnotte s'élève à ";
    texte.append(QString::number(sommeActu));
    texte.append("€");
    ui->txtsum->setText(texte);


    // Remplissage de la table si possible
    if (historique.size() > 0){
        std::string pseudo;
        double montant = 0;
        QString temp, qString;

        for(auto const& key : historique){
            pseudo = key.first;
            montant = key.second;

            // Récupération des données
            qString = QString::fromStdString(pseudo);
            temp = QString::number(montant);
            temp.append("€");

            // Transformation élément à intégrer dans la table
            QTableWidgetItem *pseud = new QTableWidgetItem(qString);
            QTableWidgetItem *val = new QTableWidgetItem(temp);

            // Insertion dans la table
            table->insertRow (table->rowCount());
            table->setItem (table->rowCount()-1, 0, pseud);
            table->setItem (table->rowCount()-1, 1, val);

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

