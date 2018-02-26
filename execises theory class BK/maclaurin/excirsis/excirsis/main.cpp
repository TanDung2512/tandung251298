//
//  main.cpp
//  excirsis
//
//  Created by nguyen tan dung on 7/1/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(){
 int a,b,c;
    cin>>a;
    cout<<endl;
    cin>>b;
    cout<<endl;
    cin>>c;
    cout<<endl;
    if((a+b)>=c){
        if (a==b || b==c || a==c){
            if ( a==b && b==c){
            cout<<"a,b,c is a iquirateral triangle\n";}
            if ((a==b && (pow(a, 2)+pow(b, 2)==pow(c, 2)) ) ||(a==c && (pow(a,2)+pow(c,2)==pow(b,2)))||(a==b && (pow(a, 2)+pow(b,2)==pow(c,2)))){
            cout<<"a,b,c is a right iscales triangle\n";}
            else  cout<<"a,b,c is a is isocales triangle\n";}
        if (((pow(a, 2)+pow(b, 2)==pow(c, 2)) ) || (pow(a,2)+pow(c,2)==pow(b,2))|| (pow(a, 2)+pow(b,2)==pow(c,2))){
        cout<<"a,b,c is a right triangle\n";}
        else cout <<" a,b,c is a normal triangle\n";
    }
    else cout<< "a,b,c are not a triangle \n";
    
    return 0;
}
