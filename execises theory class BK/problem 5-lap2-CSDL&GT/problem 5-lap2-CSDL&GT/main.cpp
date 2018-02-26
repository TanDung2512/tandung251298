//
//  main.cpp
//  problem 5-lap2-CSDL&GT
//
//  Created by nguyen tan dung on 9/13/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int checkdigit(int n,int lengthOfnum){
    int num;
    if(n%lengthOfnum>0){
        num=n/(lengthOfnum*10);
        if(num==9 ){
            
        }
    }
    
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int checknum=n;
    int i=1;
    int lengthOfnum=0;
    while(checknum/i>0){
        i*=10;
        lengthOfnum++;
    }
    checkdigit(n,lengthOfnum);
    
    return 0;
}
