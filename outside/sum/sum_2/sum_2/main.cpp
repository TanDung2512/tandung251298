//
//  main.cpp
//  sum_2
//
//  Created by nguyen tan dung on 7/7/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    unsigned int n;
    int sum=0,fn,fn_1;
    cout<<"please input n ";
    cin>>n;
    cout<<endl;
    if (n<2) {
        sum=1;
        cout<<"sum = "<<sum;
    }
    if (n>=2) {
        sum=0;
        fn=1;
        fn_1=1;
        for (int i=2; i<=n; i++) {
            sum=fn+fn_1;
            fn_1=fn;
            fn=sum;
        }
        cout<<"f("<<n<<")="<<sum<<endl;
    }
    return 0;
}
