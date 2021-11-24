#ifndef GESTIONEVENTS_HPP
#define GESTIONEVENTS_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class GestionEvents;
}

class GestionEvents : public QWidget
{
    Q_OBJECT

public:
    explicit GestionEvents(Model* m, QWidget *parent = nullptr);
    ~GestionEvents();

private slots:
    void on_ajout_event_clicked();

signals:
    void addEvent();

private:
    Ui::GestionEvents *ui;
    Model* m_model;
};

#endif // GESTIONEVENTS_HPP
