#include "search.h"
#include "ui_search.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <string>
#include <sstream>
Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Search by Name");
    ui->comboBox->addItem("Search by Author");
    ui->comboBox->addItem("Search by describe");
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

Search::~Search()
{
    delete ui;
}

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
void Search::on_pushButton_clicked()
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
      ss<< txtSearchString;
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
      algorithmsearch.QuickSort(lisBookString,listBookQString,0,count);

      for(int i=0;i<10;i++){
          a=QString::number(i);
          ui->listWidget->addItem(a+". "+listBookQString[i].Book_Name);
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
       algorithmsearch.QuickSort(lisBookString,listBookQString,0,count);
       for(int i=0;i<10;i++){
                     a=QString::number(i);
           ui->listWidget->addItem(a+". "+listBookQString[i].Book_Name  );
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
       algorithmsearch.QuickSort(lisBookString,listBookQString,0,count);
       for(int i=0;i<10;i++){
           a=QString::number(i);
           ui->listWidget->addItem(a+". "+listBookQString[i].Book_Name);
       }

   }



}




void Search::on_WatchBook_clicked()
{
    QString Choose;
    Choose=ui->listWidget->currentItem()->text();
    int num=Choose.left(1).toInt();
    ui->BookName->setText(listBookQString[num].Book_Name);
    ui->BookAuthor->setText(listBookQString[num].Book_Author);
    ui->BookDes->setText(listBookQString[num].Discribe);
    ui->BookRate->setText(listBookQString[num].Rate);
    ui->BookType->setText(listBookQString[num].Book_Type);
    ui->IDBook->setText(listBookQString[num].Book_ID);

}
