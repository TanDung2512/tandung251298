//
//  main.cpp
//  recursion
//
//  Created by nguyen tan dung on 9/14/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;

long int fibo(int n,long int & count){
    count++;
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    return fibo(n-1,count) + fibo(n-2,count);
}
int main(int argc, const char * argv[]) {
    int n;
    cout<<"nhập số lần ";
    long int count=0;
    cin>>n;
    long int a=fibo(n-1,count);
    cout<<"number of value= "<<a<<", number of calls=  "<<count<<endl;
    return 0;
}
