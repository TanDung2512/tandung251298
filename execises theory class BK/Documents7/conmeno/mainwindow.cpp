#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"register.h"
#include"info.h"
#include<QFileInfo>
#include<QDir>
#include "search.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
Account *acc;
Book *Show_Book;
void MainWindow::on_Loginbtn_clicked()
{
    QString Account_Name = ui->AccountEdit->text();
    QString Account_Pass = ui->PassEdit->text();
    QFile login("Acc/"+Account_Name+".txt");
    QString RightPass;
    if(!login.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"Warning","Account Not Found!");
        ui->AccountEdit->clear();
        ui->PassEdit->clear();
    }else{
        QTextStream ReadAcc(&login);
        QString trash = ReadAcc.readLine();
        RightPass = ReadAcc.readLine();
        SHA_1 SHA1Pass;
        QString PassSHAAfterConvert=SHA1Pass.SHA1(Account_Pass);

        if(PassSHAAfterConvert == RightPass){

            QMessageBox::warning(this,"Sucess","OK!");
            acc = new Account(Account_Name);
            acc->SetAccout();
            ui->stackedWidget->setCurrentIndex(1);
            ui->groupBox_2->hide();
            ui->Name->setText("Name: " + acc->user->User_Name);
            ui->ID->setText("ID: " + acc->user->User_ID);
            ui->AccName->setText("Account: " + acc->Account_Name);
            QString Showbook[10];
            QFile ListShow("System/BookHot.txt");
            ListShow.open(QIODevice::ReadOnly);
            QTextStream Listin(&ListShow);
            for(int i = 0; i <10; i ++){
                Showbook[i] = Listin.readLine();
            }
            ListShow.close();
            Show_Book = new Book[10];
            for(int i =0; i < 10; i ++){
                Show_Book[i].load(Showbook[i]);
            }
            ui->BookShow->setText(Show_Book[0].Book_Name);
            ui->BookShow_2->setText(Show_Book[1].Book_Name);
            ui->BookShow_3->setText(Show_Book[2].Book_Name);
            ui->BookShow_4->setText(Show_Book[3].Book_Name);
            ui->BookShow_5->setText(Show_Book[4].Book_Name);
            ui->BookShow_6->setText(Show_Book[5].Book_Name);
            ui->BookShow_7->setText(Show_Book[6].Book_Name);
            ui->BookShow_8->setText(Show_Book[7].Book_Name);
            ui->BookShow_9->setText(Show_Book[8].Book_Name);
            ui->BookShow_10->setText(Show_Book[9].Book_Name);
        }else{
            QMessageBox::warning(this,"Fail","Password isn't corect!");
            ui->PassEdit->clear();
        }
     }
}
void MainWindow::on_ExitBtn_clicked()
{
    this->close();
}

void MainWindow::on_LogOut_clicked()
{
    acc = new Account(acc->Account_Name);
    acc->SetNull();
    delete acc;
    ui->PassEdit->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    delete[] Show_Book;
    QString Showbook[10];
    QFile ListShow("System/BookHot.txt");
    ListShow.open(QIODevice::ReadOnly);
    QTextStream Listin(&ListShow);
    for(int i = 0; i <10; i ++){
        Showbook[i] = Listin.readLine();
    }
    ListShow.close();
    Show_Book = new Book[10];
    for(int i =0; i < 10; i ++){
        Show_Book[i].load(Showbook[i]);
    }
    ui->BookShow->setText(Show_Book[0].Book_Name);
    ui->BookShow_2->setText(Show_Book[1].Book_Name);
    ui->BookShow_3->setText(Show_Book[2].Book_Name);
    ui->BookShow_4->setText(Show_Book[3].Book_Name);
    ui->BookShow_5->setText(Show_Book[4].Book_Name);
    ui->BookShow_6->setText(Show_Book[5].Book_Name);
    ui->BookShow_7->setText(Show_Book[6].Book_Name);
    ui->BookShow_8->setText(Show_Book[7].Book_Name);
    ui->BookShow_9->setText(Show_Book[8].Book_Name);
    ui->BookShow_10->setText(Show_Book[9].Book_Name);
}

