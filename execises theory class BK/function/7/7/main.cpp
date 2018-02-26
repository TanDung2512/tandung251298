//
//  main.cpp
//  7
//
//  Created by nguyen tan dung on 7/25/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;

double sum(int n){
    double s=0;
    
    for (int i=1;i<=n; i++) {
        s+=i*i;
    }
    return s;
}
int main(int argc, const char * argv[]) {
    double s;
    int n;
    do {
        cin>>n;
    } while (n<0);
    s=sum(n);
    cout<<"the sum= "<<s<<endl;
    return 0;
}
