//
//  main.cpp
//  excirses 6
//
//  Created by nguyen tan dung on 7/11/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
void swap (int &m,int &n){
    int temp;
    temp=m;
    m=n;
    n=temp;
}
int main(int argc, const char * argv[]) {
    int n,a,l,v,m;
    cin>>n;
    int x[n],;
    for (int i=0; i<n; i++) {
        x[i]=i+1;
    }
    a=n-1;
   while (a>=0) {
        for (int i=0; i<n; i++) {
            cout<<x[i];
        }
        cout<<endl;
        a=n-2;
        while (a>=0 && x[a]>x[a+1]) {
            a--;
        }
     //   if(a>=0){
        l=n-1;
        while (x[l]<x[a]) {
            l--;
        }
        swap(x[a],x[l]);
       m=a+1;
       v=n-1;
       while (m<v) {
           swap(x[m], x[v]);
           m++;
           v--;
       }
}
    
  // }
    return 0;
}
