#include "dialog.h"
#include "ui_dialog.h"
#include"mainwindow.h"
#include"account.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    //ui->label->setText(account->Account_ID);
}

Dialog::~Dialog()
{
    delete ui;
}
