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

    void on_ChangeInfo_clicked();

    void on_OK_clicked();

    void on_pushButton_4_clicked();

    void on_Cart_clicked();

    void on_AddCart_clicked();




    void on_Search_clicked();

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
    void CheckAccount(){
        QFile Check("System/UsingAccount.txt");
        Check.open(QIODevice::ReadOnly);
        QTextStream Checkin(&Check);
        this->Account_Name = Checkin.readLine();
        Check.close();
    }
    void SetNull(){
        QFile SetN("System/UsingAccount.txt");
        SetN.open(QIODevice::WriteOnly);
        QTextStream SetNout(&SetN);
        SetNout << "Null";
        SetN.close();
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
        QFile book("Book/" +ID+".txt");
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
        QFile book("Book/" +this->Book_ID+".txt");
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
        QFile booklist("System/BookList.txt");
        booklist.open(QIODevice::Append);
        QTextStream outs(&booklist);
        outs << this->Book_ID << endl;
        booklist.close();
    }
    Book &operator = (const Book&copy){
        this->Book_Name=copy.Book_Name;
        this->Book_ID=copy.Book_ID;
        this->Book_Type=copy.Book_Type;
        this->Book_Author=copy.Book_Author;
        this->Sum_of_rating=copy.Sum_of_rating;
        this->Num_of_rating=copy.Num_of_rating;
        this->Rate=copy.Rate;
        this->Discribe=copy.Discribe;
        return *this;
    }

};
class SHA_1 {
public:
 QString SHA1(QString string_hash){
    stringstream ss;

    int *a;
    a=new int[string_hash.length()];
    double *hex;
    hex=new double[string_hash.length()];
    for (int i=0; i<string_hash.length(); i++) {
        a[i]=string_hash.at(i).toLatin1();
    }
    for (int i=0;i<string_hash.length(); i++) {
        ss<<std::hex<<a[i];
        ss>>hex[i];
        ss.clear();
        }
        double array[64];
        for (int i=0; i<string_hash.length(); i++) {
            array[i]=hex[i];
        }

        int n=(int)string_hash.length();
        array[n]=80;
        long long int mit[80];

        string tamp;
        int count;
        for ( count=n+1; count<62; count++) {
            array[count]=0;
        }
        array[63]=n;
        int m=0;
        for (int i=0; i<16; i++) {
            string temp;
            for (int k=0; k<4; k++) {
                ss<<array[m];
                ss>>tamp;
                ss.clear();
                temp.append(tamp);
                m++;
            }
            ss<<temp;
            ss>>mit[i];
            temp.clear();

        }
        //    for (int i=0; i<16; i++) {
        //        cout<<mit[i]<<endl;
        //    }
        unsigned long long int h0 = 0x67452301,s,b,c,d,e,
        h1 = 0xEFCDAB89,
        h2 = 0x98BADCFE,
        h3 = 0x10325476,
        h4 = 0xC3D2E1F0;
        for (int i=16; i<80; i++) {
            mit[i]=(mit[i-3]^mit[i-8]^mit[i-14]^mit[i-16])<<1;
        }
        s=h0;
        b=h1;
        c=h2;
        d=h3;
        e=h4;

        for (int i=0; i<80; i++) {
            unsigned long long int f,k;
            unsigned long long int q;
            if (i<=19) {
                f=(b&s)|((~b)&d);
                k=0x5A827999;
            }
            else if(i<=39){
                f=b^c^d;
                k=0x8F1BBCDC;
            }
            else if(i<=59){
                f=(b & c) |(b&d)| (c&d);
                k=0x8F1BBCDC;
            }
            else {
                f=b^c^d;
                k =0xCA62C1D6;
            }
            q=(s<<5)+f+e+k+mit[i];
            e=d;
            d=c;
            c=b<<30;
            b=s;
            s=q;
        }
    QString p;
        h0 = (h0 + s)<<2;
        h1 = (h1 + b)<<4;
        h2 = (h2 + c)<<5;
        h3 = (h3 + d)<<3;
        h4 = h4 + e;
        QString h0string=QString::number(h0,16);
        QString h1string =QString::number(h1,16);
        QString h2string = QString::number(h2,16);
        QString h3string =QString::number(h3,16);
        QString h4string = QString::number(h4,16);

        p=h0string+h1string+h2string +h3string+h4string;
        return p;
}
};
#endif // MAINWINDOW_H
