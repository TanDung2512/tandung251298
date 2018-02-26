#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"register.h"
#include"info.h"
#include <QFile>
#include <QTextStream>
#include <string>
#include <sstream>
bool logincheck = false;
Account *acc;
Book *Show_Book;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->addItem("Search by Name");
    ui->comboBox->addItem("Search by Author");
    ui->comboBox->addItem("Search by describe");
    ui->Gtcartfromsearch->setDisabled(true);
    QString ShowbookMain[10];
    QFile ListShowMain("System/BookHot.txt");
    ListShowMain.open(QIODevice::ReadOnly);
    QTextStream ListinMain(&ListShowMain);
    for(int i = 0; i <10; i ++){
        ShowbookMain[i] = ListinMain.readLine();
    }
    ListShowMain.close();
    Show_Book = new Book[10];
    for(int i =0; i < 10; i ++){
        Show_Book[i].load(ShowbookMain[i]);
    }
    ui->BookShow_11->setText(Show_Book[0].Book_Name);
    ui->BookShow_12->setText(Show_Book[1].Book_Name);
    ui->BookShow_13->setText(Show_Book[2].Book_Name);
    ui->BookShow_14->setText(Show_Book[3].Book_Name);
    ui->BookShow_15->setText(Show_Book[4].Book_Name);
    ui->BookShow_16->setText(Show_Book[5].Book_Name);
    ui->BookShow_17->setText(Show_Book[6].Book_Name);
    ui->BookShow_18->setText(Show_Book[7].Book_Name);
    ui->BookShow_19->setText(Show_Book[8].Book_Name);
    ui->BookShow_20->setText(Show_Book[9].Book_Name);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

        sha256 hashpassword;
        QString hash=hashpassword.SHA256(Account_Pass.toStdString());
        if(hash == RightPass){
            QMessageBox::warning(this,"Sucess","OK!");
            logincheck = true;
            ui->Gtcartfromsearch->setEnabled(true);
            acc = new Account(Account_Name);
            acc->SetAccout();
            ui->stackedWidget->setCurrentIndex(1);
            ui->groupBox_2->hide();
            ui->pushButton_4->show();
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
            delete[] Show_Book;
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
            if (acc->Role[2] == "True") {
                ui->AdminTab->setEnabled(true);
                ui->Reader111->setEnabled(true);
            }else{
                ui->AdminTab->setDisabled(true);
                ui->Reader111->setDisabled(true);
            }
            if (acc->Role[1] == "True"){
                ui->blirarian->setEnabled(true);
                ui->blirarian_2->setEnabled(true);
            }else{
                ui->blirarian->setDisabled(true);
                ui->blirarian_2->setDisabled(true);
            }
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
    logincheck = false;
    ui->Gtcartfromsearch->setDisabled(true);
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
    delete[] Show_Book;
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
void MainWindow::Showbook(int i){
    ui->BookName_3->setText("Name: " + Show_Book[i].Book_Name);
    ui->BookAuthor_3->setText("Author: " + Show_Book[i].Book_Author);
    ui->BookType_3->setText("Type: " + Show_Book[i].Book_Type);
    ui->BookRate_3->setText("ID: " + Show_Book[i].Book_ID);
    ui->BookDes_3->setText("Discribe: " + Show_Book[i].Discribe);
    CurreentBook = i;
}
void MainWindow::on_BookShow_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[0].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[0].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[0].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[0].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[0].Discribe);
    CurreentBook = 0;
}

void MainWindow::on_BookShow_2_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[1].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[1].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[1].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[1].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[1].Discribe);
    CurreentBook = 1;
}

void MainWindow::on_BookShow_3_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[2].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[2].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[2].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[2].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[2].Discribe);
    CurreentBook = 2;
}

void MainWindow::on_BookShow_4_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[3].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[3].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[3].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[3].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[3].Discribe);
    CurreentBook = 3;
}

void MainWindow::on_BookShow_5_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[4].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[4].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[4].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[4].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[4].Discribe);
    CurreentBook = 4;
}

void MainWindow::on_BookShow_6_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[5].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[5].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[5].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[5].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[5].Discribe);
    CurreentBook = 5;
}

void MainWindow::on_BookShow_7_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[6].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[6].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[6].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[6].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[6].Discribe);
    CurreentBook = 6;
}

