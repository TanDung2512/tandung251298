#include "registeruser.h"
#include "ui_registeruser.h"
#include "registeraccount.h"

RegisterUser::RegisterUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterUser)
{
    ui->setupUi(this);
}

RegisterUser::~RegisterUser()
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
    ~User(){
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
void RegisterUser::on_Regis_clicked()
{
    QString Name = ui->lineEdit->text();
    QString SSN = ui->lineEdit_2->text();
    QString Day = ui->lineEdit_3->text();
    QString Month = ui->lineEdit_4->text();
    QString Year = ui->lineEdit_5->text();
    QString Opcup = ui->lineEdit_6->text();
    QString Em = ui->lineEdit_7->text();
    if(Day.toInt()>31||Day.toInt()<1||Month.toInt()>12||Month.toInt()<1){
        QMessageBox::warning(this,"Wrong","BirthDay is incorect!");
    }else{
    User *user;
    user = new User("trash");
    user->User_Name = Name;
    user->User_SSN = SSN;
    user->User_Birth_day = Day;
    user->User_Birth_month = Month;
    user->User_Birth_year = Year;
    user->User_Opcu = Opcup;
    user->User_Email = Em;
    QFile readID("UserID.txt");
    readID.open(QIODevice::ReadOnly);
    QTextStream IDread(&readID);
    QString currentID = IDread.readLine();
    int UseID = currentID.toInt();
    UseID++;
    user->User_ID = QString::number(UseID);
    readID.close();
    QFile writeID("UserID.txt");
    writeID.open(QIODevice::WriteOnly);
    QTextStream IDwrite(&writeID);
    IDwrite << QString::number(UseID);
    writeID.close();
    delete user;
    this->close();
    QMessageBox::warning(this,"User register","Yor Name: " + Name +"\nYour ID: " + QString::number(UseID));
    RegisterAccount RA;
    RA.setModal(true);
    RA.exec();
    }
}
