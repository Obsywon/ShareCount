#ifndef LAUNCH_HPP
#define LAUNCH_HPP

#include <QWidget>
#include "Model.hpp"
#include "Connect.hpp"
#include "Inscription.hpp"

namespace Ui {
class Launch;
}

class Launch : public QWidget
{
    Q_OBJECT

public:
    explicit Launch(Model* m, QWidget *parent = nullptr);
    ~Launch();

private slots:
    void on_sinscrire_clicked();
    void on_seconnecter_clicked();

signals:
    void inscrire();
    void connecter();

private:
    Ui::Launch *ui;
    Model* m_model;
};

#endif // LAUNCH_HPP
