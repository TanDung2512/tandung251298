//
//  main.cpp
//  B. Kayaking
//
//  Created by nguyen tan dung on 11/15/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int *array=new int[2*n];
    long sum=0;
    sort(array,array+2*n);
    int size=2*n-2;

    for(int i=0;i<2*n;i++){
        cin>>array[i];
    }
        int i=1;
    while(i<size){
        sum+=abs(array[i]-array[i-1]);
        i+=2;
    }
    cout<<sum<<endl;
    return 0;
}
