//
//  main.cpp
//  Big Segment
//
//  Created by nguyen tan dung on 11/10/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    double i,min,max,tempL,tempR,left,right,count=1,n;
    
    cin>>n;
    cin>>left>>right;
    min=left;
    max=right;
    for( i=1;i<n;i++)
    {
        cin>>tempL>>tempR;
        if(min>tempL){
            min=tempL;
        }
        if(max<tempR){
            max=tempR;
        }
        if(tempL<=left && tempR>=right){
            left=tempL;
            right=tempR;
            count=i+1;
        }
    }
    
    if(left==min && right==max){
        cout<<count<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
