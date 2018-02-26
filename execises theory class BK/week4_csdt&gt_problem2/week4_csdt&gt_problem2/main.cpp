//
//  main.cpp
//  week4_csdt&gt_problem2
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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
