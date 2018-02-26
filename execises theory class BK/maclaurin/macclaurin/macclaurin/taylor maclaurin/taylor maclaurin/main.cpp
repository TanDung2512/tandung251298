//
//  main.cpp
//  taylor maclaurin
//
//  Created by nguyen tan dung on 7/2/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string.h>
#define EPSILON 0.0000000001
using namespace std ;
enum menu_num{
    FRACTION=1,
    VEBE,
    SIN,
    COS,
    INVERSE_TAN,
    LOGARIT_VEBE,
    TAYLOR,
    EXIT
};
string menu_list[8]={
    "Fraction of 1/(1-x) 0<x<1",
    "Vebe power of x",
    "sin(x) x is radian ",
    "cos(x) x is radian",
    "tan^(-1)",
    "ln(x)",
    "(1-x)^k",
    "exit"
};
//fraction
float fraction(float x){
    float sum=x,multiply=x;
    
    for (int i=0; i<=10000;i++) {
        multiply*=x;
        sum=sum+multiply;
       if(multiply<EPSILON){
           break;
       }
    }
    return sum;
};
//vebe
float vebe(float x){
    float sum=1;
    float variable=1;
    for (int i=1; i<=10000; i++) {
        variable*=(x/i);
        sum+=variable;
        if((variable)<EPSILON){
            break;
        }

    }
    return sum;
}



//sin
float sin (float x){
    float variable=x;
    float sum=x;
    int sign=1;
    for (int i=1; i<1000; i++) {
        sign*=-1;
        variable=variable*((x*x)/((i*2)*(1+2*i)));
        sum+=(sign*variable);
        if((variable)<EPSILON){
            break;
        }

        }
    return sum;
}

//cos
float cos(float x){
    float variable=x;
    float sum =1;
    int sign=1;
    for (int i=1; i<10000; i++) {
        sign*=-1;
        variable*=((x*x)/((2*i-1)*(i+i)));
        sum+=sign*variable;
        if((variable)<EPSILON){
            break;
        }
    }
    return sum;
}
// inverse of tan
float inverse_tan(float x){
    float variable=x;
    float sum=x;
    int sign=1;
    for (int i=1; i<100; i++) {
        sign*=-1;
        variable*=(x*x);
        sum+=(sign*variable)/(2*i+1);
        cout<<sum<< " ";
        if((variable)<EPSILON){
            break;
        }
        
    }
    return sum;

}



//logarit vebe
float logarit_vebe(float x){
    float variable=x;
    float sum=x;
    int sign=1;
    for (int i=1; i<=10000; i++) {
        sign*=-1;
        variable*=x*x;
        sum+=variable*sign/(2*i+1);
    if((variable)<EPSILON){
        break;
        }
    }
    return sum;
}



float taylor(float x,int k){
    float sum=1,delta;
    for (int i=0; i<10000; i++) {
        delta*=((k-i)*x)/(i+1);
        sum+=delta;
    if(delta < EPSILON){
        break;
        }
    }
    return sum;
}


//Menu
void menu(){
    cout<<setw(8)<<right<<"Menu\n";
    for (int i=1; i<=EXIT; i++) {
        cout<<i<<"."<<menu_list[i-1]<<"\n";

}
    
}
int main(int argc, const char * argv[]) {
    float variable,k;
    int choose;
    menu();
    do {
        cin>>choose;
        switch (choose) {
            case FRACTION:{
                do {
                    cout<<"please input variable from -1<x<1: ";
                    cin>>variable;
                    cout<<endl;
                } while (variable<-1||variable>1);
                cout<<"1/(1-"<<variable<<")= "<<fraction(variable)<<endl;
                break;
                }
            case VEBE:{
                    cout<<"please input variable ";
                    cin>>variable;
                    cout<<endl;
                    cout<<"e^"<<variable<<"= "<<vebe(variable)<<"\n";
                break;
                }
            case SIN:{
                    cout<<"please input radian ";
                    cin>>variable;
                    cout<<endl;
                    cout<<"sin("<<variable<<")="<<sin(variable)<<endl;
                    break;
                }
            case COS:{
                cout<<"please input radian ";
                cin>>variable;
                cout<<endl;
                cout<<"cos("<<variable<<")="<<cos(variable)<<endl;
                break;
            }
            case INVERSE_TAN:{
                    cout<<"please input number x!=1";
                    cin>>variable;
                    cout<<endl;
                    cout<<"tan^-1("<<variable<<")="<<fixed<<setprecision(7)<<(float)inverse_tan(variable)<<endl;
                    break;
                }
            case LOGARIT_VEBE:{
                    do {
                        cout<<"please input variable from x>0 ";
                        cin>>variable;
                        cout<<endl;
                    } while (variable<=0);
                    cout<<"tan^-1("<<variable<<")="<<logarit_vebe(variable)<<endl;
                    break;
                }
            case TAYLOR:{
                    cout<<"please input number x";
                    cin>>variable;
                    cout<<"please input root k ";
                    cin>>k;
                    cout<<endl;
                    cout<<"(1-"<<variable<<")^"<<k<<"="<<taylor(variable, k )<<endl;
                    break;
                }
            case EXIT:{
                break;
            }
            default:
                break;
        }
    } while (choose!=EXIT);
    
    return 0;
}
