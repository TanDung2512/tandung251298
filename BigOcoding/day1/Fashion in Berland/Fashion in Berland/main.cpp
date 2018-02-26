//
//  main.cpp
//  Fashion in Berland
//
//  Created by nguyen tan dung on 11/8/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int size;
    int temp;
    cin>>size;
    int sum=0;
    if(size==1){
        cin>>temp;
        if(temp==1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else {
    for(int i=0;i<size;i++){
        cin>>temp;
        if(temp==0){
            sum++;
        }
    }
        if(sum==1)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    }
    return 0;
}
