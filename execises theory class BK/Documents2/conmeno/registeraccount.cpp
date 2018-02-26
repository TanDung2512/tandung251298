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


void RegisterAccount::on_ButtonFinish_clicked()
{

        QString SSNInFile;
        QString temp,temp2;

        QString UserName=ui->TxtUserName->toPlainText();
        QString SSN=ui->TxtSSN->toPlainText();

        QFile fileTXT_ID(ID_User+".txt");
        if(fileTXT_ID.open(QIODevice::ReadOnly)){
            QTextStream out(&fileTXT_ID);
            temp=out.readLine();
            temp2=out.readLine();
            SSNInFile=out.readLine();

            fileTXT_ID.close();
            if(SSNInFile==SSN){
                QString AccountName=ui->TxtAccountName->toPlainText();
                QString Password1=ui->TxtPass->toPlainText();
                QString PasswordConfirm =ui->TxtPassConfirm->toPlainText();


                if(Password1==PasswordConfirm){
                    //chuyển từ password sáng chuỗi hash
                    SHA_1 SHA1Pass;
                    QString PassSHAAfterConvert=SHA1Pass.SHA(Password);

                    QFile s(AccountID+".txt");



//                    s.close();
//                    }
//                }
//                else
//                {
//                    qWarning("pass is not the same with pass confirm, please input again");
//                    ui->TxtPass->clear();
//                    ui->TxtPassConfirm->clear();
//                }

//            }
//            else {
//                qWarning("Security code is not matching,please input again");
//                ui->TxtSSN->clear();
//            }

//        }
//        else {
//            qWarning("User didnt exsist");
//        }


}
