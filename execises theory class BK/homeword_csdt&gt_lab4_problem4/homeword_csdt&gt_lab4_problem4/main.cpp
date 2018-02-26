//
//  main.cpp
//  homeword_csdt&gt_lab4_problem4
//
//  Created by nguyen tan dung on 11/2/17.
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

int main(int argc, const char * argv[]) {
    // insert code here...
    stack<int>*stack1=new stack<int>();
    stack<int>*stack2=new stack<int>();
    int n;
    int var;
    int bin;
    cin>>n;
    stack1->push(n);
    while(stack1->top->data>0){
        cout<<stack1->top->data<<endl;
        var=stack1->pop();
        bin=var%2;
        var=var/2;
        stack1->push(var);
        stack2->push(bin);
    }


    stack2->print();
    return 0;
}
