//
//  main.cpp
//  excirses 7
//
//  Created by nguyen tan dung on 7/9/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <string>
#define MAX 100
using namespace std;
// function remove ith element
void remove(string &str,int k,int m){
    for(int i=m;i<k-1;i++){
        str[i]=str[i+1];
    }
    
}

int main(int argc, const char * argv[]) {
    string str,new_str;int count=0,i,k,last;
    getline(cin,str);
    i=0;
    k=(unsigned int)str.length();
    while (str[i]==' ') {
        
        remove(str,k,i);
        k--;
        count+=1;
    }
    last=k-1;
    while (str[last]==' ') {
        k--;
        last--;
        count++;
    }
    for (int i=0; i<k-1; i++) {
        if(str[i]==' ' &&str[i+1]==' '){
            while (str[i+1]==' ') {
                remove(str,k,i+1);
                k--;
                count++;
            }
            
        }
    }
    
    for (int i=0; i<(unsigned int )str.length()-count; i++) {
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}
