//
//  main.cpp
//  A. GukiZ and Contest
//
//  Created by nguyen tan dung on 11/17/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int *position=new int[2001];
    int n;
    cin>>n;
    int *rating=new int[n];
    int range=1;
    for(int i=0;i<2001;i++){
        position[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>rating[i];
        position[rating[i]]++;
    }
    
    for(int i=2000;i>0;i--){
        if(position[i]!=0){
            range+=position[i];
            position[i]=range-position[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<position[rating[i]]<<" ";
    }
    cout<<endl;
    return 0;
}
