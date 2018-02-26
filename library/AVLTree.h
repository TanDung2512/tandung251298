#include<iostream>
using namespace std;
class balance_factor{
private:
  bool RH,LH,EH;
public:
  balance_factor(){
    this->RH=false;
    this->LH=false;
    this->EH=false;
  }
  void setEH(){
    this->EH=true;
    this->LH=false;
    this->RH=false;
  }
  void setLH(){
    this->EH=false;
    this->LH=true;
    this->RH=false;
  }
  void setRH(){
    this->EH=false;
    this->LH=false;
    this->RH=true;
  }
  bool isEH(){
    return this->EH;
  }
  bool isLH(){
    return this->LH;
  }
  bool isRH(){
    return this->RH;
  }
  void print(){
    if(this->isEH()){
      cout<<"EH";
    }
    else if(this->isLH()){
      cout<<"LH";
    }
    else{
      cout<<"RH";
    }
  }
};
template <class NodeAVL>
class node{
public:
  NodeAVL data;
  node<NodeAVL>*left;
  node<NodeAVL>*right;
  balance_factor balance;
  node(NodeAVL data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
    balance=balance_factor();
    this->balance.setEH();
  }
};


template<class tree>
class AVLTree{
private:
  node<tree>*root;
  node<tree>*rotateRight(node<tree>*root);
  node<tree>*rotateLeft(node<tree>*root);
  node<tree>*AVLInsert(node<tree>*root,node<tree>*newPtr,bool&taller);
  node<tree>*leftBalance(node<tree>*root,bool &taller);
  node<tree>*rightBalance(node<tree>*root,bool &taller);
  node<tree>*AVLDelete(node<tree>*root,tree deldata,bool &shorter,bool &success);
  node<tree>*deleteRightBalance(node<tree>*root,bool&shorter);
  node<tree>*deleteLeftBalance(node<tree>*root,bool&shorter);
public:
  AVLTree();
  void insert(tree data);
  node<tree>*getRoot();
  bool deleteNode(tree data);
  node<tree>* maxNode();
  node<tree>* minNode();
  void inorder(node<tree>*root);
  node<tree>*search(tree key);
  void printNode(node<tree>*root);
  int height(node<tree>*root);
  bool checkAVL(node<tree>*root);
};
template<class tree>
AVLTree<tree>::AVLTree()
  {
  this->root=NULL;
  }
