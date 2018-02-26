#include "register.h"
#include "ui_register.h"
#include "registeruser.h"
#include "registeraccount.h"
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_YES_clicked()
{
    RegisterUser R;
    R.setModal(true);
    R.exec();
    this->close();
}

void Register::on_NO_clicked()
{
    RegisterAccount No;
    No.setModal(true);
    No.exec();
    this->close ();
}
