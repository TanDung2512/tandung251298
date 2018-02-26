//
//  main.cpp
//  ky thuat quay luu
//
//  Created by nguyen tan dung on 7/11/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int x[100];

void printresult (){
    for (int i=0; i<n; i++) {
        cout<<x[i];
    }
    cout<<endl;
}
void Try(int i){
    for (int k=0; k<=1; k++){
        x[i]=k;
        if (i==n-1) {
            printresult();
        }
        else Try(i+1);
    }
}
int main(int argc, const char * argv[]) {
    cin>> n;
    Try(0);
    
    return 0;
}
