#ifndef AJOUTGROUPE_HPP
#define AJOUTGROUPE_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class AjoutGroupe;
}

class AjoutGroupe : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutGroupe(Model* m, QWidget *parent = nullptr);
    ~AjoutGroupe();

private slots:
    void on_ok_clicked();

signals:
    void groupes();

private:
    Ui::AjoutGroupe *ui;
    Model* m_model;
};

#endif // AJOUTGROUPE_HPP
