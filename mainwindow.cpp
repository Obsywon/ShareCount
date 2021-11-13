#include "mainwindow.h"
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
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_Inscription_clicked()
{
    print2("Valide");
}

