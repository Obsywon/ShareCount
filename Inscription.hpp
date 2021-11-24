#ifndef INSCRIPTION_HPP
#define INSCRIPTION_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class Inscription;
}

class Inscription : public QWidget
{
    Q_OBJECT

public:
    explicit Inscription(Model* m, QWidget *parent = nullptr);
    ~Inscription();

private:
    Ui::Inscription *ui;
    Model* m_model;

signals:
    void groupes();

private slots:
    void on_inscrire_clicked();
};

#endif // INSCRIPTION_HPP
