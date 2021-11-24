#ifndef GESTIONGROUPES_HPP
#define GESTIONGROUPES_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class GestionGroupes;
}

class GestionGroupes : public QWidget
{
    Q_OBJECT

public:
    explicit GestionGroupes(Model* m, QWidget *parent = nullptr);
    ~GestionGroupes();

private slots:
    void on_ajout_groupe_clicked();
    void on_b_groupes_clicked();

signals:
    void ajoutGroupe();
    void evenement();

private:
    Ui::GestionGroupes *ui;
    Model* m_model;
};

#endif // GESTIONGROUPES_HPP
