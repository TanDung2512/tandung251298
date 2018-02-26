//
//  main.cpp
//  gt&ctdl thay Sach _ tree
//
//  Created by nguyen tan dung on 10/11/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
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

class nodetree{
public:
    int data;
    nodetree* leftNode;
    nodetree*rightNode;
    node(){
        this->data=0;
        this->leftNode =NULL;
        this->rightNode =NULL;

    }
    node(int data){
        this->data=data;
        this->leftNode=NULL;
        this->rightNode =NULL;
    }
};
class binarytree{
    nodetree* root;
    nodetree*temp;
    int number_nodes;
    binarytree(){
        this->root=NULL;
        this->temp=NULL;
        this->number_nodes=0;
    }
    ~binarytree(){
        clearbinarytree(this->root);
        this->temp=NULL;
    }
    void clearbinarytree(node*delNode){
        node*temp=NULL;
        node*left=delNode->leftNode;
        node*right=delNode->rightNode;
        if(left!=NULL){
            node*temp=delNode;
            delNode=left;
            delete temp;
            clearbinarytree(delNode);
        }
        if(right!=NULL){
            node*temp=delNode;
            delNode=right;
            delete temp;
            clearbinarytree(delNode);
        }
    }
    void addNode(int data){
        if(this->root==NULL){
            this->root =new node(data);
        }
        else{
            this->temp=this->root;
            while(this->temp!=NULL){
                if(this->temp->data>data){
                    if(this->temp->leftNode==NULL){
                        this->temp->leftNode=new node(data);
                        break;
                    }
                    this->temp=this->temp->leftNode;
                }
                else {
                    if(this->temp->rightNode==NULL){
                        this->temp->rightNode=new node(data);
                        break;
                    }
                    this->temp=this->temp->rightNode;
                }
            }
        }
    }
    void preorder_traversal(){
        stack*stack1=new stack<<#class stackType#>
    }
    
    
};
int main(int argc, const char * argv[]) {
    
    return 0;
}
