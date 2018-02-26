//
//  main.cpp
//  B. African Crossword
//
//  Created by nguyen tan dung on 11/24/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    string *array=new string [n];
    int **array1=new int*[n];
    for(int i=0;i<n;i++){
        array1[i]=new int [m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            array1[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    bool check1=false,check2=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(array1[i][j]==0){
                for(int s=0;s<m;s++){
                    if(array[i][j]==array[i][s] && s!=j){
                 //       cout<<i<<" "<<j<<" "<<i<<" "<<s<<endl;
                        array1[i][s]=1;
                        check1=true;
                    }
                }
                for(int s=0;s<n;s++){
                    if(array[i][j]==array[s][j] && s!=i){
                   //     cout<<i<<" "<<j<<" "<<s<<" "<<j<<endl;
                        array1[s][j]=1;
                        check2=true;
                    }
                }
            
            if(check2==false && check1==false){
                cout<<array[i][j];
            }
            }
            check1=false;
            check2=false;
        }
    }
    return 0;
}
