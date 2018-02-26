//
//  main.cpp
//  Phuong phap sinh bai 4
//
//  Created by nguyen tan dung on 7/10/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,k,i,count=0;
    cin>>n>>k;
    int x[n];
    i=n-1;
    for (int i=0; i<k; i++) {
        x[i]=i+1;
    }
    while (i>=0) {
        count=0;
        for (int g=0; g<k; g++) {
            if(x[g]>9 ){
                count+=1;
                break;
            }
        }
        if(count==0){
        for (int g=0; g<k; g++) {
            cout<<x[g];
        }
            cout<<endl;
        }

        i=k-1;
        while (i>=0 && x[i]==n-k+i+1) {
            i--;
        }
        if(i>=0){
        x[i]++;
        for (int j=i+1; j<k; j++) {
            x[j]=x[j-1]+1;
        }
        }
    }
    return 0;
}
