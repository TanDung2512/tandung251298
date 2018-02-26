//
//  main.cpp
//  problem 5-tut2-CSDL&DT
//
//  Created by nguyen tan dung on 9/13/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<time.h>
using namespace std;

bool recursive(int **matrix,int i,int j,int n){
    if(matrix[i][j]==2){
        return true;
    }
    bool check;
    matrix[i][j]=0;
    if( & i>=0 & i+1<n & j>=0 & j<n ){
        if(matrix[i+1][j]!=-1 & matrix[i+1][j]!=0){
        check=recursive(matrix, i+1, j, n);
        if(check==true){
            cout<<i<<j<<endl;
            return true;
        }
        }
    }
    if(  i-1>=0 & i<n & j>=0 & j<n){
        if(matrix[i-1][j]!=-1 &matrix[i-1][j]!=0){
        check=recursive(matrix, i-1, j, n);
        if(check==true){
            cout<<i<<j<<endl;
            return true;
        }
        }
    }
    if(i>=0 & i<n & j>=0 & j+1<n){
        if(matrix[i][j+1]!=-1 & matrix[i][j+1]!=0){
        check=recursive(matrix, i, j+1, n);
        if(check==true){
            cout<<i<<j<<endl;
            return true;
        }
            }
    }
    if( i>=0 & i<n & j-1>=0 & j<n){
        if(matrix[i][j-1]!=-1 & matrix[i][j-1]!=0){
        check=recursive(matrix, i, j-1, n);
        if(check==true){
            cout<<i<<j<<endl;
            return true;
        }
            }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int **matrix;
    int n;
    cin>>n;
    srand((unsigned int)time(NULL));
    matrix=new int* [n];
    int checknumber;
    for(int i=0;i<n;i++){
        matrix[i]=new int [n];
 
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
                checknumber=rand()%3;
                if(checknumber==1){
                    matrix[i][j]=-1;
                }
                else matrix[i][j]=1;
        }
    }
    matrix[0][0]=0;
    matrix[n-1][n-1]=2;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    bool check2;
    check2=recursive(matrix,0,0,n);
    return 0;
}
