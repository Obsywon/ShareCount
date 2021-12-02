#include "GestionGroupes.hpp"
#include "ui_gestiongroupes.h"

/**
 * @brief Constructeur de l'interface de gestion de groupes
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v9 (Remplissage de la liste view lors d'un ajout)
 */
GestionGroupes::GestionGroupes(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionGroupes),
    m_model(m)
{
    ui->setupUi(this);

}

GestionGroupes::~GestionGroupes()
{
    delete ui;
}

/**
 * @brief Réaction au bouton d'ajout d'un groupe
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
void GestionGroupes::on_ajout_groupe_clicked()
{
    emit ajoutGroupe();
}

/**
 * @brief Affiche les Groupes liée à un compte
 * @authors Louis Jacques
 * @version v9 (Dernière modification)
 */
void GestionGroupes::afficherGroupe(Model* m){

    // Nettoyage de la vue et de la liste des ids
    ui->groupes->clear();
    m_listIDs.clear();

    // Peuplement de la vue & de la liste d'identifiants
    std::unordered_map<int, Groupe> * hashMap = m->getTousLesGroupesConnus();
    for(auto const& key : *hashMap){
        m_listIDs.push_back(key.first);
        std::string nom = key.second.getNom();
        QString qString = QString::fromStdString(nom);
        ui->groupes->addItem(qString);
    }

}
/**
 * @brief Permet d'accéder à la page d'un groupe et d'en afficher les événements
 * @author Guillaume Vautrin
 * @version v9 (Dernière modification)
 */
void GestionGroupes::on_groupes_itemClicked(QListWidgetItem *item){
    emit evenements(1);
}

