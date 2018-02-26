//
//  main.cpp
//  Phuong phap sinh bai 5
//
//  Created by nguyen tan dung on 7/10/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,a,m;
    cin>>n;
    int x[n],b[n];
    for (int i=1; i<=n; i++) {

        for (int k=0; k<i;k++) {
            x[k]=k+1;
        }
        a=i;
        while (a>=0) {
            for (int j=0; j<i; j++) {
                cout<<x[j];
            }
            cout<<endl;
            a=i-1;
            while (a>=0 && x[a]==n-i+a+1) {
                a--;
            }
            if(a>=0){
                x[a]++;
                for (int l=a+1; l<i; l++) {
                    x[l]=x[l-1]+1;
                }
            }
        }
    }
    
    for (int q=0; q<n; q++) {
        x[q]=q+1;
    }
    for (int q=0; q<n; q++) {
        b[q]=0;
    }
    while (m>=0) {
        for (int q=0; q<n; q++) {
            if(b[q]==1){
                cout<<x[q];
            }
        }
        cout<<endl;
        m=n-1;
        while (m>=0 && b[m]==1) {
            m--;
        }
        b[m]=1;
        for (int q=m+1; q<n; q++) {
            b[q]=0;
        }
    }
    
    
    
    return 0;
}
