#include "Inscription.hpp"
#include "ui_inscription.h"

/**
 * @brief Constructeur de l'interface d'inscription
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
* @author Guillaume Vautrin
* @version v17 (Dernière modification)
 */
Inscription::Inscription(Model* m, QWidget *parent) :
    Page(m, parent),
    ui(new Ui::Inscription)
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
        if (!m_model->estValideMdP(mdp.toStdString()) || ui->in_mdp->text() != ui->in_mdp_2->text()){
            err.append("Mot de passe invalide.");
            error = true;
        }
    }

    // Affichage du message d'erreur
    ui->in_erreur->setVisible(error);
    if (error){
        ui->in_erreur->setText(err);
    }else{
        m_model->inscrireUtilisateur(p.toStdString(), email.toStdString(), mdp.toStdString());
        emit vueGroupe();

    }

}

/**
 * @brief Passe à l'écran de connexion en vidant les champs locaux au préalable
 * @author Guillaume Vautrin
 * @version v9 (Dernière modification)
 */
void Inscription::on_connecter_clicked()
{
    ui->in_email->setText("");
    ui->in_erreur->setText("");
    ui->in_mdp->setText("");
    ui->in_mdp_2->setText("");
    ui->in_pseudo->setText("");
    emit connecter();
}

