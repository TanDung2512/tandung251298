//
//  main.cpp
//  csdl&gtTheory_problem1
//
//  Created by nguyen tan dung on 11/15/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
template<class T>
class TreeNode{
    T data;
    TreeNode<T>*left=NULL;
    TreeNode<T>*right=NULL;
    TreeNode(T data){
        this->data=data;
    }
};
template<class Binary>
class BinaryTree{
    TreeNode<Binary>*root;
    void insert(Binary data,TreeNode<Binary>*&root){
        if(root==NULL){
            root=new TreeNode<Binary>(data);
            return ;
        }
        if(data>=root->data){
            insert(data,root->right);
        }
        else insert(data,root->left);
        
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