void MainWindow::on_BookShow_8_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[7].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[7].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[7].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[7].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[7].Discribe);
    CurreentBook = 7;
}

void MainWindow::on_BookShow_9_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[8].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[8].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[8].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[8].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[8].Discribe);
    CurreentBook = 8;
}

void MainWindow::on_BookShow_10_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[9].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[9].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[9].Book_Type);
    ui->BookRate->setText("ID: " + Show_Book[9].Book_ID);
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

void MainWindow::on_AdminTab_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QDir Dir("Acc/");
    Dir.setFilter(QDir::Files|QDir::NoDotAndDotDot);
    mylist = Dir.entryList();
    ui->listWidget->addItems(mylist);
    //ui->Total->setText(QString("%1").arg(ui->listWidget->count()));
    ui->Name_2->setText("Name: " + acc->user->User_Name);
    ui->ID_2->setText("ID: " + acc->User_ID);
    ui->AccName_2->setText("Account: " + acc->Account_Name);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QRegExp Find(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
        ui->listWidget->clear();
        ui->listWidget->addItems(mylist.filter(Find));
        //ui->Total->setText(QString("Total: %1").arg(ui->listWidget->count()));
}
Account *Sacc;
void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    Sacc = new Account(item->text().left(item->text().length()-4));
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem("Name: " + Sacc->user->User_Name);
    ui->listWidget_2->addItem("ID: " + Sacc->User_ID);
    ui->listWidget_2->addItem("SSN: " + Sacc->user->User_SSN);
    ui->listWidget_2->addItem("BirthDay " + Sacc->user->User_Birth_day + "/" + Sacc->user->User_Birth_month + "/" + Sacc->user->User_Birth_year);
    ui->listWidget_2->addItem("Job: " + Sacc->user->User_Opcu);
    ui->listWidget_2->addItem("Email: " + Sacc->user->User_Email);
    ui->listWidget_2->addItem("Account: " + Sacc->Account_Name);
    ui->listWidget_2->addItem("Acc ID: " + Sacc->Account_ID);
    ui->listWidget_2->addItem("Reader: " + Sacc->Role[0]);
    ui->listWidget_2->addItem("Blirarian: " + Sacc->Role[1]);
    ui->listWidget_2->addItem("Admin: " + Sacc->Role[2]);
}

void MainWindow::on_pushButton_6_clicked()
{
    Sacc->password = "1";
    QMessageBox::warning(this,"OK","Password has been reset to 1");
    delete Sacc;
}

void MainWindow::on_Exit_clicked()
{
    acc = new Account(acc->Account_Name);
    acc->SetNull();
    delete acc;
    ui->PassEdit->clear();
    ui->stackedWidget->setCurrentIndex(0);
    logincheck = false;
    ui->Gtcartfromsearch->setDisabled(true);
}

void MainWindow::on_Reader_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->listWidget->clear();
}

void MainWindow::on_blirarian_clicked()
{
    ui->listWidget_4->clear();
    ui->listWidget_7->clear();
    ui->listWidget_8->clear();
    ui->listWidget_3->clear();
    ui->stackedWidget->setCurrentIndex(3);
        QFile RequiredBook("Librarian/RequiredBook/RequiredBookList.txt");
        QTextStream ReadFile (&RequiredBook);
        RequiredBook.open(QIODevice::ReadOnly);
        QString ReadBook;
        while(!ReadFile.atEnd()){
            ReadBook=RequiredBook.readLine();
            ui->listWidget_3->addItem(ReadBook);
        }
        RequiredBook.close();
        ui->Name_3->setText("Name: " + acc->user->User_Name);
        ui->ID_3->setText("ID: " + acc->user->User_ID);
        ui->AccName_3->setText("Account: " + acc->Account_Name);
        QDir Dir1("Book/");
        Dir1.setFilter(QDir::Files|QDir::NoDotAndDotDot);
        mylist1 = Dir1.entryList();
        ui->listWidget_7->addItems(mylist1);
        for(int i = 0; i < mylist1.length(); i ++){
            Book conmeno;
            //QMessageBox::warning(this,"â",ui->listWidget_7->item(i)->text().left(4));
            conmeno.load(ui->listWidget_7->item(i)->text().left(4));
            ui->listWidget_8->addItem(conmeno.Book_Name);
        }

}

