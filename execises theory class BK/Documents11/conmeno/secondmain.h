#ifndef SECONDMAIN_H
#define SECONDMAIN_H

#include <QDialog>

namespace Ui {
class SecondMain;
}

class SecondMain : public QDialog
{
    Q_OBJECT

public:
    explicit SecondMain(QWidget *parent = 0);
    ~SecondMain();

private:
    Ui::SecondMain *ui;
};

#endif // SECONDMAIN_H
