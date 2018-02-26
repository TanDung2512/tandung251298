#include "adminc.h"
#include "ui_adminc.h"

Adminc::Adminc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminc)
{
    ui->setupUi(this);
}

Adminc::~Adminc()
{
    delete ui;
}
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
        QFile f("User/" +user_iD+".txt");
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
        QFile s("User\\"+this->User_ID+".txt");
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
        this->Account_Name = Checkin.readLine();
        Check.close();
        return this->Account_Name;
    }
    void SetNull(){
        QFile SetN("System/UsingAccount.txt");
        SetN.open(QIODevice::WriteOnly);
        QTextStream SetNout(&SetN);
        SetNout << "Null";
        SetN.close();
    }
 };
void Adminc::on_pushButton_clicked()
{
    Account *acc3;
    acc3 = new Account(acc3->CheckAccount());
    QString code = ui->lineEdit->text();
    QFile Codecheck("System/AdminPass.txt");
    Codecheck.open(QIODevice::ReadOnly);
    QTextStream In(&Codecheck);
    QString Codec = In.readLine();
    Codecheck.close();
    if(Codec == code){
        acc3->Role[2] = "True";
        delete acc3;
        this->close();
    }else{
        QMessageBox::warning(this, "Opp!", "Wrong code!");
        ui->lineEdit->clear();
    }
}
