//
//  main.cpp
//  pointer_1
//
//  Created by nguyen tan dung on 7/21/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a[3]={10,15,17},sum=0;
    int *p;
    p=new int[3];
    for (int i=0; i<3; i++) {
        *(p+i)=i*i+5;
    }
    for (int i=0; i<3; i++) {
        sum+=*(p+i);
    }
    cout<<sum<<endl;
    delete []p;
        return 0;
}
