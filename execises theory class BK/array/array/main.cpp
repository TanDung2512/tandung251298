//
//  main.cpp
//  array
//
//  Created by nguyen tan dung on 7/11/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#define MAX 10
using namespace std;
int main(int argc, const char * argv[]) {
    float x[MAX],sum=0,sum_1=0;
    for (int i=0; i<MAX; i++) {
        x[i]=1.5*i;
    }
    for (int i=0; i<4; i++) {
        sum+=x[i];
    }
    cout<<"Sum of first 4 element= "<<sum<<endl;
    for (int i=0; i<MAX; i++) {
        sum_1+=x[i];
    }
    cout<<"Sum of MAX element = "<<sum_1<<endl;
    return 0;
}
