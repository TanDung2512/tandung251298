#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Loginbtn_clicked();

    void on_ExitBtn_clicked();

    void on_LogOut_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_BookShow_clicked();

    void on_BookShow_2_clicked();

    void on_BookShow_3_clicked();

    void on_BookShow_4_clicked();

    void on_BookShow_5_clicked();

    void on_BookShow_6_clicked();

    void on_BookShow_7_clicked();

    void on_BookShow_8_clicked();

    void on_BookShow_9_clicked();

    void on_BookShow_10_clicked();

    void on_Registerbtn_clicked();

private:
    Ui::MainWindow *ui;
};
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
class Book{
public:
    QString Book_Name;
    QString Book_Author;
    QString Book_ID;
    QString Book_Type;
    QString Num_of_rating, Sum_of_rating, Rate;
    QString Discribe;
    void create(QString name, QString author, QString id, QString type, QString rate, QString discribe){
        this->Book_Name = name;
        this->Book_Author = author;
        this->Book_ID = id;
        this->Book_Type = type;
        this->Rate = rate;
        this->Discribe = discribe;
        this->Num_of_rating = 1;
        this->Sum_of_rating = rate;
        this->save();
    }
    void load(QString ID){
        QFile book(ID+".txt");
        book.open(QIODevice::ReadOnly);
        QTextStream in(&book);
            this->Book_Name = in.readLine();
            this->Book_Author = in.readLine();
            this->Book_ID = in.readLine();
            this->Book_Type = in.readLine();
            this->Sum_of_rating = in.readLine();
            this->Num_of_rating = in.readLine();
            this->Rate =in.readLine();
            this->Discribe = in.readLine();
    }
    void save(){
        QFile book(this->Book_ID+".txt");
        QTextStream out(&book);
        out << this->Book_Name << endl;
        out << this->Book_Author << endl;
        out << this->Book_ID << endl;
        out << this->Book_Type << endl;
        out << this->Sum_of_rating << endl;
        out << this->Num_of_rating << endl;
        out << this->Rate << endl;
        out << this->Discribe << endl;
        book.close();
        QFile booklist("BookList.txt");
        booklist.open(QIODevice::Append);
        QTextStream outs(&booklist);
        outs << this->Book_ID << endl;
        booklist.close();
    }
};
#endif // MAINWINDOW_H
