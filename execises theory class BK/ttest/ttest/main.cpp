//
//  main.cpp
//  ttest
//
//  Created by nguyen tan dung on 9/13/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
void triangle(int n,int i){
    for(int j=0;j<=i;j++){
            cout<<"*";
    }

cout<<endl;
    if(n>0){
        
        triangle(n-1,i+1);
    }
    
    }
int main(int argc, const char * argv[]) {
    int a[]={0,1,2,3};


    return 0;
}
