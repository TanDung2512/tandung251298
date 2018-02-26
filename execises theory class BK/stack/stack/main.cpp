//
//  main.cpp
//  stack
//
//  Created by nguyen tan dung on 10/4/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
template<class nodeType>
class node{
public:
    nodeType data;
    node<nodeType>*link;
    node(){
        data=0;
        this->link=NULL;
    }
    node(nodeType data ){
        this->data=data;
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
    void push(stackType data){
   
        node<stackType>*Nnode=new node<stackType>(data);
        Nnode->link=this->top;
        this->top=Nnode;
        this->count++;
        
    }
    void print(){
        node<stackType>*temp=this->top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<endl;
    }
    stackType pop(){
        if(this->count!=0){
        stackType pop;
        pop=this->top->data;
        node<stackType>*Nnode=this->top;
        this->top=this->top->link;
        delete Nnode;
        this->count--;
        return pop;
        }
        return 0;
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


void recursive(stack<int>*temp1,int a,stack<int>*temp2,int &n)
{
    int size;
    int int123;
    if(n<1){
        size=temp2->count;

        for(int i=0;i<size;i++){
            int123=temp2->pop();
            temp1->push(int123);
        }
        return ;
    }
     size=temp1->count;
    for(int i=0;i<size;i++){
        int123=temp1->pop();
        temp2->push(int123);
    }
    a=temp2->pop();
    size=temp2->count;
    for(int i=0;i<n;i++){
        int123=temp2->pop();
        temp1->push(int123);
    }
    temp2->push(a);
    n--;
    recursive(temp1,a,temp2,n);
}

int main(int argc, const char * argv[]) {
    stack<int>*head=new stack<int>();
    for(int i=0;i<6;i++){
        head->push(i);
    }
    head->print();

    stack<int>*temp=new stack<int>();
    int int1;
    int n;
    int1=head->pop();
    temp->push(int1);
    n=head->count;

    recursive(head,int1,temp,n);
    head->print();
    
    return 0;
}
