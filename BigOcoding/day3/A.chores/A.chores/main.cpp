//
//  main.cpp
//  A.chores
//
//  Created by nguyen tan dung on 11/15/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,a,b;
    cin>>n>>a>>b;
    long *chores=new long [n];
    for(int i=0;i<n;i++){
        cin>>chores[i];
    }
    sort(chores,chores+n);
    long x;
    int count=0;
    x=chores[b-1];
    int i=b;
    if(chores[b]<=x){
        cout<<0<<endl;
        return 0;
    }
    else{
        count=chores[b]-chores[b-1];


    }
    cout<<count<<endl;
    return 0;
}
