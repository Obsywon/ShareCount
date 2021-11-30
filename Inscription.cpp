#include "Inscription.hpp"
#include "ui_inscription.h"

/**
 * @brief Constructeur de l'interface d'inscription
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
Inscription::Inscription(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inscription),
    m_model(m)
{
    ui->setupUi(this);
}

Inscription::~Inscription()
{
    delete ui;
}
/**
 * @brief réaction au bouton 'inscription'
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
void Inscription::on_inscrire_clicked()
{
    QString p, mdp, email, err;
    p = ui->in_pseudo->text();
    mdp = ui->in_mdp->text();
    email = ui->in_email->text();
    bool error = false;

    err = QString("Erreur : ");

    // Vérifie les erreurs ou si les champs sont vides lors de la validation
    if (email.isEmpty() || mdp.isEmpty()){
        err.append("Un ou plusieurs champs sont vides.");
        error = true;
    }else{


        // Texte à afficher si l'email est invalide
        if (!m_model->estValideEmail(email.toStdString())){
            err.append("Addresse e-mail invalide. ");
            error = true;
        }

        // Texte à afficher si le mdp est invalide
        if (!m_model->estValideMdP(mdp.toStdString())){
            err.append("Mot de passe invalide.");
            error = true;
        }
    }

    // Affichage du message d'erreur
    ui->in_erreur->setVisible(error);
    if (error){
        ui->in_erreur->setText("Erreur : adresse e-mail invalide.");
    }else{
        m_model->inscrireUtilisateur(p.toStdString(), email.toStdString(), mdp.toStdString());
        //print2(m_model->toString());
        emit groupes();

    }

}

