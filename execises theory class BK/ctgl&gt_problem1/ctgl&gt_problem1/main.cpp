//
//  main.cpp
//  ctgl&gt_problem1
//
//  Created by nguyen tan dung on 11/15/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
class TreeNode{
private:
    string character;
    int count;
    TreeNode*left=NULL;
    TreeNode*right=NULL;
public:
    TreeNode(string character){
        this->character=character;
    }
    TreeNode(char character){
        this->character=character;
    }
    ~TreeNode(){
        this->character.erase();
        this->left=NULL;
        this->right=NULL;
    }
    void increaseCount(){
        this->count++;
    }
    int getCount(){
        return this->count;
    }
    void setCount(int newCount){
        this->count=newCount;
    }
    void setChar(string newChar){
        this->character=newChar;
    }
    string getChar(){
        return this->character;
    }
    void setLeft(TreeNode*newLeft){
        if(newLeft!=NULL){
        this->left=newLeft;
        }
    }
    TreeNode*getLeft(){
        return this->left;
    }
    TreeNode*getRight(){
        return this->right;
    }
    void setRight(TreeNode*newRight){
        if(newRight!=NULL){
            this->right=newRight;
        }
    }
};

class BinarySearchTree{
public:
    TreeNode*root=NULL;
    void insert(TreeNode*node){
        if(node==NULL){
            return ;
        }
        if(node->getChar()==NULL){
            node->increaseCount();
        }
        TreeNode *tempNode=this->root;
        while(tempNode!=NULL){
            if(tempNode->getChar().compare(node->getChar())>1){
                tempNode=tempNode->getLeft();
            }
            else tempNode=tempNode->getRight();
        }
        tempNode=new TreeNode(node->getChar());
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
