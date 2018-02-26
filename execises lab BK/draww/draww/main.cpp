//
//  main.cpp
//  draww
//
//  Created by nguyen tan dung on 7/7/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,s=1;
    cin>>n;
    for (int i=0; i<(n/2+1); i++) {
        for (int k=1; k<=((n/2-i));k++) {
            cout<<" ";}
        for (int j=1; j<=s; j++) {
                cout<<"*";
            }
        s+=2;
        cout<<endl;
        
    }
    s=1;
    for (int i=0; i<(n/2+1); i++) {
        for (int k=1; k<=((n/2-i));k++) {
            cout<<" ";}
        for (int j=1; j<=s;j++) {
            if((s)==(n)){
            cout<<"*";}
            else if(j==1){
            cout<<"*";}
            else if(j==s){
            cout<<"*";}
            
            else if(j!=s && j!=1){cout<<" ";}
            
        }
        s+=2;
        cout<<endl;
        
    }

return 0;
}
