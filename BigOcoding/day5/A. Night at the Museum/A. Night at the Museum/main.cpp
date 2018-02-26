//
//  main.cpp
//  A. Night at the Museum
//
//  Created by nguyen tan dung on 11/22/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    int diff1,diff2,sum=0;
    int a=97;
    for(int i=0;i<s.size();i++){
     //   cout<<"s "<<(int)s[i]<<endl;
        diff1=abs(a-s[i]);
        diff2=26-abs(a-s[i]);
        a=int(s[i]);
        sum+=min(diff1,diff2);
    }
    cout<<sum<<endl;
    return 0;
}
