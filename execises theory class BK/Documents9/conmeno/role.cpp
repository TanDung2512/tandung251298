#include "role.h"
#include "ui_role.h"

Role::Role(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Role)
{
    ui->setupUi(this);
    ui->label->setText("User: "+ user->User_Name);
    ui->label_2->setText("ID: "+accounts->User_ID);
    ui->label_3->setText("Account: "+ accounts->Account_Name);
}

Role::~Role()
{
    delete ui;
}
