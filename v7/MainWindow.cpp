#include "MainWindow.hpp"
#include "ui_mainwindow.h"
/**
 * Affiche un message sur la console
 * @param msg string à afficher
 */
void print2(const std::string &msg) {
    QString ps = QString();
    ps = QString::fromStdString(msg);
    qDebug("%s", qUtf8Printable(ps));

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_model = Model();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Sert à demander l'inscription d'un utilisateur
 */
void MainWindow::on_inscrire_clicked()
{
    QString p, mdp, email, err;
    p = ui->in_pseudo->text();
    mdp = ui->in_mdp->text();
    email = ui->in_email->text();
    bool error = false;

    err = QString("Erreur : ");


    // Texte à afficher si l'email est invalide
    if (!m_model.estValideEmail(email.toStdString())){
        err.append("Addresse e-mail invalide. ");
        error = true;
    }

    // Texte à afficher si le mdp est invalide
    if (!m_model.estValideMdP(mdp.toStdString())){
        err.append("Mot de passe invalide.");
        error = true;
    }

    // Affichage du message d'erreur
    ui->in_erreur->setVisible(error);
    if (error == true){
        ui->in_erreur->setText("Erreur : adresse e-mail invalide.");
    }else{
        m_model.inscrireUtilisateur(p.toStdString(), email.toStdString(), mdp.toStdString());
        print2(m_model.toString());
        ui->pages->setCurrentIndex(1);

    }
}

/**
 * @brief Permet d'aller à la page d'inscription
 */
void MainWindow::on_sinscrire_clicked()
{
    ui->pages->setCurrentIndex(2);
}


/**
 * @brief Permet d'aller à la page de connection
 */
void MainWindow::on_seconnecter_clicked()
{
    ui->pages->setCurrentIndex(1);

}

/**
 * @brief Permet de se connecter, si possible
 */
void MainWindow::on_connecter_clicked()
{

    QString QMdp = ui->co_mdp->text();
    QString QPseudo = ui->co_pseudo->text();
    QString error = QString("Erreur : ");
    if (QPseudo.isEmpty() || QMdp.isEmpty()){
        error.append("Champs vides. ");
        ui->co_err->setText(error);
        ui->co_err->setVisible(true);
    }else{
        ui->co_err->setVisible(false);
        bool connect = m_model.compteExiste(QPseudo.toStdString(), QMdp.toStdString());
        if (connect){
            m_model.connecterUtilisateur(QPseudo.toStdString(), "" ,QMdp.toStdString()); // Partie e-mail à retravailler
            print2(m_model.toString());
            m_model.creerGroupe("Groupe 1");
            updateGroups();
            ui->pages->setCurrentIndex(3);

        }else{
            error.append("Erreur lors de la connection.");
            ui->co_err->setText(error);
            ui->co_err->setVisible(true);
        }
    }


}

void MainWindow::updateGroups(){
     std::vector <std::string> liste = m_model.listeNoms();
     m_id_groupe = liste[0];

     /*
     int i=0;
     for (auto kv : liste){
         QLabel temp (new QString(kv));
        ui->groupes->addWidget(&temp, i, Qt::Alignment());
        i++;
     }
     */
}


void MainWindow::on_b_groupes_clicked()
{
    ui->pages->setCurrentIndex(4);
}


void MainWindow::on_ok_event_clicked()
{
    updateGroups();
    QString nom = ui->nom_event->text();
    QDate dateDeb = ui->dateDeb->date();
    QDate dateFin = ui->dateFin->date();
    print2(dateDeb.toString("dd.MM.yyyy").toStdString());
    m_model.creerEvenement(m_id_groupe,nom.toStdString(), dateDeb.toString("dd.MM.yyyy").toStdString(), dateFin.toString("dd.MM.yyyy").toStdString());
    ui->pages->setCurrentIndex(3);

}




void MainWindow::on_ok_groupes_clicked()
{
    QString nom = ui->nom_groupe->text();
     m_model.creerGroupe(nom.toStdString());
     print2("GROUPES : ");
     print2(m_model.groupesToString());
     ui->pages->setCurrentIndex(3);


}


void MainWindow::on_ajout_event_clicked()
{
    ui->pages->setCurrentIndex(6);

}


void MainWindow::on_ajout_groupe_clicked()
{
    ui->pages->setCurrentIndex(5);
}

