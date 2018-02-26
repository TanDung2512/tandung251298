//
//  main.cpp
//  Bear and Game
//
//  Created by nguyen tan dung on 11/8/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int size;
    cin>>size;
    int n1,n2=0;
    
    cin>>n1;
    int sum=n1+15;

    if(n1<=15){
        for(int i=0;i<size-1;i++){
            cin>>n2;
            if(n2-n1<=15){
                n1=n2;
                sum=n2+15;
            }
            else{
                cout<<n1+15<<endl;
                return 0;
            }
        }
//        if(size>4){
//        if(90-n2<=15){
//            cout<<90<<endl;
//        }
//        else cout<<n2+15<<endl;
//        }
//        else{
//            cout<<n1+15<<endl;
//        }

    }
    else{
        sum=15;
        cout<<sum<<endl;
        return 0;
        
    }
    if(sum>90)
        {
    cout<<90<<endl;
            }
    else cout<<sum<<endl;
           return 0;
}
