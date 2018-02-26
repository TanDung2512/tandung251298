



#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

//hàm tìm bé nhỏ nhất
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


int  main(){
    string a,b,c;
    int compare;
    getline (cin,a);// chuoi can tim
    getline(cin,b);
    stringstream ss;
    ss<<b;
    
    // so sánh 1 thằng trong 1 đống chuỗi được đưa vào
    while (ss>>c){
        
        compare= levenstein_distance(a,c);
        if(compare==0 || compare == 1){    // nếu nó giống hoàn toàn hoặc chệnh lệch nhau 1 ký tự thì xuất ra
        }
    }
    
    

    
    return 0;
}
