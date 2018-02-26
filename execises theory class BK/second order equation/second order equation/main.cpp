//
//  main.cpp
//  second order equation
//
//  Created by nguyen tan dung on 7/6/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int a,b,c;
    cout<<"please input a,b,c which a,b,c are interger in ax^2+bx+c=0 \n";
    cin>>a>>b>>c;
    if (a==0) {
        if (b==0 && c!=0) {
            cout<<"equation has no solution \n";
            return 0;
        }
        else if (b==0 && c==0) {
            cout<<"equation has many solution\n";
        }
        else{
            cout<<"equation has one solution x="<<(float)-c/a<<"\n";
        }
    }
    if (a!=0) {
        int delta;
        delta = b*b-4*a*c;
        if (delta>0) {
            delta=sqrt(delta);
            cout<<"equation has 2 solution\n";
            cout<<"x1= "<<(float)(-b-delta)/(2*a)<<"\n";
            cout<<"x2= "<<(float)(-b+delta)/(2*a)<<"\n";
        }
        if (delta<0) {
            delta=sqrt(-delta);
            cout<<"equation has 2 imagine solution\n";
            cout<<"x1= "<<(float)-b/(2*a)<<"+"<<(float)delta/(2*a)<<"i"<<"\n";
            cout<<"x2= "<<(float)-b/(2*a)<<"-"<<(float)delta/(2*a)<<"i"<<"\n";
        }
        if (delta==0) {
            cout<<"equation has 1 solution\n";
            cout<<"x= "<<(float)-b/(2*a)<<"\n";
        }
    }
    
    return 0;
}
