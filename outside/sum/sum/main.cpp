//
//  main.cpp
//  sum
//
//  Created by nguyen tan dung on 7/4/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,sum=0;
    cin>>n;
    cout<<endl;
    
    for (int i=0;i<n; i++) {
        sum+=(2*i+1)*(2*i+1);
    }
    cout<<"sum= "<<sum<<" ";
    
    return 0;
}
