//
//  main.cpp
//  Nicholas and Permutation
//
//  Created by nguyen tan dung on 11/10/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,temp,min=0,max=0,i,dis1=0,dis2=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>temp;
        if(temp==1){
            min=i;
            dis1=i-1;
            i++;
            break;
        }
        else if(temp==n){
            max=i;
            dis1=i-1;
            i++;
            break;
        }
    }
    for(;i<=n;i++){
        cin>>temp;
        if(temp==1){
            min=i;
            dis2=n-i;
            if(dis2==0 & dis1==0){
                cout<<n-1<<endl;
            }
            else if(dis2>dis1){
                cout<<n-(dis1+1)<<endl;
            }
            else cout<<i-1<<endl;
            break;
        }
        else if(temp==n){
            max=i;
            dis2=n-(i);
            if(dis2==0 & dis1==0){
                cout<<n-1<<endl;
            }
            else if(dis2>dis1){
                cout<<n-(dis1+1)<<endl;
            }
            else cout<<i-1<<endl;
            break;
        }
    }

    
    return 0;
}
