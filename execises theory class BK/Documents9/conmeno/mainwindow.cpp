#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"register.h"
#include"info.h"
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

        sha256 hashpassword;
        QString hash=hashpassword.SHA256(Account_Pass.toStdString());

        if(hash == RightPass){
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
            if (acc->Role[2] == "True") ui->AdminTab->show();
            else ui->AdminTab->hide();
            ui->LibrarianTab->show();
//            if (acc->Role[1] == "True") ui->LibrarianTab->show();
//            else ui->LibrarianTab->hide();

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
    ui->BookID->setText("Book ID: " + Show_Book[0].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[0].Discribe);
    CurreentBook = 0;
}

void MainWindow::on_BookShow_2_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[1].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[1].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[1].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[1].Rate);
    ui->BookID->setText("Book ID: " + Show_Book[1].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[1].Discribe);
    CurreentBook = 1;
}

void MainWindow::on_BookShow_3_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[2].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[2].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[2].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[2].Rate);
    ui->BookID->setText("Book ID: " + Show_Book[2].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[2].Discribe);
    CurreentBook = 2;
}

void MainWindow::on_BookShow_4_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[3].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[3].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[3].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[3].Rate);
    ui->BookID->setText("Book ID: " + Show_Book[3].Book_ID);

    ui->BookDes->setText("Discribe: " + Show_Book[3].Discribe);
    CurreentBook = 3;
}

void MainWindow::on_BookShow_5_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[4].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[4].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[4].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[4].Rate);
    ui->BookID->setText("Book ID: " + Show_Book[4].Book_ID);

    ui->BookDes->setText("Discribe: " + Show_Book[4].Discribe);
    CurreentBook = 4;
}

void MainWindow::on_BookShow_6_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[5].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[5].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[5].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[5].Rate);
    ui->BookID->setText("Book ID: " + Show_Book[5].Book_ID);

    ui->BookDes->setText("Discribe: " + Show_Book[5].Discribe);
    CurreentBook = 5;
}

void MainWindow::on_BookShow_7_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[6].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[6].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[6].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[6].Rate);
    ui->BookID->setText("Book ID: " + Show_Book[6].Book_ID);
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
    ui->BookID->setText("Book ID: " + Show_Book[7].Book_ID);

    CurreentBook = 7;
}

void MainWindow::on_BookShow_9_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[8].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[8].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[8].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[8].Rate);
    ui->BookID->setText("Book ID: " + Show_Book[8].Book_ID);
    ui->BookDes->setText("Discribe: " + Show_Book[8].Discribe);
    CurreentBook = 8;
}

void MainWindow::on_BookShow_10_clicked()
{
    ui->BookName->setText("Name: " + Show_Book[9].Book_Name);
    ui->BookAuthor->setText("Author: " + Show_Book[9].Book_Author);
    ui->BookType->setText("Type: " + Show_Book[9].Book_Type);
    ui->BookRate->setText("Rate: " + Show_Book[9].Rate);
    ui->BookID->setText("Book ID: " + Show_Book[9].Book_ID);
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
    close();
}

void MainWindow::on_Reader_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->listWidget->clear();
}

void MainWindow::on_Cart_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_AddCart_clicked()
{
    {
        QString txtName =ui->BookID->text();
        txtName.remove(0,8);

                QFile CartFile ("Cart/"+ui->Name->text().remove(0,5)+".txt");
                QTextStream writeCart(&CartFile);
                if( CartFile.open(QIODevice::Append)){
                writeCart<<ui->BookID->text().remove(0,8)<<endl;
                ui->listWidget_4->addItem(ui->BookID->text().remove(0,9)+". "+ ui->BookName->text().remove(0,5));
                CartFile.close();}
                else QMessageBox::warning(this,"Title","Cannot save");

    }
}

void MainWindow::on_Search_clicked()
{
    Search m;
    m.setModal(true);
    m.exec();
}
void MainWindow::on_WatchBook_4_clicked()
{
    QFile SubBook ("Librarian/RequiredBook/RequiredBookList.txt");
    QTextStream Sub(&SubBook);
    QString Check;
    int count=0;
    if(SubBook.open(QIODevice::ReadOnly)){
        while  (!Sub.atEnd())
        {
               Check=Sub.readLine();
               if(Check==ui->Name->text().remove(0,6)){
                   count++;
               }
        }
         SubBook.close();
    }
    else QMessageBox::warning(this,"title","cannot open file1");
    if(count==0){
    if(SubBook.open(QIODevice::WriteOnly | QIODevice::Append)){
        Sub<<ui->Name->text().remove(0,6)<<endl;
         SubBook.close();
    }
    else QMessageBox::warning(this,"title","cannot open file2");
    }
    QListWidgetItem *a= ui->listWidget_4->currentItem();
    QFile BookRequiredFromAcc("Librarian/RequiredBook/"+ui->Name->text().remove(0,6)+".txt");
    QTextStream WriteBookRequiredFromAcc(&BookRequiredFromAcc);
    if(BookRequiredFromAcc.open(QIODevice::WriteOnly | QIODevice::Append)){
        WriteBookRequiredFromAcc<<a->text().left(4)<<endl;
         BookRequiredFromAcc.close();
    }
}
void MainWindow::on_LibrarianTab_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QFile RequiredBook("Librarian/RequiredBook/RequiredBookList.txt");
    QTextStream ReadFile (&RequiredBook);
    RequiredBook.open(QIODevice::ReadOnly);
    QString ReadBook;
    while(!ReadFile.atEnd()){
        ReadBook=RequiredBook.readLine();
        ui->RequiredBook->addItem(ReadBook);
    }
    RequiredBook.close();
}
void MainWindow::on_listWidget_4_itemClicked(QListWidgetItem *item)
{
    QString temp;
    Book BookCart;
    BookCart.load(item->text().left(4));
    ui->BookName_4->setText(BookCart.Book_Name);
    ui->BookAuthor_4->setText(BookCart.Book_Author);
    ui->BookDes_4->setText(BookCart.Discribe);
    ui->BookRate_4->setText(BookCart.Num_of_rating);
    ui->BookType_4->setText(BookCart.Book_Type);
    ui->BookID_3->setText(BookCart.Book_ID);

}
void MainWindow::on_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_RequiredBook_itemClicked(QListWidgetItem *item)
{
    QFile BookRequiredFromAcc("Librarian/RequiredBook/"+item->text()+".txt");
    QTextStream WriteBookRequiredFromAcc(&BookRequiredFromAcc);
    BookRequiredFromAcc.open(QIODevice::ReadOnly);
    Book *Show_Book;
    QString GetIDBook;
    Show_Book=new Book[1];
    while(!WriteBookRequiredFromAcc.atEnd()){
    GetIDBook=WriteBookRequiredFromAcc.readLine();
    Show_Book->load(GetIDBook);
    ui->RequiredBook1->addItem(Show_Book->Book_Name);
//    ui->RequiredBook1->addItem("Author: "+Show_Book.Book_Author);
//    ui->RequiredBook1->addItem("Type: " + Show_Book.Book_Type);
//    ui->RequiredBook1->addItem("Rate: " + Show_Book.Rate);
//    ui->RequiredBook1->addItem("Book ID: " + Show_Book.Book_ID);
//    ui->RequiredBook1->addItem("Discribe: " + Show_Book.Discribe);
     }
    BookRequiredFromAcc.close();
}
