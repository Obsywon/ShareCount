#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Launch.hpp"
#include "Connect.hpp"
#include "Inscription.hpp"
#include "GestionGroupes.hpp"
#include "GestionEvents.hpp"
#include "AjoutGroupe.hpp"
#include "AjoutEvent.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum pages {LAUNCH, CONNECT, INSCRIPTION, GROUPES, EVENTS, ADDGROUP, ADDEVENT};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model* m, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Model *m_model;
    Launch *m_launch;
    Inscription *m_inscription;
    Connect *m_connection;
    GestionGroupes* m_groupes;
    GestionEvents* m_events;
    AjoutGroupe* m_addGroup;
    AjoutEvent* m_addEvent;

    void changerPage(int i);

public slots:
    void afficherInscription();
    void afficherConnection();
    void afficherGroupes();
    void afficherAjoutGroupe();
    void afficherEvenement();
    void afficherAjoutEvent();

};
#endif // MAINWINDOW_H
