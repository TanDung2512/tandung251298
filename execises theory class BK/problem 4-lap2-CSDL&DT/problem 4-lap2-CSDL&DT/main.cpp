//
//  main.cpp
//  problem 4-lap2-CSDL&DT
//
//  Created by nguyen tan dung on 9/13/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
void recursive(int start,int end){
    if(start==end){
        return ;
    }
    if(end-start>=6){
                cout<<"+6"<<endl;
        recursive(start+6,end);
    }
    if(end-start<6 && end-start>0){
                cout<<"+3"<<endl;
        recursive( start+3,end);

    }
    if(end-start<0){
                cout<<"-5"<<endl;
        recursive(start-5,end);

    }
}


int main(int argc, const char * argv[]) {
    int start,end;
    cin>>start;
    cin>>end;
    recursive(start,end);
    return 0;
}
