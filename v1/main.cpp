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
    model.inscrireUtilisateur("pseudo", "email@email.com", "test01");
    print(model.userToString());



    return QCoreApplication::exec();
}
