#include <QApplication>
#include "MainWindow.hpp"
#include "Model.hpp"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Model modele;
    MainWindow w(&modele);
    w.show();

    return QApplication::exec();
}
