#include<iostream>
#include<vector>
#include<math.h>
#include<stack>
#include<iomanip>

using namespace std;
struct node{
  int data;
  node*link;
};
struct TreeNode{
  int data;
  TreeNode*leftchild;
  TreeNode*rightchild;
};
double hashFunction(string a){
  double sum=0;
  for(int i=0;i<a.size();i++){
    if(i==a.size()-1){
      sum+=pow((int)a[a.size()-1],(int)a[0]);
      break;
    }
    sum+=pow(a[i],a[i+1]);
  }
  return sum;
}
double hashFunctionb(int*heap,int size){
  double sum=0;
  for(int i=0;i<size;i++){
    sum+=pow(heap[i],log2(i+1)+1);
  }
  return sum;
}
node* insertion(node*head){
  if(head==NULL){
    return NULL;
  }
  else if(head->link==NULL){
    return head;
  }
  node*traverse=head->link;
  node*pre=head;
  while(traverse!=NULL){
    node*temp=head;
    node*pre1=NULL;
    while(temp!=traverse){
      if(traverse->data<temp->data){
        if(pre1==NULL){
          pre->link=traverse->link;
          traverse->link=temp;
          head=traverse;
          traverse=pre;
          break;
        }
        pre->link=traverse->link;
        pre1->link=traverse;
        traverse->link=temp;
        traverse=pre;
        break;
      }
      else{
        pre1=temp;
        temp=temp->link;
      }
    }
    pre=traverse;
    traverse=traverse->link;
  }
  return head;
}
struct Node1{
  char data;
  Node1*left;
  Node1*right;
};
int calculator(struct Node1 * root){
  if(root==NULL){
    return 0;
  }
  if(root->data>='0' && root->data<='9'){
    return root->data-'0';
  }
  int left = calculator(root->left);
  int right=calculator(root->right);
  if(root->data=='+'){
    return left+right;
  }
  else if(root->data=='-'){
    return left-right;
  }
  else if(root->data=='*'){
    return left*right;
  }
  else if(root->data=='/'){
    return left/right;
  }
  else return 0;
}
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
  int heap1[]={30,30};
  cout<<fixed<<hashFunction("a")<<endl;
  // node*node1=new node();
  // node*node2=new node();
  // node*node3=new node();
  // node*node4=new node();
  // node*node5=new node();
  // node*node6=new node();
  //
  // node1->link=node2;
  // node2->link=node3;
  // node3->link=node4;
  // node4->link=NULL;
  // node5->link=NULL;
  // node6->link=NULL;
  // node1->data=13;
  // node2->data=10;
  // node3->data=1;
  // node4->data=9;
  // node5->data=2;
  // node6->data=6;
  // node1=insertion(node1);
  // node*temp=node1;
  // while(temp!=NULL){
  //   cout<<temp->data<<endl;
  //   temp=temp->link;
  // }

  struct Node1 * root =new struct Node1();
  struct Node1 * root1=new struct Node1();
  struct Node1 * root2=new struct Node1();
  struct Node1 * root3=new struct Node1();
  struct Node1 * root4=new struct Node1();
  struct Node1 * root5=new struct Node1();
  struct Node1 * root6=new struct Node1();
  struct Node1 * root7=new struct Node1();
  struct Node1 * root8=new struct Node1();
  struct Node1 * root9=new struct Node1();
  struct Node1 * root10=new struct Node1();
  struct Node1 * root11=new struct Node1();
  struct Node1 * root12=new struct Node1();

    root->left=root1;
    root->right=root2;
    root1->left=root3;
    root1->right=root4;
    root2->left=root5;
    root2->right=root6;
    root3->left=root7;
    root3->right=root8;
    root4->left=root9;
    root4->right=root10;
    root5->left=NULL;
    root5->right=NULL;
    root6->left=root11;
    root6->right=root12;
    root7->left=NULL;
    root7->right=NULL;
    root8->left=NULL;
    root8->right=NULL;
    root9->left=NULL;
    root9->right=NULL;
    root10->left=NULL;
    root10->right=NULL;
    root11->left=NULL;
    root11->right=NULL;
    root12->left=NULL;
    root12->right=NULL;
    root->data='+';
    root1->data='/';
    root2->data='*';
    root3->data='*';
    root4->data='-';
    root5->data='5';
    root6->data='-';
    root7->data='2';
    root8->data='3';
    root9->data='2';
    root10->data='1';
    root11->data='4';
    root12->data='1';


    cout<<calculator(root)<<endl;
  return 0;
}
