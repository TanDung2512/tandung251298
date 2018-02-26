#include "info.h"
#include "blirariancofirm.h"
#include "ui_info.h"
#include <QTextStream>
#include <QFile>
#include<QMessageBox>
#include<QWidget>
#include<iostream>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<QFileInfo>
#include<string>
#include "adminc.h"
#define MAX_account 20
using namespace std;
class User{
public:
    QString User_Name;
    QString User_ID;
    QString User_SSN;
    QString User_Birth_day, User_Birth_month, User_Birth_year;
    QString User_Opcu;
    QString User_Email;
    QString History[50];
    User(QString user_iD){
        QFile f("User/"+user_iD+".txt");
        f.open(QIODevice::ReadOnly);
         QTextStream in(&f);
           this->User_Name = in.readLine();
           this->User_ID = in.readLine();
           this->User_SSN = in.readLine();
         this->User_Birth_day = in.readLine();
         this->User_Birth_month = in.readLine();
         this->User_Birth_year = in.readLine();
         this->User_Opcu = in.readLine();
         this->User_Email = in.readLine();
           for(int i = 0; i < 50; i ++){
               this->History[i] = in.readLine();
           }
           f.close();
       }
    ~User(){
        QFile s("User/"+this->User_ID+".txt");
        s.open(QIODevice::WriteOnly);
        QTextStream out(&s);
        out << this->User_Name << endl;
        out << this->User_ID << endl;
        out << this->User_SSN << endl;
        out << this->User_Birth_day << endl;
        out << this->User_Birth_month << endl;
        out << this->User_Birth_year << endl;
        out << this->User_Opcu << endl;
        out << this->User_Email << endl;
        for(int i = 0; i < 50; i ++){
              out << this->History[i] <<endl;
        }
        s.close();
    }
};
class Account{
public:
    QString Account_Name;
    QString password;
    QString Account_ID;
    QString User_ID;
    QString Role[3];
    User *user;
    Account(QString account_name){
        QFile f("Acc/" + account_name + ".txt");
        if (!f.open(QIODevice::ReadOnly)) {

           qWarning("Cannot find account!");
         }else{
         QTextStream in(&f);
           this->Account_Name = in.readLine();
           this->password = in.readLine();
           this->Account_ID = in.readLine();
           this->User_ID = in.readLine();
           for(int i = 0; i<3; i ++){
           this->Role[i] = in.readLine();
           }
           f.close();
           user = new User(this->User_ID);
                }
       }
    ~Account(){
        QFile s("Acc/" +this->Account_Name+".txt");
        if(!s.open(QIODevice::WriteOnly)){
            qWarning("Cannot open!");
        }
        QTextStream out(&s);
        out << this->Account_Name<<endl;
        out << this->password <<endl;
        out << this->Account_ID<<endl;
        out << this->User_ID <<endl;
        for(int i = 0; i <3; i ++){
        out << this->Role[i]  << endl;
        }
        s.close();
        delete user;
    }
    void SetAccout(){
        QFile Set("System/UsingAccount.txt");
        Set.open(QIODevice::WriteOnly);
        QTextStream Setout(&Set);
        Setout << this->Account_Name;
        Set.close();
    }
    QString CheckAccount(){
        QFile Check("System/UsingAccount.txt");
        Check.open(QIODevice::ReadOnly);
        QTextStream Checkin(&Check);
        QString Name = Checkin.readLine();
        Check.close();
        return Name;
    }
    void SetNull(){
        QFile SetN("System/UsingAccount.txt");
        SetN.open(QIODevice::WriteOnly);
        QTextStream SetNout(&SetN);
        SetNout << "Null";
        SetN.close();
    }
 };
Account *acc1;
info::info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
   // acc1->CheckAccount();
    acc1 = new Account(acc1->CheckAccount());
    ui->NameUser->setText(acc1->user->User_Name);
    ui->IDUser->setText(acc1->user->User_ID);
    ui->SSNUser->setText(acc1->user->User_SSN);
    ui->Job->setText(acc1->user->User_Opcu);
    ui->Email->setText(acc1->user->User_Email);
    ui->AccountID->setText(acc1->Account_ID);
    ui->AccountName->setText(acc1->Account_Name);
    ui->IsReader->setText(acc1->Role[0]);
    if(acc1->Role[1]== "True"){
        ui->IsBlirarian->setDisabled(true);
        ui->IsBlirarian->setText("Yes");
    }else{
        ui->IsBlirarian->setEnabled(true);
        ui->IsBlirarian->setText("Active");
    }
    if(acc1->Role[2]== "True"){
        ui->IsAdmin->setDisabled(true);
        ui->IsAdmin->setText("Yes");
    }else{
        ui->IsAdmin->setEnabled(true);
        ui->IsAdmin->setText("Active");
    }
    QString History1 = "";
    for(int i = 0; i <50; i ++){
        if(acc1->user->History[i].length() > 0){
            History1 += (acc1->user->History[i] + "\n");
        }
        //acc1->user->History[i] = "Huy";
        //History1 += acc1->user->History[i];
    }
    ui->History5->setText(History1);
}

info::~info()
{   delete acc1;
    delete ui;
}

void info::on_ChangeInfo_clicked()
{
    acc1 =  new Account(acc1->Account_Name);
    acc1->user->User_Name = ui->NameUser->text();
    acc1->user->User_Opcu = ui->Job->text();
    acc1->user->User_Email = ui->Email->text();
    this->close();
}

void info::on_ChangePass_clicked()
{
    acc1 = new Account(acc1->Account_Name);
    QString oldpass = ui->OldPass->text();
    QString newpass = ui->NewPass->text();
    QString comfirm = ui->ComfirmPass->text();
    if(oldpass!= acc1->password){
        QMessageBox::warning(this, "Password", "Password incorect!");
        ui->OldPass->clear();
        ui->NewPass->clear();
        ui->ComfirmPass->clear();
    }else{
        if(newpass != comfirm|| newpass.length() < 4){
            QMessageBox::warning(this, "Password", "Password comfirm Wrong!");
            ui->OldPass->clear();
            ui->NewPass->clear();
            ui->ComfirmPass->clear();
        }else{
            acc1->password = ui->NewPass->text();
            this->close();
        }
    }
}

void info::on_Ok_clicked()
{
    acc1 = new Account(acc1->Account_Name);
    this->close();
}

void info::on_IsBlirarian_clicked()
{
    blirariancofirm b;
    b.setModal(true);
    b.exec();
}

void info::on_IsAdmin_clicked()
{
    Adminc A;
    A.setModal(true);
    A.exec();
}
