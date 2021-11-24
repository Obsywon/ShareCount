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
    m_model (m),
    QWidget(parent),
    ui(new Ui::Connect)

{
    ui->setupUi(this);
}

Connect::~Connect()
{
    delete ui;
}

/**
 * @brief Envoie un signal permettant de revenir sur l'interface des groupes
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
void Connect::on_connecter_clicked()
{
    emit groupes();
}

