//
//  main.cpp
//  macclaurin
//
//  Created by nguyen tan dung on 6/30/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    float a,b,s;
    cin>>a;
    cout<<endl;
    cin>>b;
    s=a;
    for(int i=1;i<b;i++){
        s*=(pow(-1,i)*a*a)/((i+1)*(i+2));
        
    }
    
    cout<<s<<endl;
    
    
}
