//
//  main.cpp
//  ctdl&gt_problem4_lab5
//
//  Created by nguyen tan dung on 11/15/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//
#include <iostream>
#include<vector>
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
int highoftree(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int l=0,r=0;
    l=highoftree(root->left);
    r=highoftree(root->right);
    if(l>=r){
        return l+1;
    }else return r+1;
}
void Inorder(TreeNode*subtree,vector<int> &BNS){
    if(subtree==NULL){
        return;
    }
    Inorder(subtree->left,BNS);
    BNS.push_back(subtree->data);
    Inorder(subtree->right,BNS);
}
bool check(TreeNode*root){
    vector<int>BNS;
    Inorder(root,BNS);
    for(int i=1;i<BNS.size();i++){
        if(BNS[i-1]>BNS[i]){
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int n ;
    cin>>n;
    int temp;
    BinaryTree abc;
    for(int i=0;i<n;i++){
        cin>>temp;
        abc.insertNode(abc.root, temp);
    }
    bool check1=check(abc.root);
    if(check1==true){
        cout<<"Yes"<<endl;
    } else cout<<"no"<<endl;
    int hight = highoftree(abc.root);
    cout<<hight<<endl;
    return 0;
}
