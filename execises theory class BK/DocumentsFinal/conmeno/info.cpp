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
#include <bitset>
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
class sha256{
private:
    bitset<32> rightRotate(bitset<32> n, unsigned int d)
    {
       return (n >> d)|(n << (32 - d));
    }
    string changeinttoHex(string a)
    {
        int count1=0;
        string hex;
        string HEX;
        for(int i=0;i<a.length()/4;i++){
            for(int k=0;k<4;k++){
                hex+=a[count1];
                count1++;
            }
            if(hex=="0000"){
                HEX+="0";
            }
            if(hex=="0001"){
                 HEX+="1";
            }
            if(hex=="0010"){
                  HEX+="2";
            }
            if(hex=="0011"){
                HEX+="3";
            }
            if(hex=="0100"){
                HEX+="4";
            }
            if(hex=="0101"){
                HEX+="5";
            }
            if(hex=="0110"){
                HEX+="6";
            }
            if(hex=="0111"){
                HEX+="7";
            }
            if(hex=="1000"){
                HEX+="8";
            }
            if(hex=="1001"){
                HEX+="9";
            }
            if(hex=="1010"){
                HEX+="A";
            }
            if(hex=="1011"){
                HEX+="B";
            }
            if(hex=="1100"){
                HEX+="C";
            }
            if(hex=="1101"){
                HEX+="D";
            }
            if(hex=="1110"){
                HEX+="E";
            }
            if(hex=="1111"){
                HEX+="F";
            }
            hex.clear();
        }
        return HEX;
      }
    bitset<32> sumbinary(bitset<32> a1,bitset<32> b1){
            bitset<1>c(0);
            string a2string=a1.to_string();
            string b2string=b1.to_string();
            string sumstring;
        for(int i=0;i<32;i++){
            bitset<1>a(a2string[i]);
            bitset<1>b(b2string[i]);
            bitset<1>sum;
            sum=a^b^c;
            bitset<1>carry;
            carry=((a&b)|(b&c)|(c&a));
            c=bitset<1>(carry);
            sumstring+=sum.to_string();
        }
        bitset<32>sumbinary(sumstring);
        return sumbinary;
//        sum = a xor b xor c

//        carry = ab+bc+ca
    }
public:
     QString SHA256(string string_hash){
         string HASH;

        string binaryhash;
                string qwe;
        for(int i=0;i<string_hash.length();i++){
          bitset<8>my(string_hash[i]);
          binaryhash+=my.to_string();

        }

        binaryhash+='1';
        int count1=0;
        int qw=448-binaryhash.length();
        while(count1<qw){
            binaryhash+="0";
            count1++;

        }
        bitset<64>my1(binaryhash.length());
        binaryhash+=my1.to_string();


            string array[64];
            int q=0;
            for(int f=0;f<16;f++){
                for(int p=0;p<32;p++){
                array[f]+=binaryhash[q];

                q++;
                }
            }

//                string_hash=w2.to_string();
            unsigned long long h0 = 0x6a09e667,
             h1 = 0xbb67ae85,
             h2 = 0x3c6ef372,
             h3 = 0xa54ff53a,
             h4 = 0x510e527f,
             h5 = 0x9b05688c,
             h6 = 0x1f83d9ab,
             h7 = 0x5be0cd19,
             s[64] ={
            0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
            0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
            0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
            0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
            0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
            0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
            0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
            0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
             for(int f=16;f<63;f++){
              bitset<32>w1(array[f-15]);
               bitset<32> w2(array[f-2]);
               bitset<32> w3(array[f-16]);
               bitset<32>w4(array[f-7]);
               bitset<32>s0(rightRotate(w1,7)|rightRotate(w1,18)|(rightRotate(w1,3)));
                bitset<32>s1(rightRotate(w2,17)|rightRotate(w1,19)|(rightRotate(w1,10)));
                bitset<32>wi(sumbinary(sumbinary(w3,s0),sumbinary(w4,s1)));
                array[f]=wi.to_string();

              }

             bitset<32>a(h0);
             bitset<32>b(h1);
             bitset<32>c(h2);
             bitset<32>d(h3);
             bitset<32>e(h4);
             bitset<32>f(h5);
             bitset<32>g(h6);
             bitset<32>h(h7);

     for(int count=0;count<64;count++){




                bitset<32>k(s[count]);
                bitset<32>wl(array[count]);
                bitset<32>S1((rightRotate(e,6)^rightRotate(e,11))^rightRotate(e,25));
                bitset<32>Ch((e&f)^(~e&g));
                bitset<32>sum987(sumbinary(h,S1));
                bitset<32>sum123(sumbinary(sum987,sumbinary(Ch,k)));
                bitset<32>temp3( sumbinary(sum123,wl));
                bitset<32>S0((rightRotate(a,2)^rightRotate(a,13))^rightRotate(a,22));
                bitset<32>maj(((a&b)^(a&c))^(b&c));
                bitset<32>temp2(sumbinary(S0,maj));

                h=bitset<32>(g);
                g=bitset<32>(f);
                e=bitset<32>(sumbinary(d,temp3));
                d=bitset<32>(c);
                c=bitset<32>(b);
                b=bitset<32>(a);
                a=bitset<32>(sumbinary(temp3,temp2));


     }

            h0+=a.to_ullong();
            h1+=b.to_ullong();
            h2+=c.to_ullong();
            h3+=d.to_ullong();
            h4+=e.to_ullong();
            h5+=f.to_ullong();
            h6+=g.to_ullong();
            h7+=h.to_ullong();

            bitset<32>A(h0);
            bitset<32>B(h1);
//              bitset<32>suma(sumbinary(A,B));
            bitset<32>C(h2);
            bitset<32>D(h3);
            bitset<32>E(h4);
            bitset<32>F(h5);
            bitset<32>G(h6);
            bitset<32>H(h7);
//                        qwe=A.to_string();
          HASH+=A.to_string();
          HASH+=B.to_string();
          HASH+=C.to_string();
          HASH+=D.to_string();
          HASH+=E.to_string();
          HASH+=F.to_string();
          HASH+=G.to_string();
          HASH+=H.to_string();
        QString hash;
        string last=changeinttoHex(HASH);
       hash=QString::fromStdString(last);
        return hash;
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

            sha256 Hashpassword;
            QString hash=Hashpassword.SHA256(newpass.toStdString());
            acc1->password = hash;
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