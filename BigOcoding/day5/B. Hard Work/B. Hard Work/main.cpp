//
//  main.cpp
//  B. Hard Work
//
//  Created by nguyen tan dung on 11/24/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {

    string a[3];
    string array1[3];
    string comparearray[3];
    string array6[6];
  //  cout<<a.size()<<endl;
    cin>>a[0];
    cin>>a[1];
    cin>>a[2];
    int sum=0;
   //     cout<<a<<endl;
   // cout<<a.size()<<endl;
    string newstring;
    string temp;
    for(int i=0;i<3;i++){
    
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]!='_' && a[i][j]!=';'&&a[i][j]!='-'){
                if(isupper(a[i][j])!=0){
                    a[i][j]=tolower(a[i][j]);
                }
                array1[i].push_back(a[i][j]);
            }
        }
    }
    for(int i=0;i<3;i++){
        array6[i*2]=array1[i];
        array6[i*2+1]=array1[i];
        array6[i*2].append(array1[(i+1)%3]);
        array6[i*2].append(array1[(i+2)%3]);
        array6[i*2+1].append(array1[(i+2)%3]);
        array6[i*2+1].append(array1[(i+1)%3]);
    }

    int n;
    cin>>n;
    for(int j=0;j<n;j++){
        string temp;
        cin>>temp;
        bool check=false;
        string a1;
        for(int i=0;i<temp.size();i++){
            if(temp[i]!='_' && temp[i]!=';'&&temp[i]!='-'){
                if(isupper(temp[i])!=0){
                    temp[i]=tolower(temp[i]);
                }
                a1.push_back(temp[i]);
            }
        }
     //   cout<<a1<<endl;
        for(int i=0;i<6;i++){
       //     cout<<a1<<" "<<array6[i]<<endl;
            if(a1.compare(array6[i])==0){
                cout<<"ACC"<<endl;
                check=true;
                break;
            }
        }
        if(check==false){
        cout<<"WA"<<endl;
        }
    }
    return 0;
}
