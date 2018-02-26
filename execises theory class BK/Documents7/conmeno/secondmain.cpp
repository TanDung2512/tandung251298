#include "secondmain.h"
#include "ui_secondmain.h"

SecondMain::SecondMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondMain)
{
    ui->setupUi(this);
}

SecondMain::~SecondMain()
{
    delete ui;
}
