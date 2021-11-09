#include <QCoreApplication>
#include <QDebug>
#include "Model.h"

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
    qDebug() << "Hello World";
    Model model = Model();
    std::string mdp = "test01";
    std::string email = "email@email.com";
    std::string pseudo = "test";



    return QCoreApplication::exec();
}
