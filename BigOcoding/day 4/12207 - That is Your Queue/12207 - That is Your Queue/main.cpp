//
//  main.cpp
//  12207 - That is Your Queue
//
//  Created by nguyen tan dung on 11/21/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
#include <iostream>
#include<list>
using namespace std;
bool check=false;
void commentN(list<unsigned long int>&line,unsigned long int &countNode,unsigned long int C){
    for(list<unsigned long int>::iterator i =line.begin();i!=line.end();i++){
        if(*i==countNode){
            countNode=(countNode+1)%C;
        }
    }
    if(countNode==0){
        countNode=C;
        check=true;
    }
    line.push_front(countNode);
    countNode=(countNode+1)%C;
}
void commentE(list<unsigned long int>&line,unsigned long int &newNode,unsigned long int th){
    list<unsigned long int>::iterator i=line.begin();
    if(*i==th){
        if(newNode==0   )
            newNode++;
        return ;
    }
    for( i =line.begin();i!=line.end();i++){
        if(*i==th){
            line.push_front(*i);
            line.erase(i);
            newNode++;
            return ;
        }
    }
    
    line.push_front(th);
    newNode++;
}

void returnLine(list<unsigned long int>&line,unsigned long int &newNode,unsigned long int &countNode,unsigned long int C){
    if(newNode==0){
        if(check==false){
            commentN(line,countNode,C);
        }
    }
    else{
        newNode--;
    }
    unsigned long int i=line.front();
    cout<<i<<endl;
    line.pop_front();
    line.push_back(i);
}
int main(int argc, const char * argv[]) {
    unsigned long int P,C,th;
    char comment;
    unsigned long int newNode=0;
    unsigned long int count=0;
    unsigned long int countNode=1;
    bool chekout=false;
    while(chekout==false){
        cin>>P>>C;
     //   cout<<P<<"  "<<C<<endl;

     //   cout<<P<<" "<<C<<endl;
        if(P==0 && C==0) {
            chekout=true;
        }
        else {
            list<unsigned long int>line;
            count++;
          cout<<"Case "<<count<<":"<<endl;
            for(int i=0;i<C;i++){
                cin>>comment;
                if(comment=='N'){
                    returnLine(line,newNode,countNode,P);
                }
                else {
                    cin>>th;
                    commentE(line, newNode, th);
                }
            }
            check=false;
            countNode=1;
            newNode=0;
            continue;
        }
    }
    return 0;
}
