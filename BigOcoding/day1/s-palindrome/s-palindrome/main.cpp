//
//  main.cpp
//  s-palindrome
//
//  Created by nguyen tan dung on 11/8/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<vector>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    int n=(unsigned)(s.size());
    int sizestring=s.size()-1;
    int i=0;
    int count0=0;
    int count1=0;
    if(s.size()<5){
        cout<<"no"<<endl;
        return 0;
    }
    while(n>0){
        while(s[sizestring-i]!=0 & n>0){
            i++;
            n--;
        }
        if(s[sizestring-i]==1){
            cout<<"no"<<endl;
            return 0;
        }
        if(n>0){
            i++;
            while(s[sizestring-i]==1){
                count1++;
            }
            if(count1==5){
                cout<<"yes"<<endl;
                return 0;
            }
            

        }
    }
    
    return 0;
}
