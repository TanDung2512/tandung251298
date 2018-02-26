//
//  main.cpp
//  problem1_week4_csdl&gt
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
int main(int argc, const char * argv[]) {
    stack *head=new stack();
    a_create(head);
    
    
    b_push(head, 1);
    cout<<head->top->data<<endl;
    b_push(head, 2);
    cout<<head->top->data<<endl;

    b_push(head, 3);
    cout<<head->top->data<<endl;

    
    c_pop(head);
    g_clear(head);
    return 0;
}
