//
//  main.cpp
//  sum_1
//
//  Created by nguyen tan dung on 7/4/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    float x,variable;
    int n;
    float s;
    cout<<"input x and n= ";
    cin>>x>>n;
    
    variable=x;
    s=x;
    int i=0;
    do {
        variable*=x*x;
        s+=variable;
        i++;
    } while(i<n);
    cout<<"sum = "<<s<<"\n";
    return 0;
}
