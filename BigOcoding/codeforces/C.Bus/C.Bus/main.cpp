//
//  main.cpp
//  C.Bus
//
//  Created by nguyen tan dung on 11/12/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    long a,b,f,k;
    int position1[]={0,1,2,1};
    int position;
    cin>>a>>b>>f>>k;
    long DistStartToGas=f,DistGasToEnd=a-f;
    if(DistGasToEnd>b||DistStartToGas>b)
    {
            cout<<-1<<endl;
            return 0;
    }
    if(  k==2 && DistGasToEnd*2>b){
        cout<<-1<<endl;
        return 0;
    }
    if((DistGasToEnd*2>b || DistStartToGas*2>b) && k>=3){
        cout<<-1<<endl;
        return 0;
    }
    int i=0;
    long numGas=0;
    long gas=b;
    
    gas-=DistStartToGas;
    long sumOfDis=a*k;
    sumOfDis-=DistStartToGas;
    position=1;
//    cout<<"dist start to gas "<<DistStartToGas<<" dist gas to end "<<DistGasToEnd<<endl;
//    
//    cout<<position1[position]<<endl;
//    cout<<"gas "<<gas<<" numGas "<<numGas<<" i "<<i<<" sumofDis "<<sumOfDis<<endl;
    while(i<=k){
//        cout<<position1[position]<<endl;
//        cout<<"gas "<<gas<<" numGas "<<numGas<<" i "<<i<<" sumofDis "<<sumOfDis<<endl;
//
        if(position1[position]==0){
            
            i++;
        }
        if(position1[position]==2){
            
            i++;
        }
        else if(position1[position]==1 && position==1){
            if(sumOfDis==DistGasToEnd){
                if(gas<DistGasToEnd){
                    numGas++;
                }
                break;
            }
            if(DistGasToEnd*2>gas){
                gas=b;
                gas-=DistGasToEnd*2;
                numGas++;
            }
            else {
                gas-=DistGasToEnd*2;
            }
            sumOfDis-=DistGasToEnd*2;
        }
        else if(position1[position]==1 && position==3){
            if(sumOfDis==DistStartToGas){
                if(gas<DistStartToGas){
                    numGas++;
                }
                break;
            }
            if(DistStartToGas*2>gas){
                gas=b;
                numGas++;
                gas-=DistStartToGas*2;
            }
            else{
            gas-=DistStartToGas*2;
            }
            sumOfDis-=DistStartToGas*2;
        }
        
        position++;
        position%=4;
    }
    cout<<numGas<<endl;
    return 0;
}
