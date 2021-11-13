#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include "Model.hpp"
#include "mainwindow.h"

/**
 * Affiche un message sur la console
 * @param msg string à afficher
 */
void print(const std::string &msg) {
    QString ps = QString();
    ps = QString::fromStdString(msg);
    qDebug("%s", qUtf8Printable(ps));

}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Model model = Model();

    // String de tests
    std::string pseudo = "pseudo";
    std::string mdp = "mdp";
    std::string email = "test@test.com";

    // Test de validité des éléments sensibles + inscription effective
    if (model.estValideMdP(mdp) && model.estValideEmail(email)){
        model.inscrireUtilisateur("pseudo", "email@email.com", "test01");
        print(model.userToString());
    }else{
        print(mdp); print (email);
        print("Inscription utilisateur impossible : mot de passe ou e-mail invalide");
    }

    // "test" pour retrouver un compte et le connecter:
    if (model.compteExiste(pseudo, mdp)){
        model.connecterUtilisateur(pseudo,email,mdp);
    }

    model.creerGroupe("Groupe 1");
    Utilisateur t = Utilisateur("moi", "e@t.fr", "..", nullptr);
    model.ajouterMembreAGroupe("Groupe 1", &t);
    model.creerEvenement("Groupe 1", "event", "01/01/2000", "02/01/2000");
    print(model.toString());

    // Interface exemplaire
    MainWindow w;
    w.show();

    return QApplication::exec();
}