template<class tree>
node<tree>*AVLTree<tree>::rotateRight(node<tree>*root){
  node<tree>*temp=root->left;
  root->left=temp->right;
  temp->right=root;
  return temp;
}
template<class tree>
node<tree>*AVLTree<tree>::rotateLeft(node<tree>*root){
  node<tree>*temp=root->right;
  root->right=temp->left;
  temp->left=root;
  return temp;
}
template<class tree>
void AVLTree<tree>::insert(tree data){
  node<tree>*newPtr=new node<tree>(data);
  bool taller=false;
  this->root=AVLInsert(this->root,newPtr,taller);
}
template<class tree>
node<tree>*AVLTree<tree>::AVLInsert(node<tree>*root,node<tree>*newPtr,bool&taller){
  if(root==NULL){
    taller=true;
    return newPtr;
  }
  if(root->data>newPtr->data){
    root->left=AVLInsert(root->left,newPtr,taller);
    if(taller){
      if(root->balance.isLH()){
        root=leftBalance(root,taller);
      }
      else if(root->balance.isEH()){
        root->balance.setLH();
      }
      else {
        root->balance.setEH();
        taller=false;
      }
    }
  }
  else {
    root->right=AVLInsert(root->right,newPtr,taller);
    if(taller){
      if(root->balance.isLH()){
        root->balance.setEH();
        taller=false;
      }
      else if(root->balance.isEH()){
        root->balance.setRH();
      }
      else {
        root=rightBalance(root,taller);
      }
    }
  }
  return root;
}
template<class tree>
node<tree>*AVLTree<tree>::leftBalance(node<tree>*root,bool &taller){
  node<tree>*leftTree=root->left;
  if(leftTree->balance.isLH()){
    if(root->right==NULL || leftTree->right!=NULL){
      root->balance.setEH();
    }
    else if( leftTree->right==NULL){
      root->balance.setRH();
    }
    leftTree->balance.setEH();
    root=rotateRight(root);
    taller=false;
  }
  else {
    node<tree>*rightTree=leftTree->right;
    if(root->right==NULL){
      root->balance.setEH();
      leftTree->balance.setEH();
    }
    if(rightTree==NULL){
      cout<<root->data<<" "<<root->left->data<<endl;
      throw "rightree";
    }
    else if(rightTree->balance.isLH()){
      root->balance.setRH();
      leftTree->balance.setEH();
    }
    else if(rightTree->balance.isEH()){
      leftTree->balance.setEH();
    }
    else {
      root->balance.setEH();
      leftTree->balance.setLH();
    }
    rightTree->balance.setEH();
    root->left=rotateLeft(leftTree);
    root=rotateRight(root);
    taller=false;
  }
  return root;
}
template<class tree>
node<tree>*AVLTree<tree>::rightBalance(node<tree>*root,bool &taller){
  node<tree>*rightTree=root->right;
  if(rightTree->balance.isRH()){
      if(root->left==NULL || rightTree->left!=NULL){
        root->balance.setEH();
      }
      else if( rightTree->left==NULL){
        root->balance.setLH();
      }
    root=rotateLeft(root);
    root->balance.setEH();
    rightTree->balance.setEH();
    taller=false;
  }
  else {
    node<tree>*leftTree=rightTree->left;
    if(root->left==NULL){
      root->balance.setEH();
      rightTree->balance.setEH();
    }
    if(leftTree==NULL){
      cout<<root->data<<" "<<root->right->data<<endl;
      throw "leftree";
    }
    if(leftTree->balance.isRH()){
      root->balance.setLH();
      rightTree->balance.setEH();
    }
    else if(leftTree->balance.isEH()){
      rightTree->balance.setEH();
    }
    else {
      root->balance.setEH();
      rightTree->balance.setRH();
    }
    leftTree->balance.setEH();
    root->right=rotateRight(rightTree);
    root=rotateLeft(root);
    taller=false;
  }
  return root;
}
template<class tree>
int AVLTree<tree>::height(node<tree>*root){
  if(root==NULL){
    return 1;
  }
  int lh=height(root->left);
  int rh=height(root->right);
  return max(lh,rh)+1;
}
template<class tree>
bool AVLTree<tree>::checkAVL(node<tree>*root){
  if(root==NULL){
    return true;
  }
  int abs1=height(root->left)-height(root->right);
  cout<<abs1<<endl;
  if(abs1>1 || abs1<-1){
    return false;
  }
  bool bl=checkAVL(root->left);
  if(!bl){
    return false;
  }
  bool br=checkAVL(root->right);
  if(!br){
    return false;
  }
  return true;
}
template<class tree>
void AVLTree<tree>::inorder(node<tree>*root){
  if(root!=NULL){
    inorder(root->left);
    cout<<root->data<<" ";

    inorder(root->right);
  }
}
template<class tree>
void AVLTree<tree>::printNode(node<tree>*root){
  cout<<"root : "<<root->data<<" ";
    root->balance.print();
    cout<<" ";
    if(root->left!=NULL){
      cout<<"left: "<<root->left->data<<" ";
      root->left->balance.print();
      cout<<" ";
    }
    if(root->right!=NULL){
      cout<<"right: "<<root->right->data;
      root->right->balance.print();
      cout<<" ";
    }
    cout<<endl;
}
template<class tree>
node<tree>*AVLTree<tree>::AVLDelete(node<tree>*root,tree deldata,bool &shorter,bool &success){
  if(root==NULL){
    success=false;
    shorter=false;
    return NULL;
  }
  if(deldata>root->data){
    root->right=AVLDelete(root->right,deldata,shorter,success);
    if(shorter){
      root=deleteLeftBalance(root,shorter);
    }
  }
  else if(deldata<root->data){
    root->left=AVLDelete(root->left,deldata,shorter,success);
    if(shorter){
      root=deleteRightBalance(root,shorter);
    }
  }
  else {
    if(root->right==NULL){
      node<tree>*newRoot=root->left;
      success=true;
      shorter=true;
      delete root;
      root=NULL;
      return newRoot;
    }
    else if(root->left==NULL){
      node<tree>*newRoot=root->right;
      success=true;
      shorter=true;
      delete root;
      root=NULL;
      return newRoot;
    }
    else{
        node<tree>*exchPtr=root->left;
        while(exchPtr->right!=NULL){
          exchPtr=exchPtr->right;
        }
        root->data=exchPtr->data;
        root->left=AVLDelete(root->left,exchPtr->data,shorter,success);
        if(shorter){
          root=deleteRightBalance(root,shorter);
      }
    }
  }
  return root;
}
template<class tree>
node<tree>*AVLTree<tree>::deleteRightBalance(node<tree>*root,bool&shorter){
  if(root->balance.isLH()){
    root->balance.setEH();
    shorter=false;
  }
  else if(root->balance.isEH()){
    root->balance.setRH();
    shorter=false;
  }
  else{
    node<tree>*rightTree=root->right;
    if(rightTree->balance.isLH()){
      node<tree>*leftTree=rightTree->left;
      if(leftTree->balance.isLH()){
        rightTree->balance.setRH();
      }
      else if(leftTree->balance.isEH()){
        root->balance.setLH();
        rightTree->balance.setEH();
      }
      else{
        root->balance.setLH();
        rightTree->balance.setEH();
      }
      leftTree->balance.isEH();
      root->right=rotateRight(rightTree);
      root=rotateLeft(root);
    }
    else{
      if(!rightTree->balance.isEH()){
        root->balance.setEH();
        rightTree->balance.setEH();
      }
      else{
        root->balance.setRH();
        rightTree->balance.setLH();
        shorter=false;
      }
      root=rotateLeft(root);
    }
  }
  return root;
}
template<class tree>
node<tree>*AVLTree<tree>::deleteLeftBalance(node<tree>*root,bool&shorter){
  if(root->balance.isRH()){
    root->balance.setEH();
    shorter=false;
  }
  else if(root->balance.isEH()){
    root->balance.setLH();
    shorter=false;
  }
  else{
    node<tree>*leftTree=root->left;
    if(leftTree->balance.isRH()){
      node<tree>*rightTree=leftTree->right;
      if(rightTree->balance.isRH()){
        leftTree->balance.setLH();
        root->balance.setEH();
      }
      else if(rightTree->balance.isEH()){
        root->balance.setRH();
        leftTree->balance.setEH();
      }
      else{
        root->balance.setRH();
        leftTree->balance.setEH();
      }
      rightTree->balance.isEH();
      root->left=rotateLeft(leftTree);
      root=rotateRight(root);
    }
    else{
      if(!leftTree->balance.isEH()){
        root->balance.setEH();
        leftTree->balance.setEH();
      }
      else{
        root->balance.setLH();
        leftTree->balance.setRH();
        shorter=false;
      }
      root=rotateRight(root);
    }
  }
  return root;
}

