//
//  main->cpp
//  homework_csdt&gt_lab4_problem5
//
//  Created by nguyen tan dung on 11/2/17->
//  Copyright © 2017 nguyen tan dung-> All rights reserved->
//

#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;
template<class nodeType>
class node{
public:
    nodeType x;
    nodeType y;
    node<nodeType>*link;
    node(){
        x=0;
        y=0;
        this->link=NULL;
    }
    node(nodeType x,nodeType y ){
        this->x=x;
        this->y=y;
        this->link=NULL;
    }
};
template<class stackType>
class stack{
public:
    node<stackType>*top;
    int count;
    stack(){
        this->top=NULL;
        this->count=0;
    }
    void push(stackType x,stackType y){
        
        node<stackType>*Nnode=new node<stackType>(x,y);
        Nnode->link=this->top;
        this->top=Nnode;
        this->count++;
        
    }
    void print(){
        node<stackType>*temp=this->top;
        while(temp!=NULL){
            cout<<temp->x<<" "<<temp->y<<endl;
            temp=temp->link;
        }
        cout<<endl;
    }
    node<stackType>*pop(){
        if(this->count!=0){
            node<stackType>*Nnode=this->top;
            this->top=this->top->link;
            this->count--;
            return Nnode;
        }
        return NULL;
    }
    bool isempty(){
        if(this->top!=NULL){
            return false;
        }
        else return true;
    }
    ~stack(){
        node<stackType>*temp;
        while(this->top!=NULL){
            temp=this->top;
            this->top=this->top->link;
            delete temp;
        }
    }
};


int main(int argc, const char * argv[]) {
    stack<int>*recursive=new stack<int>();
    stack<int>*road=new stack<int>();
    int size;
    srand(time(NULL));
    cin>>size;
    node<int>*position;
    int **map=new int*[size];
    for(int i=0;i<size;i++){
        map[i]=new int[size];
    }
    cout<<1<<endl;
    int num;
    for(int i=0;i<size;i++){
        for(int k=0;k<size;k++)
            {
                num=rand()%3;
                if(num==1){
                    map[i][k]=-1;
                }
                else{
                    map[i][k]=1;
                }
        }
    }
    map[0][0]=0;
    map[size-1][size-1]=2;
    for(int i=0;i<size;i++){
        for(int k=0;k<size;k++)
        {
            cout<<fixed<<setw(3)<<map[i][k]<<" ";
        }
        cout<<endl;
    }
    cout<<1<<endl;

    bool check=false;
    recursive->push(0,0);

    while(recursive->count!=0){
        check=false;
        position=recursive->pop();
        map[position->x][position->y]=-1;
        road->push(position->x,position->y);
        if(position->x-1>=0 ){
            if(map[position->x-1][position->y]==1){
            recursive->push(position->x-1,position->y);
            check=true;
            }
            if(map[position->x-1][position->y]==2)
            {
                break;
            }
        }
        if(position->x+1<size ){
            if(map[position->x+1][position->y]==1){
            recursive->push(position->x+1,position->y);
            check=true;
            }
            if(map[position->x+1][position->y]==2)
            {
                break;
            }
        }
        if(position->y+1<size){
            if(map[position->x][position->y+1]==1){
            recursive->push(position->x,position->y+1);
            check=true;
            }
            if(map[position->x][position->y+1]==2)
            {
                break;
            }
        }
        if(position->y-1>=0 ){
            if(map[position->x][position->y-1]==1){
            recursive->push(position->x,position->y-1);
            check=true;
            }
            if(map[position->x][position->y-1]==2)
            {
                break;
            }
        }
        map[position->x][position->y]=-1;
        if(check==false){
        position=road->pop();
        }
    }
    road->print();
    return 0;
}