void MainWindow::on_listWidget_3_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_4->clear();
    QFile BookRequiredFromAcc("Librarian/RequiredBook/"+item->text()+".txt");
        QTextStream WriteBookRequiredFromAcc(&BookRequiredFromAcc);
        BookRequiredFromAcc.open(QIODevice::ReadOnly);
        Book *Show_Book;
        QString GetIDBook;
        Show_Book=new Book[1];
        while(!WriteBookRequiredFromAcc.atEnd()){
        GetIDBook=WriteBookRequiredFromAcc.readLine();
        Show_Book->load(GetIDBook);
        ui->listWidget_4->addItem(Show_Book->Book_Name);
    //    ui->RequiredBook1->addItem("Author: "+Show_Book.Book_Author);
    //    ui->RequiredBook1->addItem("Type: " + Show_Book.Book_Type);
    //    ui->RequiredBook1->addItem("Rate: " + Show_Book.Rate);
    //    ui->RequiredBook1->addItem("Book ID: " + Show_Book.Book_ID);
    //    ui->RequiredBook1->addItem("Discribe: " + Show_Book.Discribe);
         }
        BookRequiredFromAcc.close();
}

void MainWindow::on_blirarian_2_clicked()
{
    ui->listWidget_4->clear();
    ui->listWidget_7->clear();
    ui->listWidget_8->clear();
    ui->listWidget_3->clear();
    ui->stackedWidget->setCurrentIndex(3);
        QFile RequiredBook("Librarian/RequiredBook/RequiredBookList.txt");
        QTextStream ReadFile (&RequiredBook);
        RequiredBook.open(QIODevice::ReadOnly);
        QString ReadBook;
        while(!ReadFile.atEnd()){
            ReadBook = RequiredBook.readLine();
            ui->listWidget_3->addItem(ReadBook.left(ReadBook.length()-1));
        }
        RequiredBook.close();
        ui->Name_3->setText("Name: " + acc->user->User_Name);
        ui->ID_3->setText("ID: " + acc->user->User_ID);
        ui->AccName_3->setText("Account: " + acc->Account_Name);
        QDir Dir1("Book/");
        Dir1.setFilter(QDir::Files|QDir::NoDotAndDotDot);
        mylist1 = Dir1.entryList();
        ui->listWidget_7->addItems(mylist1);
        for(int i = 0; i < mylist1.length(); i ++){
            Book conmeno;
            //QMessageBox::warning(this,"â",ui->listWidget_7->item(i)->text().left(4));
            conmeno.load(ui->listWidget_7->item(i)->text().left(4));
            ui->listWidget_8->addItem(conmeno.Book_Name);
        }
}

void MainWindow::on_Reader111_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QDir Dir("Acc/");
    Dir.setFilter(QDir::Files|QDir::NoDotAndDotDot);
    mylist = Dir.entryList();
    ui->listWidget->addItems(mylist);
    //ui->Total->setText(QString("%1").arg(ui->listWidget->count()));
    ui->Name_2->setText("Name: " + acc->user->User_Name);
    ui->ID_2->setText("ID: " + acc->User_ID);
    ui->AccName_2->setText("Account: " + acc->Account_Name);
}

void MainWindow::on_Admin111_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_logoutblirarian_clicked()
{
    acc = new Account(acc->Account_Name);
    acc->SetNull();
    delete acc;
    ui->PassEdit->clear();
    ui->stackedWidget->setCurrentIndex(0);
    logincheck = false;
    ui->Gtcartfromsearch->setDisabled(true);
}
int cartbook;
void MainWindow::on_pushButton_5_clicked()
{
    //QString txtName =ui->BookRate->text();
    //        txtName.remove(0,8);
    ui->listWidget_5->addItem(ui->BookRate->text().remove(0,4)+". "+ ui->BookName->text().remove(0,6));
    cartbook++;
    //CartFile.close();}
}

