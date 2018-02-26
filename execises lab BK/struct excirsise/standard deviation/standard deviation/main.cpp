//
//  main.cpp
//  standard deviation
//
//  Created by nguyen tan dung on 7/8/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <cmath>
#define MAX_SIZE 100
using namespace std;
int main(int argc, const char * argv[]) {
    float a[MAX_SIZE ],average=0,sum=0,temp;
    int count;
    for (int i=0; i<MAX_SIZE;i++) {
        cin>>a[i];
        if(a[i]<0){
            count=i;
            break;}
    }
    for (int i=0; i<count; i++) {
        cout<<a[i]<<" ";
        }
    cout<<endl;
    for (int i=0; i<count; i++) {
        average+=a[i];
    }
    average=average/count;
    for (int i=0; i<count; i++) {
        sum+=(a[i]-average)*(a[i]-average);
    }
    sum=sqrt(sum/(count-1));
    cout<<"sum =" <<sum<<endl;
    for (int i=0; i<count/2; i++) {
        temp=a[count-i-1];
        a[count-i-1]=a[i];
        a[i]=temp;
    }
    for (int i=0; i<count; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
