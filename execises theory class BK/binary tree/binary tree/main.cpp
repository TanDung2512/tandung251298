//
//  main.cpp
//  binary tree
//
//  Created by nguyen tan dung on 11/8/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;
template<class T>
class node{
private:
    T data;
    node<T>* lNode;
    node<T>* rNode;
    node(){
        this->data=0;
        this->lNode=NULL;
        this->rNode=NULL;
    }
    node(T data){
        this->data=data;
        this->lNode=NULL;
        this->rNode=NULL;
    }
};
template <class B>
class BinTree{
public:
    node<B>* root;
    BinTree(){
        this->root=NULL;
    }
    void insert(B data){
        node<B>*temp=this->root;
        if(this->root == NULL){
            this->root=new node<B>(data);
            return ;
        }
        while(1){
            if(data>=temp->data){
                if(temp->rNode!=NULL){
                    temp=temp->rNode;
                }
                else {
                    temp->rNode=new node<B>(data);
                    break;
                }
            }
            else {
                if(temp->lNode!=NULL){
                    temp=temp->lNode;
                }
                else {
                    temp->lNode=new node<B>(data);
                    break;
                }
            }
        }
    }
    
    void traversalPost(node<B>*root){
        if(root->lNode!=NULL){
            traversalPost(root->lNode)  ;
        }
        if(root->rNode!=NULL){
            traversalPost(root->rNode)  ;
        }

        cout<<root->data<<" ";
    }
    void traversalIn(node<B>*root){
        if(root->lNode!=NULL){
            traversalPost(root->lNode)  ;
        }
        cout<<root->data<<" ";
        if(root->rNode!=NULL){
            traversalPost(root->rNode)  ;
        }



    }
    void traversalPre(node<B>*root){
        cout<<root->data<<" ";
        if(root->lNode!=NULL){
            traversalPost(root->lNode)  ;
        }
        if(root->rNode!=NULL){
            traversalPost(root->rNode)  ;
        }
    }
    void remove(node<B>*root){
        if(root!=NULL){
            remove(root->lNode)  ;
            remove(root->rNode)  ;
            delete root;
        }
    }
    ~BinTree(){
        this->remove(this->root);
    }
};
int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int n;
    BinTree<int>*tree=new BinTree<int>();
    int temp;
    cin>>n;
    for(int i=0;i<n;i++){
        temp=rand()%100;
        tree->insert(temp);
    }
    tree->traversalIn(tree->root);
    cout<<endl;
    tree->traversalPost(tree->root);
    delete tree;
    return 0;
};