void MainWindow::on_Cart_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_listWidget_5_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_6->clear();
    Book Bookcart;
    QString bookid;
    //QMessageBox::warning(this,"this",item->text().left(4));
    bookid = item->text().left(4);
    Bookcart.load(bookid);
    ui->listWidget_6->addItem("Name: "+ Bookcart.Book_Name);
    ui->listWidget_6->addItem("Type: "+ Bookcart.Book_Type);
    ui->listWidget_6->addItem("ID: "+ Bookcart.Book_ID);
    ui->listWidget_6->addItem("Rate: "+ Bookcart.Rate);
    ui->listWidget_6->addItem("Author: "+ Bookcart.Book_Author);
    ui->listWidget_6->addItem("Discribe: "+ Bookcart.Discribe);
}

void MainWindow::on_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_listWidget_6_itemClicked(QListWidgetItem *item)
{

}

void MainWindow::on_listWidget_5_itemDoubleClicked(QListWidgetItem *item)
{
    item->setHidden(true);
    cartbook--;
}

void MainWindow::on_pushButton_8_clicked()
{
    QFile CartFile ("Librarian/RequiredBook/"+ui->Name->text().remove(0,5)+".txt");
    QTextStream writeCart(&CartFile);
    if( CartFile.open(QIODevice::WriteOnly)){
        for(int i = 0; i < cartbook;i++){
            writeCart<< ui->listWidget_5->item(i)->text().left(4) << endl;
        }
    }
    else QMessageBox::warning(this,"Title","Cannot save");
    CartFile.close();
    QFile CartName ("Librarian/RequiredBook/RequiredBookList.txt");
    QTextStream WriteCartName(&CartName);
    CartName.open(QIODevice::Append);
        WriteCartName << ui->Name->text().remove(0,5) << endl;
    CartName.close();
}

void MainWindow::on_accept_clicked()
{
    QString listofrequest[1000];
    QFile listrequest("Librarian/RequiredBook/RequiredBookList.txt");
    QTextStream required(&listrequest);
    int count = 0;
    listrequest.open(QIODevice::ReadOnly);
    while (!required.atEnd()) {
        listofrequest[count] = required.readLine();
        count++;
    }
    listrequest.close();
    QFile writelist("Librarian/RequiredBook/RequiredBookList.txt");
    QTextStream writere(&writelist);
    writelist.open(QIODevice::WriteOnly);
    for(int i = 0; i < count; i ++){
        if(listofrequest[i] != ui->listWidget_3->currentItem()->text()){
            writere << listofrequest[i] << endl;
        }
    }
    writelist.close();
    QFile de("Librarian/RequiredBook/" + ui->listWidget_3->currentItem()->text() + ".txt");
    de.remove();
}

void MainWindow::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    QRegExp Find(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
        ui->listWidget_7->clear();
        ui->listWidget_7->addItems(mylist1.filter(Find));
        ui->listWidget_8->clear();
        //ui->listWidget_8->addItems(mylist2);
        for(int i = 0; i < ui->listWidget_7->count(); i ++){
            Book conmeno;
            //QMessageBox::warning(this,"â",ui->listWidget_7->item(i)->text().left(4));
            conmeno.load(ui->listWidget_7->item(i)->text().left(4));
            ui->listWidget_8->addItem(conmeno.Book_Name);
}
}

void MainWindow::on_pushButton_7_clicked()
{
    QFile Xoa("Book/" + ui->listWidget_7->currentItem()->text());
    Xoa.remove();
    QFile XoaTrongList("System/BookList.txt");
    QTextStream doc(&XoaTrongList);
    QString *danhsach = new QString[10000], trash;
    int sosach = 0;
    XoaTrongList.open(QIODevice::ReadOnly);
    while (!doc.atEnd()) {
        danhsach[sosach] = doc.readLine();
        sosach ++;
    }
    QFile XoaTrongList1("System/BookList.txt");
    XoaTrongList1.open(QIODevice::WriteOnly);
    QTextStream ghide(&XoaTrongList1);
    for(int i = 0; i < sosach; i ++){
        if(danhsach[i] != ui->listWidget_7->currentItem()->text().left(4)){
            ghide << danhsach[i] << endl;
            QMessageBox::warning(this,"ba", danhsach[i]);
        }
    }
    XoaTrongList1.close();
    delete[] danhsach;
}
#include "changebook.h"
void MainWindow::on_pushButton_9_clicked()
{
    QFile chonsach("System/SeclectedBook.txt");
    chonsach.open(QIODevice::WriteOnly);
    QTextStream ghi(&chonsach);
    ghi << ui->listWidget_7->currentItem()->text().left(4);
    chonsach.close();
    changeBook C;
    C.setModal(true);
    C.exec();
}
#include "addbook.h"
void MainWindow::on_Admin111_2_clicked()
{
    Addbook A;
    A.setModal(true);
    A.exec();
}

