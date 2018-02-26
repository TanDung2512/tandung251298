//
//  main.cpp
//  array
//
//  Created by nguyen tan dung on 11/11/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
struct index{
    int position,data;
};
int main(int argc, const char * argv[]) {
    long n,k;
    long temp;
    cin>>n>>k;
    long diff=0;
    long left=1,right=1;
    long first;
    long count [100005];
    long *array=new long[n];
    for(long i=0;i<100005;i++){
        count[i]=0;
    }
    cin>>first;
    array[0]=first;
    count[first+1]++;
    diff++;
    for(long i=1;i<n;i++){
        cin>>temp;
        array[i]=temp;
        if(diff==k){
            break;
        }
        if(count[temp+1]==0){
            diff++;
            right=i+1;
            count[temp+1]++;
            if(diff==k){
                break;
            }
        }
        else count[temp+1]++;

    }
    int i=0;
    while(count[array[i]+1]>1){
        count[array[i]+1]--;
        left++;
        i++;
    }
    
    if(diff==k && left<=right)
        cout<<left<<" "<<right<<endl;
    else cout<<-1<<" "<<-1<<endl;
    return 0;
}
