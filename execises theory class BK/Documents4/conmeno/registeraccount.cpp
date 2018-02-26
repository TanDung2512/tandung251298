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
        QFile f("Acc\\" + account_name + ".txt");
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
        QFile s("Acc\\" +this->Account_Name+".txt");
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
class SHA_1 {
public:
 QString SHA1(QString string_hash){
    stringstream ss;

    int a[string_hash.length()];
    double hex[string_hash.length()];
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

void RegisterAccount::on_pushButton_clicked()
{
    QString User_ID, User_SSD, user_SSDCo, Account_Name, Account_Pass, Account_PassCo;
    User_ID = ui->lineEdit->text();
    User_SSD = ui->lineEdit_2->text();
    Account_Name = ui->lineEdit_3->text();
    Account_Pass = ui->lineEdit_4->text();
    Account_PassCo = ui->lineEdit_5->text();
    QFile USER("User\\"+User_ID+".txt");
    if(!USER.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"User","User not found!");
        ui->lineEdit->clear();
        ui->label_2->clear();
    }else{
        //USER.open(QIODevice::ReadOnly);
        QTextStream Userin(&USER);
        user_SSDCo = Userin.readLine();
        user_SSDCo = Userin.readLine();
        user_SSDCo = Userin.readLine();
        USER.close();
        if(User_SSD != user_SSDCo){
            QMessageBox::warning(this,"User","SSD not corect!");
            ui->lineEdit_2->clear();
        }
        else{
            if(Account_Pass !=Account_PassCo|| Account_Pass.length() < 4){
                QMessageBox::warning(this, "Pass","Comfirm Password not corect!");
                ui->lineEdit_4->clear();
                ui->lineEdit_5->clear();
            }
            else{
                SHA_1 SHA1Pass;
                QString PassSHAAfterConvert=SHA1Pass.SHA1(Account_Pass);

                Account *acc;
                acc = new Account("");
                acc->Account_Name = Account_Name;
                acc->password = PassSHAAfterConvert;
                acc->Role[0] = "True";
                acc->Role[1] = "False";
                acc->Role[2] = "False";
                acc->User_ID = User_ID;

                QFile AccIDread("System\\AccID.txt");
                AccIDread.open(QIODevice::ReadOnly);
                QTextStream Accread(&AccIDread);
                QString ID = Accread.readLine();
                int accid = ID.toInt();
                accid++;
                acc->Account_ID = QString::number(accid);
                acc->user =  new User(acc->User_ID);
                AccIDread.close();

                QFile AccIDwrite("System\\AccID.txt");
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
