#include "GestionGroupes.hpp"
#include "ui_gestiongroupes.h"

/**
 * @brief Constructeur de l'interface de gestion de groupes
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 */
GestionGroupes::GestionGroupes(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionGroupes),
    m_model(m)
{
    ui->setupUi(this);

    /*std::unordered_map<std::string, Groupe>  map = {{"oui",Groupe("test")},{"oui2",Groupe("test2")}};



    for(auto const& key : map){
        std::cout << key.first;
        std::string nom = map.at(key.first).getNom();
        QString qString = QString::fromStdString(nom);
        ui->groupes->addItem(qString);
    }*/

    std::unordered_map<int, Groupe> * hashMap = m->getTousLesGroupesConnus();
        for(auto const& key : *hashMap){
            std::cout << key.first;
            std::string nom = key.second.getNom();
            QString qString = QString::fromStdString(nom);
            ui->groupes->addItem(qString);
        }

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
 * @brief Réaction au bouton pour créer un événement
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
void GestionGroupes::on_b_groupes_clicked()
{
    emit evenement();
}

/**
 * @brief Affiche les Groupes liée à un compte
 * @authors Louis Jacques
 * @version v9 (Dernière modification)
 */
void GestionGroupes::afficherGroupe(Model* m){
    std::unordered_map<int, Groupe> * hashMap = m->getTousLesGroupesConnus();
        for(auto const& key : *hashMap){
            std::cout << key.first;
            std::string nom = key.second.getNom();
            QString qString = QString::fromStdString(nom);
            ui->groupes->addItem(qString);
        }
}