Book *listBookQString ;
QString a;
struct StringListBook{
   string Book_Name;
   string Book_Author;
   string Book_ID;
   string Book_Describe;
   int CountDistance;
   StringListBook &operator=(const StringListBook &copy);
};
StringListBook &StringListBook::operator=(const StringListBook &copy){
   this->Book_Name=copy.Book_Name;
   this->Book_ID=copy.Book_ID;
   this->Book_Author=copy.Book_Author;
   this->Book_Describe=copy.Book_Describe;
   this->CountDistance=copy.CountDistance;
   return *this;
};

class algorithm{
   int min(int a[]){
       int small=a[0];

       if (small>a[1]) {
           small=a[1];
       }
       if(small>a[2]){
           small=a[2];
       }
       return small;
   }

   void swap (StringListBook &a,StringListBook &b,Book &a1,Book &a2){
       StringListBook temp;
       Book tempBook;
       temp =a;
       a=b;
       b=temp;
       tempBook =a1;
       a1=a2;
       a2=tempBook;
   }
public:
   // hàm levenstein . nhập 2 chuỗi ký tự bất kỳ để tim được khoảng cách khác nhau
   int levenstein_distance(string a,string b){
       int m=(int)a.length();              // độ dài của 2 chuỗi ký tự
       int n=(int)b.length();

       int **array;
       array=new int*[m+1];
       for(int i=0;i<m+1;i++){
           array[i]=new int[n+1];
       }
       int temp;
       int arraycompare[3]; // ma trận để so sánh tim bé nhỏ nhất trong 3 thằng


       for (int i=0; i<=m; i++) {
           array[i][0]=i;                  //gắn giá trị ở cột đầu của ma trận
       }
       for (int i=0; i<=n; i++) {
           array[0][i]=i;                  // gắn giá trị ở hàng đầu của ma trận
       }
         for (int i=1; i<=m; i++) {
           for (int j=1; j<=n; j++) {         // duyệt từng phần tử trong mảng array để so sách các ký tự
               if (a[i-1]==b[j-1]) {
                   temp=0;
               }
               else
                   temp=1;

               arraycompare[0]=array[i-1][j-1]+temp;
               arraycompare[1]=array[i-1][j]+1;
               arraycompare[2]=array[i][j-1]+1;
               array[i][j]=min(arraycompare);
           }

       }
   //    for (int i=0; i<=m; i++) {
   //        for (int j=0; j<=n; j++) {
   //            cout<<array[i][j]<<" ";           // xuất ra ma trận nếu mày muốn :D
   //        }
   //        cout<<endl;
   //    }
       return array[m][n];
   }
   void QuickSort(StringListBook array[],Book array1[],int left,int right){
       int i=left,j=right;
       int middle = array[(j+i)/2].CountDistance;
       do{
       while(array[i].CountDistance<middle && i<right){
           i++;
       }
       while (array[j].CountDistance>middle&& j>left){
           j--;
       }
       if(i<=j){
           swap(array[i],array[j],array1[i],array1[j]);
           i++;j--;
       }
       }while (i<=j);
      if(i<right){
          QuickSort(array,array1,i,right);
      }
      if(j>left){
          QuickSort(array,array1,left,j);
      }
   }
};
void MainWindow::on_pushButton_10_clicked()
{
        QString txtSearchQString=ui->txtSearch->text();
        string txtSearchString =txtSearchQString.toStdString();

        QFile file("System/BookList.txt");
        QTextStream InBookList(&file);
        file.open(QIODevice::ReadOnly);

        int count =0;
                QString *emyeu;
               emyeu=new QString[1];
        while(!InBookList.atEnd()){
            *emyeu=InBookList.readLine();
            count++;
        }
        file.close();
        listBookQString =new Book[count];
        StringListBook  *lisBookString;
       lisBookString =new StringListBook [count];

       for  (int i=0;i<count;i++){
           file.open(QIODevice::ReadOnly);
           *emyeu=InBookList.readLine();
           listBookQString[i].load(*emyeu);
           lisBookString[i].Book_Name=listBookQString[i].Book_Name.toStdString();
           lisBookString[i].Book_Author=listBookQString[i].Book_Author .toStdString();
           lisBookString[i].Book_Describe=listBookQString[i].Discribe.toStdString();
           lisBookString[i].Book_ID=listBookQString[i].Book_ID.toStdString();

       }
    file.close();
       stringstream ss;
       stringstream ss1;
       int distance;
       algorithm algorithmsearch;

       if(ui->comboBox->currentText()=="Search by Name"){
          ss<<txtSearchString;
          string string_search;
         for(int i=0;i<count;i++){
             while(ss>>string_search){
                ss1<<lisBookString[i].Book_Name;
                string StringSearchFromBookList;
                while(ss1>>StringSearchFromBookList){

                    distance =algorithmsearch.levenstein_distance(string_search,StringSearchFromBookList);
                    if(distance < (unsigned int )string_search.length()){
                        distance++;
                    }
                }
             }
             lisBookString[i].CountDistance=distance;
         }
             algorithmsearch.QuickSort(lisBookString,listBookQString,0,count-1);
          for(int i=0;i<10;i++){
              ui->listWidget_9->addItem(listBookQString[i].Book_ID+"."+listBookQString[i].Book_Name);
          }

       }

       if(ui->comboBox->currentText()=="Search by Author"){
           ss<< txtSearchString;
           string string_search;
           for(int i=0;i<count;i++){
              while(ss>>string_search){
                 ss1<<lisBookString[i].Book_Author;
                 string StringSearchFromBookList;
                 while(ss1>>StringSearchFromBookList){

                     distance =algorithmsearch.levenstein_distance(string_search,StringSearchFromBookList);
                     if(distance < (unsigned int )string_search.length()){
                         distance++;
                     }
                 }
              }
              lisBookString[i].CountDistance=distance;
           }
           algorithmsearch.QuickSort(lisBookString,listBookQString,0,count-1);
           for(int i=0;i<10;i++){
               ui->listWidget_9->addItem(listBookQString[i].Book_ID+". "+listBookQString[i].Book_Name);
           }
       }
       if(ui->comboBox->currentText()=="Search by Describe"){
           ss<< txtSearchString;
           string string_search;
           for(int i=0;i<count;i++){
              while(ss>>string_search){
                 ss1<<lisBookString[i].Book_Describe;
                 string StringSearchFromBookList;
                 while(ss1>>StringSearchFromBookList){

                     distance =algorithmsearch.levenstein_distance(string_search,StringSearchFromBookList);
                     if(distance < (unsigned int )string_search.length()){
                         distance++;
                     }
                 }
              }
              lisBookString[i].CountDistance=distance;
           }
           algorithmsearch.QuickSort(lisBookString,listBookQString,0,count-1);
           for(int i=0;i<10;i++){
               ui->listWidget_9->addItem(listBookQString[i].Book_ID+". "+listBookQString[i].Book_Name);
           }

       }


}

