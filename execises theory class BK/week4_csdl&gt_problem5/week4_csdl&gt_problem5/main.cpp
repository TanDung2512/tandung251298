//
//  main.cpp
//  week4_csdl&gt_problem5
//
//  Created by nguyen tan dung on 10/4/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
struct node{
    int data;
    node*next;
};
struct queue{
    node*front;
    node*rear;
    int count;
};
void a_create(queue *head){
    head->front=NULL;
    head->rear=NULL;
    head->count=0;
}
void b_EnQuere(queue*head,int data){
    node*temp=new node();
    temp->data=data;
    temp->next=NULL;
    
    if(head->rear==NULL){
        head->rear=temp;
        head->front=temp;
    }
    else{
        head->rear->next=temp;
        head->rear=temp;
        
    }
    head->count++;
}
void c_Dequeue(queue *head){
    if(head->count==0){
        return ;}
    if(head->count==1){
        head->rear=NULL;
    }
    head->front =head->front->next;
    head->count--;
}
int d_QueuenFront(queue *head){
    if(head->rear!=NULL){
        return head->front->data;
    }
    return 0;
}
int e_QuereRear(queue *head){
    if(head->rear!=NULL){
        return head->rear->data;
    }
    return 0;
}
bool f_isEmpty(queue *head){
    if(head->count==0){
        return true;
    }
    else return false;
}
bool g_isFull(queue *head){
    if(head->count!=0){
        return true;
    }
    else return false;
}
void h_clear(queue *head){
    head->rear=NULL;
    node*temp;
    while(head->front!=NULL){
        temp=head->front;
        head->front=head->front->next;
        delete temp;
        head->count--;
    }
}
int i_size(queue *head){
    return head->count;
}

struct stack{
    node*top;
    int count;
};
void create(stack *head){
    head->top=NULL;
    head->count=0;
}
void push(stack *head,int data){
    node*temp=new node();
    temp->data=data;
    temp->next=head->top;
    head->top=temp;
    head->count++;
}
void pop(stack *head){
    if(head->top!=NULL){
        node*temp=head->top;
        head->top=head->top->next;
        head->count--;
        delete temp;
    }
}
int top(stack *head){
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
void clear(stack*head){
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







queue*StackToQueue(stack *head){
    queue *head1=new queue();
    a_create(head1);
    int int123;
    while(!isEmpty(head)){
        int123=top(head);
        pop(head);
        b_EnQuere(head1, int123);
    }
    return head1;
}
stack*QueueToStack(queue *head){
    stack *head1=new stack();
    create(head1);
    int int123;
    node*temp=head->front;
    while(temp!=NULL){
        int123=temp->data;
        push(head1, int123);
        temp=temp->next;
    }
    return head1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
