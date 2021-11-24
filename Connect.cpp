#include "Connect.hpp"
#include "ui_connect.h"

Connect::Connect(Model* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connect),
    m_model (m)
{
    ui->setupUi(this);
}

Connect::~Connect()
{
    delete ui;
}

void Connect::on_connecter_clicked()
{
    emit groupes();
}

