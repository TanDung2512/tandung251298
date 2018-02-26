//
//  main.cpp
//  Vanya and Fence
//
//  Created by nguyen tan dung on 11/8/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int size,height;
    cin>>size>>height;
    int temp;
    int sum=0;
    for(int i=0;i<size;i++){
        cin>>temp;
        if(temp<=height){
            sum++;
        }
        else{
            sum+=2;
        }
        }
    cout<<sum<<endl;
    
    return 0;
}
