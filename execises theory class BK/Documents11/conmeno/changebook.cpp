#include "changebook.h"
#include "ui_changebook.h"
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
        book.close();
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
};

Book Bookchange;
changeBook::changeBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeBook)
{
    ui->setupUi(this);
    QFile sachsua("System/SeclectedBook.txt");
    sachsua.open(QIODevice::ReadOnly);
    QTextStream docsach(&sachsua);
    QString id = docsach.readLine();
    sachsua.close();
    Bookchange.load(id);
    ui->lineEdit->setText(Bookchange.Book_Name);
    ui->lineEdit_2->setText(Bookchange.Book_Type);
    ui->lineEdit_3->setText(Bookchange.Book_Author);
    ui->lineEdit_4->setText(Bookchange.Discribe);
}

changeBook::~changeBook()
{
    delete ui;
}

void changeBook::on_pushButton_clicked()
{
    Bookchange.Book_Name = ui->lineEdit->text();
    Bookchange.Book_Type = ui->lineEdit_2->text();
    Bookchange.Book_Author = ui->lineEdit_3->text();
    Bookchange.Discribe = ui->lineEdit_4->text();
    QFile book("Book/" +Bookchange.Book_ID+".txt");
    book.open(QIODevice::WriteOnly);
    QTextStream out(&book);
    out << Bookchange.Book_Name << endl;
    out << Bookchange.Book_Author << endl;
    out << Bookchange.Book_ID << endl;
    out << Bookchange.Book_Type << endl;
    out << Bookchange.Sum_of_rating << endl;
    out << Bookchange.Num_of_rating << endl;
    out << Bookchange.Rate << endl;
    out << Bookchange.Discribe << endl;
    book.close();
    close();
}