void MainWindow::on_pushButton_2_clicked()
{
    delete[] Show_Book;
    QString Showbook[10];
    QFile ListShow("System/BookList.txt");
    ListShow.open(QIODevice::ReadOnly);
    QTextStream Listin(&ListShow);
    while (!Listin.atEnd()) {
        for(int i = 9; i >0; i--){
            Showbook[i] = Showbook[i-1];
        }
        Showbook[0] = Listin.readLine();
    }
    ListShow.close();
    Show_Book = new Book[10];
    for(int i =0; i < 10; i ++){
        Show_Book[i].load(Showbook[i]);
    }
    ui->BookShow->setText(Show_Book[0].Book_Name);
    ui->BookShow_2->setText(Show_Book[1].Book_Name);
    ui->BookShow_3->setText(Show_Book[2].Book_Name);
    ui->BookShow_4->setText(Show_Book[3].Book_Name);
    ui->BookShow_5->setText(Show_Book[4].Book_Name);
    ui->BookShow_6->setText(Show_Book[5].Book_Name);
    ui->BookShow_7->setText(Show_Book[6].Book_Name);
    ui->BookShow_8->setText(Show_Book[7].Book_Name);
    ui->BookShow_9->setText(Show_Book[8].Book_Name);
    ui->BookShow_10->setText(Show_Book[9].Book_Name);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString Showbook[10];
    QFile ListShow("System/OldGoodBook.txt");
    ListShow.open(QIODevice::ReadOnly);
    QTextStream Listin(&ListShow);
    for(int i = 0; i <10; i ++){
        Showbook[i] = Listin.readLine();
    }
    ListShow.close();
    Show_Book = new Book[10];
    for(int i =0; i < 10; i ++){
        Show_Book[i].load(Showbook[i]);
    }
    ui->BookShow->setText(Show_Book[0].Book_Name);
    ui->BookShow_2->setText(Show_Book[1].Book_Name);
    ui->BookShow_3->setText(Show_Book[2].Book_Name);
    ui->BookShow_4->setText(Show_Book[3].Book_Name);
    ui->BookShow_5->setText(Show_Book[4].Book_Name);
    ui->BookShow_6->setText(Show_Book[5].Book_Name);
    ui->BookShow_7->setText(Show_Book[6].Book_Name);
    ui->BookShow_8->setText(Show_Book[7].Book_Name);
    ui->BookShow_9->setText(Show_Book[8].Book_Name);
    ui->BookShow_10->setText(Show_Book[9].Book_Name);
}
int CurreentBook;
void MainWindow::on_BookShow_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[0].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[0].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[0].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[0].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[0].Discribe);
    CurreentBook = 0;
}

void MainWindow::on_BookShow_2_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[1].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[1].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[1].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[1].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[1].Discribe);
    CurreentBook = 1;
}

void MainWindow::on_BookShow_3_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[2].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[2].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[2].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[2].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[2].Discribe);
    CurreentBook = 2;
}

void MainWindow::on_BookShow_4_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[3].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[3].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[3].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[3].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[3].Discribe);
    CurreentBook = 3;
}

void MainWindow::on_BookShow_5_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[4].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[4].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[4].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[4].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[4].Discribe);
    CurreentBook = 4;
}

void MainWindow::on_BookShow_6_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[5].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[5].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[5].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[5].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[5].Discribe);
    CurreentBook = 5;
}

void MainWindow::on_BookShow_7_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[6].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[6].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[6].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[6].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[6].Discribe);
    CurreentBook = 6;
}

void MainWindow::on_BookShow_8_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[7].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[7].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[7].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[7].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[7].Discribe);
    CurreentBook = 7;
}

void MainWindow::on_BookShow_9_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[8].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[8].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[8].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[8].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[8].Discribe);
    CurreentBook = 8;
}

void MainWindow::on_BookShow_10_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[9].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[9].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[9].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[9].Rate);
    ui->BookDes->setText("Discribe: " + Show_Book[9].Discribe);
    CurreentBook = 9;
}

void MainWindow::on_Registerbtn_clicked()
{
    Register R;
    R.setModal(true);
    R.exec();
}

void MainWindow::on_ChangeInfo_clicked()
{
    info I;
    I.setModal(true);
    I.exec();
}

void MainWindow::on_OK_clicked()
{
    acc = new Account(acc->Account_Name);
    ui->Name->setText("Name: " + acc->user->User_Name);
    ui->ID->setText("ID: " + acc->User_ID);
    ui->AccName->setText("Account: " + acc->Account_Name);
    ui->groupBox_2->hide();
    ui->pushButton_4->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->hide();
    ui->groupBox_2->show();
}

void MainWindow::on_Cart_clicked()
{

}

void MainWindow::on_AddCart_clicked()
{
    {
        QString txtName =ui->BookName->text();
        txtName.remove(0,6);
        for(int i=0;i<10;i++){
            if(txtName==Show_Book[i].Book_Name){
                QFile CartFile ("System/Cart.txt");
                QTextStream writeCart(&CartFile);
               if( CartFile.open(QIODevice::WriteOnly)){

                writeCart<<Show_Book[i].Book_ID;
               ui->listWidget->addItem(Show_Book[i].Book_Name);
               CartFile.close();}
               else QMessageBox::warning(this,"Title","Cannot save");
                break;
            }
        }
}}

void MainWindow::on_Search_clicked()
{
    Search m;
    m.setModal(true);
    m.exec();
}
