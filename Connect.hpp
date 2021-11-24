#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class Connect;
}

class Connect : public QWidget
{
    Q_OBJECT

public:
    explicit Connect(Model* m, QWidget *parent = nullptr);
    ~Connect();

private:
    Ui::Connect *ui;
    Model* m_model;

signals:
    void groupes();
private slots:
    void on_connecter_clicked();
};

#endif // CONNECT_HPP
