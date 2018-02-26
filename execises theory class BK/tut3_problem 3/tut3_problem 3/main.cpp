//
//  main.cpp
//  tut3_problem 3
//
//  Created by nguyen tan dung on 9/27/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
class node{
public:
    int data;
    node*link;
public:
    node(){
        this->link=NULL;
        this->data=0;
    }
    node(int data){
        this->link=NULL;
        this->data=data;
    }
};
class linked_list{
public:
    node *head;
    node *last;
    int count;
public:
    linked_list(){
        this->head=NULL;
        this->last=NULL;
        int count=0;
    }
    void insert_last(int data){
        if(this->head==NULL){
            node *pnew=new node(data);
            this->head=pnew;
            this->last=pnew;
            
        }
        else {
            node *pnew=new node(data);
            this->last->link=pnew;
            this->last=this->last->link;
            this->count++;
        }
    }
    void coutlinklist(){
        int i=1;
        node *cout1=this->head;
        while(cout1!=NULL){
            
            cout<<i<<"th= "<<cout1->data<<endl;
            i++;
            cout1=cout1->link;
        }
        delete cout1;
        cout1=NULL;
    }
    ~linked_list(){
        node *del=NULL;
        while(this->head!=NULL){
            del=this->head;
            this->head=this->head->link;
            delete del;
            del=NULL;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int *listarray=new int [21];
    linked_list *givelist=new linked_list();
    int size_givelist;
    cin>>size_givelist;
    int temp;

    for(int i=1;i<=20;i++){
        listarray[i]=0;
    }
    for(int i=0;i<size_givelist;i++) {
        cin>>temp;
        givelist->insert_last(temp);
    }
    int a;
    node *temp1=givelist->head;
    for (int i=0; i<size_givelist; i++)
        {
            listarray[temp1->data]++;
            temp1=temp1->link;
    }
    linked_list *linkedlist=new linked_list();
    for(int i=1;i<=20;i++){
        a=listarray[i];
        linkedlist->insert_last(a);
    }
    linkedlist->coutlinklist();
    return 0;
}
