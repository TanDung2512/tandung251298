//
//  main.cpp
//  B. Books
//
//  Created by nguyen tan dung on 11/14/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    unsigned long long int n,t;
    cin>>n>>t;
    unsigned long long int *books=new unsigned long long int[n];

    unsigned long long int left=0,right=0,sum=0,max=0,numbooks=0;
    for(unsigned long long int i=0;i<n;i++){
         cin>>books[i];
        sum+=books[right];
        numbooks++;
//        cout<<" numbooks "<<numbooks<<" right "<<right<<endl;
        if(sum<=t ){
            right++;
        }
        else {
            while(left<=right && sum>t){
                sum-=books[left];
                numbooks--;
                left++;
            }
            right++;
            
        }
        if(numbooks>max){
            max=numbooks;
        }
    }
    cout<<max<<endl;
    return 0;
}
