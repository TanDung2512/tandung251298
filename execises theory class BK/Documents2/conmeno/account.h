#ifndef ACCOUNT_H
#define ACCOUNT_H
#include"user.h"
#define MAX_account 20
using namespace std;
class Account{
public:
    QString Account_Name;
    QString password;
    QString Account_ID;
    QString User_ID;
    QString Role[3];
    User user;
    Account(QString account_name){
        QFile f(account_name+".txt");
        if (!f.open(QIODevice::ReadOnly)) {

           qWarning("Cannot find account!");
         }else{

         QTextStream in(&f);
           this->Account_Name = in.readLine();
          // out << this->Account_Name << endl;
           this->password = in.readLine();
          // out << this->password << endl;
           this->Account_ID = in.readLine();
         //  out << this->Account_ID << endl;
           this->User_ID = in.readLine();
         //  out << this->User_ID << endl;
           for(int i = 0; i<3; i ++){
           this->Role[i] = in.readLine();
          // out << this->Role[i] << endl;
           }
           f.close();
           user.User(User_ID);
                }
       }
    ~Account(void){
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
        user.~User();
    }
 };
Account accounts;
#endif // ACCOUNT_H
