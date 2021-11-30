#include <QApplication>
#include "MainWindow.hpp"
#include "Model.hpp"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Model modele; // Crée le modèle contenant les données du programme
    MainWindow w(&modele); // Génère l'interface qui va modifier les données
    w.show();

    return QApplication::exec();
}