template<class tree>
bool AVLTree<tree>::deleteNode(tree data){
  bool success=false;
  bool shorter=false;
  this->root=AVLDelete(this->root,data,shorter,success);
  if(success){
    return true;
  }
  else {
    return false;
  }
}
template<class tree>
node<tree>* AVLTree<tree>::getRoot(){
  return this->root;
}
template<class tree>
node<tree>* AVLTree<tree>::minNode(){
  if(this->root==NULL){
    return NULL;
  }
  node<tree>*minN=this->root;
  while(minN->left!=NULL){
    minN=minN->left;
  }
  node<tree>*newNode=node<tree>(minN->data);

  return newNode;
}
template<class tree>
node<tree>*AVLTree<tree>::maxNode(){
  if(this->root==NULL){
    return NULL;
  }
  node<tree>*maxN=this->root;
  while(maxN->right!=NULL){
    maxN=maxN->right;
  }
  node<tree>*newNode=node<tree>(maxN->data);
  return newNode;
}
template<class tree>
node<tree>*AVLTree<tree>::search(tree key){
  if(root==NULL){
    return NULL;
  }
  node<tree>*temp=root;
  while(temp!=NULL){
    if(temp->key==key){
      return temp;
    }
    else if(temp->key>key){
      temp=temp->left;
    }
    else {
      temp=temp->right;
    }
  }
  return NULL;
}
