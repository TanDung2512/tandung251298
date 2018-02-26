//
//  main.cpp
//  week4_csdl&gt_problem4
//
//  Created by nguyen tan dung on 10/4/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
struct node{
    int data;
    node*next;
};
struct stack{
    node*top;
    int count;
};
void a_create(stack *head){
    head->top=NULL;
    head->count=0;
}
void b_push(stack *head,int data){
    node*temp=new node();
    temp->data=data;
    temp->next=head->top;
    head->top=temp;
    head->count++;
}
void c_pop(stack *head){
    if(head->top!=NULL){
        node*temp=head->top;
        head->top=head->top->next;
        head->count--;
        delete temp;
    }
}
int d_top(stack *head){
    if(head->top!=NULL){
        return head->top->data;
    }
    return 0;
}
bool isEmpty(stack *head){
    if(head->top==NULL){
        return true;
    }
    else return false;
}
bool isFull(stack *head){
    if(head->top!=NULL){
        return true;
    }
    else return false;
}
void g_clear(stack*head){
    node*temp;
    while(head->top!=NULL){
        temp=head->top;
        head->top=head->top->next;
        delete temp;
    }
}
int h_size(stack *head){
    return head->count;
}

void DecimalToBinary(int n){
    int s=n;
    stack*temp=new stack();
    a_create(temp);
    
    int binary;
    while(s>0){
        binary=s%2;
        b_push(temp, binary);
        s=s/2;
    }
    node*temp1=temp->top;
    for(int i=1;i<=temp->count;i++){
        cout<<temp1->data;
        temp1=temp1->next;
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    DecimalToBinary(10);
    return 0;
}