void MainWindow::on_listWidget_9_itemClicked(QListWidgetItem *item)
{
    QString ChooseBookID;
    ChooseBookID=item->text().left(4);
    Book BookChoose;
    BookChoose.load(ChooseBookID);
    ui->BookName_2->setText(BookChoose.Book_Name);
    ui->BookAuthor_2->setText(BookChoose.Book_Author);
    ui->BookDes_2->setText(BookChoose.Discribe);
    ui->BookRate_2->setText(BookChoose.Rate);
    ui->BookType_2->setText(BookChoose.Book_Type);
    ui->IDBook->setText(BookChoose.Book_ID);
}

void MainWindow::on_adcartsearch_clicked()
{
    if(logincheck == true){
        ui->listWidget_5->addItem(ui->IDBook->text() +". "+ ui->BookName_2->text());
        cartbook++;
    }else{
        QMessageBox::warning(this, "opp", "You need to login first");
    }
}

void MainWindow::on_Gtcartfromsearch_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_BackfromSearch_clicked()
{
    if(logincheck == true) ui->stackedWidget->setCurrentIndex(1);
    else ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_blirarian_3_clicked()
{
    QFile setcode("System/BlirarianCode.txt");
    setcode.open(QIODevice::WriteOnly);
    QTextStream codeout(&setcode);
    codeout << ui->lineEdit_3->text();
    setcode.close();
    QMessageBox::warning(this,"OK","Blirarian code has ben changed to: " + ui->lineEdit_3->text());
    ui->lineEdit_3->clear();
}

void MainWindow::on_blirarian_4_clicked()
{

    QFile setcode1("System/AdminPass.txt");
    setcode1.open(QIODevice::WriteOnly);
    QTextStream codeout1(&setcode1);
    codeout1 << ui->lineEdit_4->text();
    setcode1.close();
    QMessageBox::warning(this,"OK","Admin password has ben changed to: " + ui->lineEdit_4->text());
    ui->lineEdit_4->clear();
}

void MainWindow::on_SearchReader_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_12_clicked()
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
    ui->BookShow_11->setText(Show_Book[0].Book_Name);
    ui->BookShow_12->setText(Show_Book[1].Book_Name);
    ui->BookShow_13->setText(Show_Book[2].Book_Name);
    ui->BookShow_14->setText(Show_Book[3].Book_Name);
    ui->BookShow_15->setText(Show_Book[4].Book_Name);
    ui->BookShow_16->setText(Show_Book[5].Book_Name);
    ui->BookShow_17->setText(Show_Book[6].Book_Name);
    ui->BookShow_18->setText(Show_Book[7].Book_Name);
    ui->BookShow_19->setText(Show_Book[8].Book_Name);
    ui->BookShow_20->setText(Show_Book[9].Book_Name);
}

