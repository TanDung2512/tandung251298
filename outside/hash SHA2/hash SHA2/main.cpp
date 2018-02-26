//
//  main.cpp
//  hash SHA2
//
//  Created by nguyen tan dung on 8/2/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <sstream>
#include<string.h>
#include<iomanip>
#include<vector>
#include <bitset>
using namespace std;

unsigned long long int leftRotate(unsigned long long int n, unsigned int d)
{

    return (n << d)|(n >> (32- d));
    }
string SHA1(string string_hash){
stringstream ss;
    cout<<string_hash<<endl;
int a[string_hash.length()];
double hex[string_hash.length()];
for (int i=0; i<string_hash.length(); i++) {
    a[i]=(int)string_hash[i];
}
for (int i=0;i<string_hash.length(); i++) {
    ss<<std::hex<<a[i];
    ss>>hex[i];
    ss.clear();
    }
    double array[64];
    for (int i=0; i<string_hash.length(); i++) {
        array[i]=hex[i];
    }
    
    int n=(int)string_hash.length();
    array[n]=80;
    long long int mit[80];
    
    string tamp;
    int count;
    for ( count=n+1; count<62; count++) {
        array[count]=0;
    }
    array[63]=n;
    int m=0;
    for (int i=0; i<16; i++) {
        string temp;
        for (int k=0; k<4; k++) {
            ss<<array[m];
            ss>>tamp;
            ss.clear();
            temp.append(tamp);
            m++;
        }
        ss<<temp;
        ss>>mit[i];
        temp.clear();
        
    }
    //    for (int i=0; i<16; i++) {
    //        cout<<mit[i]<<endl;
    //    }
    unsigned long long int h0 = 0x67452301,s,b,c,d,e,
    h1 = 0xEFCDAB89,
    h2 = 0x98BADCFE,
    h3 = 0x10325476,
    h4 = 0xC3D2E1F0;
    for (int i=16; i<80; i++) {
        mit[i]=leftRotate((mit[i-3]^mit[i-8]^mit[i-14]^mit[i-16]), 1);
    }
    s=h0;
    b=h1;
    c=h2;
    d=h3;
    e=h4;
    
    for (int i=0; i<80; i++) {
        unsigned long long int f,k;
        unsigned long long int q;
        if (i<=19) {
            f=(b&s)|((~b)&d);
            k=0x5A827999;
        }
        else if(i<=39){
            f=b^c^d;
            k=0x8F1BBCDC;
        }
        else if(i<=59){
            f=(b & c) |(b&d)| (c&d);
            k=0x8F1BBCDC;
        }
        else if(i<=79){
            f=b^c^d;
            k =0xCA62C1D6;
        }
        q=(leftRotate(s, 5))+f+e+k+mit[i];
        e=d;
        d=c;
        c=leftRotate(b,30);
        b=s;
        s=q;
        
    }
    string p;

    h0 = (h0 + s);
    h1 = (h1 + b);
    h2 = (h2 + c);
    h3 = (h3 + d);
    h4 = h4 + e;
    h0=leftRotate(h0,128);
    h1=(leftRotate(h1,64));
    unsigned long long int hh=leftRotate(h0,128)|(leftRotate(h1,64))|(leftRotate(h2,96))|(leftRotate(h3,32))|h4;

//    h0=h0<<128;
//    h2=h2<<64;
 
    cout<<std::bitset<160>(hh);
    
    return p;
    }
int main(int argc, const char * argv[]) {
    string p,a;
    cin>>p;
    a=SHA1(p);
    cout<<a<<endl;
//    cout<<"1586156d49911b04e64c1f9bfbf33610229166e3175b9fc06d7dd2848192a3b0657ce061c3d2e1f0"<<endl;
    return 0;
}
