//
//  main.cpp
//  lab_3 problem 3
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
    node* insert_node(node* head,int data){
        if(head==NULL){
            head=new node();
            head->data=data;
            head->link=NULL;
            return head;
        }
        else{
        node *Plast=head;
        while(Plast->link!=NULL){
            Plast=Plast->link;
        }
            node *pnew=new node();
            pnew->data=data;
            pnew->link=NULL;
            Plast->link=pnew;
            Plast=Plast->link;
        }
        return head;
    }
};
node *Reverselist(node *root,int &n){
    if(root->link==NULL){
        return root;
    }
    else{
        node *temp=root->link;
        node *a=Reverselist(root->link,n);
        temp->link=root;
        root->link=NULL;
        return a;
    }
}
    void coutnode(node *root){
        node *temp=root;
        if(temp->link!=NULL){
            cout<<temp->data<<endl;
            coutnode(temp->link);
        }
    }

int main(int argc, const char * argv[]) {
    node *head1=new node();
    int size;
    cin>>size;
    int temp;
    for(int i=0;i<size;i++){
        cin>>temp;
        head1->insert_node(head1,temp);
    }
    node *newHead=new node();
    newHead=Reverselist(head1,size);
    for(int i=0;i<size;i++){
        int temp1=newHead->data;
        cout<<temp1<<endl;
        newHead=newHead->link;
    }
    
    return 0;
}

