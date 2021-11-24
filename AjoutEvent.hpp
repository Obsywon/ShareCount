#ifndef AJOUTEVENT_HPP
#define AJOUTEVENT_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class AjoutEvent;
}

class AjoutEvent : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutEvent(Model* m, QWidget *parent = nullptr);
    ~AjoutEvent();
signals:
    void groupes();

private slots:
    void on_ok_event_clicked();

private:
    Ui::AjoutEvent *ui;
    Model* m_model;
};

#endif // AJOUTEVENT_HPP
