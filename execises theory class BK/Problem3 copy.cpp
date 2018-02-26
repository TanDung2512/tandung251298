#include<iostream>
#include<vector>
#include<math.h>
#include<stack>
#include<iomanip>
using namespace std;
struct TreeNode{
  int data;
  TreeNode*leftchild;
  TreeNode*rightchild;
};
int numberofPrime(TreeNode*root){
  if(root==NULL){
    return 0;
  }
  int left=numberofPrime(root->leftchild);
  int right=numberofPrime(root->rightchild);
  int num=0;
  if(root->data==1||root->data==0){
     num=0;
  }
  else if(root->data==2){
    num=1;
  }
  else if(root->data==3){
    num=1;
  }
  else if(root->data%2==0){
    num=0;
  }
  else {
    num=1;
    for(int i=3;i<=sqrt(root->data);i+=2){
      if(root->data%i==0){
        num=0;
        break;
      }
    }
  }
  return num+left+right;
}
int main(){
  struct TreeNode * root =new struct TreeNode();
  struct TreeNode * root1=new struct TreeNode();
  struct TreeNode * root2=new struct TreeNode();
  struct TreeNode * root3=new struct TreeNode();
  struct TreeNode * root4=new struct TreeNode();
  struct TreeNode * root5=new struct TreeNode();
  struct TreeNode * root6=new struct TreeNode();
  struct TreeNode * root7=new struct TreeNode();
    root->leftchild=root1;
    root->rightchild=root2;
    root1->leftchild=root3;
    root1->rightchild=root4;
    root2->leftchild=root5;
    root2->rightchild=root6;
    root3->leftchild=root7;
    root3->rightchild=NULL;
    root4->leftchild=NULL;
    root4->rightchild=NULL;
    root5->leftchild=NULL;
    root5->rightchild=NULL;
    root6->leftchild=NULL;
    root6->rightchild=NULL;
    root7->leftchild=NULL;
    root7->rightchild=NULL;

    root->data=30;
    root1->data=30;
    root2->data=127;
    root3->data=20;
    root4->data=13;
    root5->data=19;
    root6->data=15;
    root7->data=18;
    cout<<"number of prime nodes: "<<numberofPrime(root)<<endl;
    return 0;
}
