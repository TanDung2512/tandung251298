//
//  main.cpp
//  csdt&gt_lab4_problem3
//
//  Created by nguyen tan dung on 11/2/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

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
void problem3(stack<int>*&stack1,stack<int>*&stack2,int sizetemp){
    int tempvar;
    int var;
    for(int i=0;i<sizetemp;i++){
        tempvar=stack1->pop();
        stack2->push(tempvar);
    }
    
    var=stack2->pop();
    for(int i=0;i<sizetemp-1;i++){
        tempvar=stack2->pop();
        stack1->push(tempvar);
    }
    stack2->push(var);
    if(stack1->count>0){
        problem3(stack1,stack2,sizetemp-1);
    }
    
    
}
int main(int argc, const char * argv[]) {
    stack<int>*head=new stack<int>();
    int var;
    for(int i=0;i<6;i++){
        head->push(i);
    }
    head->print();
    
    stack<int>*headtemp=new stack<int>();
    problem3(head,headtemp,6);
    for(int i=0;i<6;i++){
        var=headtemp->pop();
        head->push(var);
    }
    head->print();
    return 0;
}

