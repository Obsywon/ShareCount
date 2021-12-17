#include "cagnotte.hpp"
#include "ui_cagnotte.h"

cagnotte::cagnotte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cagnotte)
{
    ui->setupUi(this);
}

cagnotte::~cagnotte()
{
    delete ui;
}
