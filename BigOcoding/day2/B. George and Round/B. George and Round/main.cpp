//
//  main.cpp
//  B. George and Round
//
//  Created by nguyen tan dung on 11/14/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    long n,m;
    cin>>n>>m;
    long *requireProble=new long[n];
    long *GeorgeProblem=new long[m];

    for(int i=0;i<n;i++){
        cin>>requireProble[i];
    }
    for(int i=0;i<m;i++){
        cin>>GeorgeProblem[i];
        
    }
    long minimun=n;
    int a=0,b=0;
    while(a<n && b<m){
        if(requireProble[a]<=GeorgeProblem[b]){
            minimun--;
            a++;
            b++;
        }
        else b++;
    }
    cout<<minimun<<endl;
    return 0;
}
