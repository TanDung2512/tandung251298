//
//  main.cpp
//  B. Pasha and Tea
//
//  Created by nguyen tan dung on 11/17/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include<algorithm>
#define e 0.000001
using namespace std;
int compareAB(float A,float B){
    if (A - B > e){
        return 0;
    } else if (A - B < -e){
        return 1;
    } else {
        return -1;
    }
    }
int main(int argc, const char * argv[]) {
    using namespace std;
    unsigned long n,count=1;
    float w;
    cin>>n>>w;
    unsigned long int temp;
   unsigned long int mingirls,minboys;
    cin>>mingirls;
    minboys=mingirls;
    
    for(unsigned long int i=1;i!=2*n;i++){
        cin>>temp;
        if(temp<mingirls){
            mingirls=temp;
            count++;
        }
        else if(temp>=minboys&& count!=n+1){
        minboys=temp;
        count++;
        }
        
    }
    float minboys1,mingirls1;
    mingirls1=float(mingirls);
    minboys1=minboys*0.5;
    if(compareAB(w,mingirls1)==1 || compareAB(w,mingirls1)==-1 ||   compareAB(w,minboys1)==1){
        cout<<fixed<<setprecision(6)<<w<<endl;
        return 0;
    }
    if(compareAB(mingirls1,minboys1)==1){
        cout<<fixed<<setprecision(6)<<mingirls*3*n<<endl;
    }
    else  cout<<fixed<<setprecision(6)<<minboys1*3*n<<endl;

    return 0;
}