void MainWindow::on_pushButton_13_clicked()
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
    ui->BookShow_11->setText(Show_Book[0].Book_Name);
    ui->BookShow_12->setText(Show_Book[1].Book_Name);
    ui->BookShow_13->setText(Show_Book[2].Book_Name);
    ui->BookShow_14->setText(Show_Book[3].Book_Name);
    ui->BookShow_15->setText(Show_Book[4].Book_Name);
    ui->BookShow_16->setText(Show_Book[5].Book_Name);
    ui->BookShow_17->setText(Show_Book[6].Book_Name);
    ui->BookShow_18->setText(Show_Book[7].Book_Name);
    ui->BookShow_19->setText(Show_Book[8].Book_Name);
    ui->BookShow_20->setText(Show_Book[9].Book_Name);
}

void MainWindow::on_pushButton_14_clicked()
{
    delete[] Show_Book;
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
    ui->BookShow_11->setText(Show_Book[0].Book_Name);
    ui->BookShow_12->setText(Show_Book[1].Book_Name);
    ui->BookShow_13->setText(Show_Book[2].Book_Name);
    ui->BookShow_14->setText(Show_Book[3].Book_Name);
    ui->BookShow_15->setText(Show_Book[4].Book_Name);
    ui->BookShow_16->setText(Show_Book[5].Book_Name);
    ui->BookShow_17->setText(Show_Book[6].Book_Name);
    ui->BookShow_18->setText(Show_Book[7].Book_Name);
    ui->BookShow_19->setText(Show_Book[8].Book_Name);
    ui->BookShow_20->setText(Show_Book[9].Book_Name);
}

void MainWindow::on_BookShow_11_clicked()
{
    Showbook(0);
}

void MainWindow::on_BookShow_12_clicked()
{
    Showbook(1);
}

void MainWindow::on_BookShow_13_clicked()
{
    Showbook(2);
}

void MainWindow::on_BookShow_14_clicked()
{
    Showbook(3);
}

void MainWindow::on_BookShow_15_clicked()
{
    Showbook(4);
}

void MainWindow::on_BookShow_16_clicked()
{
    Showbook(5);
}

void MainWindow::on_BookShow_17_clicked()
{
    Showbook(6);
}

void MainWindow::on_BookShow_18_clicked()
{
    Showbook(7);
}

void MainWindow::on_BookShow_19_clicked()
{
    Showbook(8);
}

void MainWindow::on_BookShow_20_clicked()
{
    Showbook(9);
}
