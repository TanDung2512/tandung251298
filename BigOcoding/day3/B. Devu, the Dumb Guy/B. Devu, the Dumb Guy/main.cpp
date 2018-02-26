//
//  main.cpp
//  B. Devu, the Dumb Guy
//
//  Created by nguyen tan dung on 11/16/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) {
    long n,x;
    cin>>n>>x;
    unsigned long long sum=0;
    unsigned long long *subject=new unsigned long long[n];
    for(unsigned long long i=0;i<n;i++){
        cin>>subject[i];
    }
    sort(subject,subject+n);
    for(unsigned long long i=0;i<n;i++){
        sum+=subject[i]*x;
        if(x>1){
            x--;
        }
        
    }
    cout<<sum<<endl;
    return 0;
}
