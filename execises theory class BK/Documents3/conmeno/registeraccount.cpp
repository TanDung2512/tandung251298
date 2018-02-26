#include "registeraccount.h"
#include "ui_registeraccount.h"

RegisterAccount::RegisterAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterAccount)
{
    ui->setupUi(this);
}

RegisterAccount::~RegisterAccount()
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
        QFile f(user_iD+".txt");
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
    ~User()
    {
        QFile s(this->User_ID+".txt");
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
        QFile f(account_name+".txt");
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
        QFile s(this->Account_Name+".txt");
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
 };

void RegisterAccount::on_pushButton_clicked()
{
    QString User_ID, User_SSD, user_SSDCo, Account_Name, Account_Pass, Account_PassCo;
    User_ID = ui->lineEdit->text();
    User_SSD = ui->lineEdit_2->text();
    Account_Name = ui->lineEdit_3->text();
    Account_Pass = ui->lineEdit_4->text();
    Account_PassCo = ui->lineEdit_5->text();

    QFile USER(User_ID+".txt");
    if(!USER.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"User","User not found!");
        ui->lineEdit->clear();
        ui->label_2->clear();
    }
    else
    {

        //USER.open(QIODevice::ReadOnly);
        QTextStream Userin(&USER);
        user_SSDCo = Userin.readLine();
        user_SSDCo = Userin.readLine();
        user_SSDCo = Userin.readLine();
        USER.close();

        if(User_SSD != user_SSDCo){
            QMessageBox::warning(this,"User","SSD not corect!");
            ui->lineEdit_2->clear();
        }else
        {
            if(Account_Pass !=Account_PassCo|| Account_Pass.length() < 4)
            {
                QMessageBox::warning(this, "Pass","Comfirm Password not corect!");
                ui->lineEdit_4->clear();
                ui->lineEdit_5->clear();
            }
            else
            {
                Account *acc;
                acc = new Account("");
                acc->Account_Name = Account_Name;
                acc->password = Account_Pass;
                acc->Role[0] = "True";
                acc->Role[1] = "False";
                acc->Role[2] = "False";
                acc->User_ID = User_ID;

                QFile AccIDread("AccID.txt");
                AccIDread.open(QIODevice::ReadOnly);
                QTextStream Accread(&AccIDread);
                QString ID = Accread.readLine();

                int accid = ID.toInt();
                accid++;
                acc->Account_ID = QString::number(accid);
                acc->user =  new User(acc->User_ID);
                AccIDread.close();

                QFile AccIDwrite("AccID.txt");
                AccIDwrite.open(QIODevice::WriteOnly);
                QTextStream Accwrite(&AccIDwrite);
                Accwrite << QString::number(accid);
                AccIDwrite.close();

                delete acc;

                QMessageBox::warning(this,"Sucess","OK!");
                this->close();
            }
        }
     }
}
