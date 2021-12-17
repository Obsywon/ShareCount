#ifndef CAGNOTTE_HPP
#define CAGNOTTE_HPP

#include <QWidget>

namespace Ui {
class cagnotte;
}

class cagnotte : public QWidget
{
    Q_OBJECT

public:
    explicit cagnotte(QWidget *parent = nullptr);
    ~cagnotte();

private:
    Ui::cagnotte *ui;
};

#endif // CAGNOTTE_HPP
