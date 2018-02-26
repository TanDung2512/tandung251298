#include "search.h"
#include "ui_search.h"
#include "mainwindow.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <sstream>
#include<string>
Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    ui->comboBox->addAction("Search by name book");
    ui->comboBox->addAction("Search by name author");
    ui->comboBox->addAction("Search by Decribe");
}



struct bookliststring{
    string Book_name;
    string Book_author;
    string Book_decribe;
    string Book_ID;
    int a;
};

Book *listbookInformation;
//Book::operator=(book&& copy){

//}
Search::~Search()
{
    delete ui;
}
class levenstein{

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

    // hàm levenstein . nhập 2 chuỗi ký tự bất kỳ để tim được khoảng cách khác nhau
    int levenstein_distance(string a,string b){
        int m=(int)a.length();              // độ dài của 2 chuỗi ký tự
        int n=(int)b.length();

        int array[m+1][n+1];
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
                if (a.[(i-1]==b.[j-1]) {
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
        return array[m][n];
    }

};
void Search::on_pushButton_clicked()
{
    int count =0;
    QFile ListBook("BookList.txt");
    ListBook.open(QIODevice::ReadOnly);
    QTextStream CountBook(&ListBook);
    while(!CountBook.atEnd()){
     CountBook.readLine();
        count++;
    }
    ListBook.close();

    QString ListIDBook[count];

    ListBook(QIODevice::ReadOnly);
    for (int i=0;i<count;i++){
        ListIDBook[i]=CountBook.readLine();
    }

    ListBook.close();

    struct bookliststring listBookInformationString[count];
    listbookInformation= new Book[count];
    for(int i=0;i<count;i++){
        listbookInformation[i]=Book.load(ListIDBook[i]);
        listBookInformationString[i].Book_name=listbookInformation[i].Book_name;
        listBookInformationString[i].Book_author=listbookInformation[i].Book_Author;
        listBookInformationString[i].Book_decribe=listbookInformation[i].Discribe;
        listBookInformationString[i].Book_ID=listbookInformation[i].Book_ID;

    }

    stringstream ss;

    QString txtSearch=ui->lineEdit->text();
    string txtSearchString=txtSearch.toStdString() ;
    string array123[count];
    if(ui->comboBox->currentText()=="Search by name book"){
           for(int i=0;i<count;i++){
               int countTheSameString=0;

               while(ss<<txtSearchString){
                    string a;
                         ss.str(a);
                         ss.clear();
                         stringstream ss1;

                         while(ss1<<listBookInformationString[i].Book_name){
                          string b;
                          ss1.str(b);
                          levenstein distance1;
                          int dis= distance1.levenstein_distance(a,b);
                          if(dis<a.length()-3){
                                countTheSameString++;
            }
            }
            }
                            listBookInformationString[i].a=countTheSameString;
            }
            for (int i=0;i<count-1;i++){
                        for( int j=i+1;j<count;j++){
                             if(listBookInformationString[i].a  > listBookInformationString[j].a){

            }
            }
            }
    }
    else if (ui->comboBox->currentText()=="Search by name author"){
        ui->plainTextEdit->
    }
    else  if (ui->comboBox->currentText()=="Search by Decribe"){

    }

}
