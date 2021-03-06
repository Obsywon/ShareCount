#include <QCoreApplication>
#include <QDebug>
#include "Model.hpp"

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
    QCoreApplication a(argc, argv);
    Model model = Model();

    // String de tests
    std::string pseudo = "test";
    std::string mdp = "test";
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






    return QCoreApplication::exec();
}
