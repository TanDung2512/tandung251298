//
//  main.cpp
//  DSAP
//
//  Created by nguyen tan dung on 7/10/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,count;
    cin>>n;
    int i;
    int x[n];
    for (int k=0; k<n; k++) {
        x[k]=0;
    }
    i=n-1;
    while (i>=0) {
        count=0;
        for (int i=0; i<n-1; i++) {
            if(x[i]==0 && x[i+1]==1){
                count+=1;
            }
        }
        if (count==2) {
            for (int h=0; h<n; h++) {
                cout<<x[h];
            }
            cout<<endl;
        }

        i=n-1;
        while (i>=0 && x[i]==1) {
            i--;
        }
        x[i]=1;
        for (int j=i+1; j<n; j++) {
            x[j]=0;
        }
    }
    
    
    return 0;
}
