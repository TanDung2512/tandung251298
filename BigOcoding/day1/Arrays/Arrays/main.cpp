//
//  main.cpp
//  Arrays
//
//  Created by nguyen tan dung on 11/10/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int na,nb;
    cin>>na>>nb;
    int k,m,i;
    cin>>k>>m;

    int temp, num=0,cond=k-1,cond1=nb-m;
    for(i=0;i<na;i++){
    
        cin>>temp;
        if(i==cond){
            num=temp;
        }
    }
    for(i=0;i<nb;i++){
        cin>>temp;
        if(num<temp & i<=cond1){
            cout<<"YES"<<endl;
            return 0;
        }
//        b[i]=temp;
    }
    cout<<"NO"<<endl;
    return 0;
}
