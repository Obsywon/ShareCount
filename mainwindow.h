#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Model.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_inscrire_clicked();

    void on_sinscrire_clicked();

    void on_seconnecter_clicked();

    void on_connecter_clicked();

private:
    Ui::MainWindow *ui;
    Model m_model;
};
#endif // MAINWINDOW_H
