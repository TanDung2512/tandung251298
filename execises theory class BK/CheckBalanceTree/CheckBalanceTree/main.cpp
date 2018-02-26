//
//  main.cpp
//  CheckBalanceTree
//
//  Created by nguyen tan dung on 11/22/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
class TreeNode{
public:
    int data;
    int count;
    TreeNode*left=NULL;
    TreeNode*right=NULL;
public:
    TreeNode(int data){
        this->data=data;
    }
    void setRight(TreeNode*right){
        this->right=right;
    }
    TreeNode *&getRight(){
        return this->right;
    }
    TreeNode *&getLeft()
    {
        return this->left;
    }
    void setLeft(TreeNode*left){
        this->left=left;
    }
    int getData(){
        return this->data;
    }
};
class BinaryTree{
public:
    TreeNode*root;
    BinaryTree(){
        this->root=NULL;
    }
    void insertNode(TreeNode*& node,int data){
        if(node==NULL){
            node=new TreeNode(data);
        }
        else {
            if(data>node->getData()){
                insertNode(node->getLeft(),data);
            }
            else {
                insertNode(node->getRight(),data);
            }
        }
    }
    void printNode(TreeNode*root){
        if(root==NULL){
            return ;
        }
        printNode(root->left);
        cout<<root->getData()<< " ";
        printNode(root->right);
    }
};
int checkBalancetree(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int l=0,r=0;
    l=checkBalancetree(root->left);
    r=checkBalancetree(root->right);
    if(l==-1 || r==-1){
        return -1;
    }
    int diff=abs(l-r);
    if(diff==1 || diff ==0){
        if(l>r){
            return l+1;
        }
        else return r+1;
    }
    else return -1;
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
