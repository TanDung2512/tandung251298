//
//  main.cpp
//  B. Sort the Array
//
//  Created by nguyen tan dung on 11/15/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    long *array=new long[n+1];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int i=1,j=1;
    int a=1;
    bool check=true;
    while(j<n){
        if(array[a-1]<array[a]){
            i++;j++;
            a++;
        }
        else {
            while(a<n && array[a-1]>=array[a]){
                j++;
                a++;
            }
            if(j<n &&array[i-1]>array[j]){
                check=false;
                break;
            }
            if(i-2>=0 && array[j-1]<array[i-2]){
                check=false;
                break;
            }
            while(a<n && array[a-1]<array[a]){
                a++;
                if(a<n && array[a-1]>array[a]){
                    check=false;
                    break;
                }
                
            }
            break;
        }
    }
    if(check==true){
        cout<<"yes"<<endl;
        cout<<i<<" "<<j<<endl;
    }else cout<<"no"<<endl;
    return 0;
    
}
