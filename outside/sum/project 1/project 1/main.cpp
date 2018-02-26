//
//  main.cpp
//  project 1
//
//  Created by nguyen tan dung on 6/28/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <math.h>


using namespace std;
int n;
enum Menu
{
    TinhTong=0,
    Tinh_Tongbinhphuong=1,
    Tinh_Tongphanso=2,    // tong thap phan so lẻ
    Tinh_tongphanso_sochan=3, // tong thap phan so chẵn
    Tinh_tongphanso_sole=4,
    Giai_thua,
    cac_uocso,
    EXIT
};

string Menu_list[]{
    "Tính tổng từ 1 - n",
    "Tính tổng bình phường từ 1 - n",
    "Tính tổng các phân số từ 1 - 1/n",
    "Tính tổng các phân số của các phân số chẵn từ 1 - 1/2n",
    "Tính tổng các phân số của các phân số lẻ từ 1-1/2n-1",
    "Tính giai thừa",
    "Liệt kê, tính tổng số lượng các ước số từ 1-n",
    "Thoát ",
};
int tong(int n){
    int s;
    s=0;
    for (int k=1; k<=n; k++) {
        s=s+k;
    };
    return s;
};
// tinh tong cac binh phuong
int tong_binhphuong(int n ){
    int s;
    s=0;
    for (int k=1; k<=n; k++)
    {
        s=s+k*k;
    };
    return s;
};
// tinh tong cac phan so
float tongphanso(int n){
    float s;
    s=0;
    for (int k=1; k<=n; k++) {
        s=s+(float)1/k ;
    };
    return s;
};
// tinh tong phan so cua cac phan so chan
float tongphanso_sochan(int n) {
    float s;
    s=0;
    for (int k=1; k<=n; k++) {
        if (k%2==0)
        {
            s=s+(float)1/k;
        };
    };
    return s;
}
// tinh tong phan so cua cac so le
float tongphanso_sole(int n ){
    float s;
    s=0;
    for (int k=1; k<=n; k++) {
        if (k%2==1) {
            s=s+(float)1/k;
        };
    };
    return s;
}
// tinh giai thua cua n
double tinh_giaithua(int n ){
    double giaithua;
    giaithua=1;
    for (int k=1; k<=n; k++) {
        giaithua=giaithua*k;
    };
    return giaithua;
};
// tim uoc so
void uocso(int n ){
    int root,sl,s;
    sl=0;
    s=0;
    root=n/2;
    cout<<"cac uoc so cua n"<<endl;
    for (int k=1; k<=root; k++) {
        if (n%k==0) {
            sl=sl+1;
            s=s+k;
            cout <<k<<" ";
        };
    };
    cout<<"Số lượng các ước số của "<<n<<"= "<<sl<<endl;
    cout<<"Tổng số lượng các ước số của "<<n<<"= "<<s<<endl;
};



// menu list
void menu(){
    cout<<fixed<<setw(30)<<right<< "Menu\n";
    for (int k=TinhTong; k<= EXIT; k++) {
        cout <<fixed<<setprecision(20)<<setw(20)<<right<<k<<"."<<Menu_list[k]<<endl;
    };
    cout<<endl<<"Nhập số n= ";
    cin>>n;
    
}




//main
int main(int argc, const char * argv[]) {
    int menulist;

    do{
        menu();
        cout<<"chon muc ";
        cin >> menulist;
    switch (menulist) {
        case TinhTong:
            cout<<"tổng từ 1 -> "<<n<< "= "<<tong(n)<<endl;
            break;
        case Tinh_Tongbinhphuong:
            cout<<"Tổng bình phường từ 1 -> "<<n<< "= "<<tong_binhphuong(n )<<endl;
            break;
        case Tinh_Tongphanso:
            cout<<"Tính tổng các phân số từ 1 -> 1/"<<n<< "= "<<tongphanso(n)<<endl;
            break;
        case Tinh_tongphanso_sochan:
            cout<<"Tính tổng các phân số của các phân số chẵn từ 1 -> 1/(2"<<n<< "= "<<tongphanso_sochan(n)<<endl;
            break;
        case Tinh_tongphanso_sole:
            cout<<"Tính tổng các phân số của các phân số lẻ từ 1 -> 1/(2"<<n<<"+1)"<< "= "<<tongphanso_sole(n );
            break;
        case Giai_thua:
            cout<<"Tính giai thừa"<<fixed<<setprecision(0)<<tinh_giaithua(n)<<endl;
            break;
        case cac_uocso:
            uocso(n );
            break;
        case EXIT:
            return 0;
        default:
            break;
    };
        cin.ignore();
        cin.get();
        for (int k=0; k<30; k++) {
            cout<<endl;
        }
        
        
    } while(menulist !=9);
    return 0;
}
