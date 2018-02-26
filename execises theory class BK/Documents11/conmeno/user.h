#ifndef USER_H
#define USER_H
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
QTextStream out(stdout);
class User{
public:
    QString User_Name;
    QString User_ID;
    QString History[50];
    User(QString user_iD){
        QFile f(user_iD+".txt");
        if (!f.open(QIODevice::ReadOnly)) {

           qWarning("Cannot find user!");
         }

         QTextStream in(&f);
           this->User_Name = in.readLine();
           out << this->User_Name << endl;
           this->User_ID = in.readLine();
           out << this->User_ID << endl;
           for(int i = 0; i < 50; i ++){
               this->History[i] = in.readLine();
               out << this->History[i] <<endl;
           }
           f.close();
       }
    ~User(void){
        QFile s(this->User_ID+".txt");
        if(!s.open(QIODevice::WriteOnly)){
            qWarning("Cannot open!");
        }
        else{
            QTextStream out(&s);
            out << this->User_Name << endl;
            out << this->User_ID << endl;
            for(int i = 0; i < 50; i ++){
                out << this->History[i] <<endl;
            }
        }
        s.close();
    }
};
#endif // USER_H
