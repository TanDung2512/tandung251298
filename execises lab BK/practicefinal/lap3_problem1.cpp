#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;
struct node{
  int data;
  node*link;
};
node*Nnode(node*N,int data){
  N=new node();
  N->data=data;
  N->link=NULL;
  return N;
}

#define node struct node
node* CreateListRandom(int n){
  node*head=Nnode(head,rand()%1000);
  n=n-1;
  while(n--){
    node*Nnod=Nnode(Nnod,rand()%10000);
    Nnod->link=head;
    head=Nnod;
  }
  return head;
}
void travese (node*head){
  node*temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->link;
  }
  cout<<endl;
}
void InsertTail(node*&head,int newData){
  node*temp=head;
  node*pNode=NULL;
  while(temp!=NULL){
    pNode=temp;
    temp=temp->link;
  }
  if(pNode==NULL){
    pNode=Nnode(pNode,newData);
  }
  else{
    pNode->link=Nnode(pNode->link,newData);
  }

}
void InsertHead(node*&head,int newData){
  node*temp=Nnode(temp,newData);
  temp->link=head;
  head=temp;
}
int sum(node*&pHead){
  int result =0;
  node*temp=pHead;
  while(temp!=NULL){
    result+=temp->data;
    temp=temp->link;
  }
  return result;
}
float PolyEval(node*&head,int x){
  node*temp=head;
  float result;
  int count=0;
  while(temp!=NULL){
    temp=temp->link;
    count++;
  }
  count--;
  temp=head;
  while(temp!=NULL){
    result+=pow(x,count)*temp->data;
    count--;
    temp=temp->link;
  }
  return result;
}
void DeleteData(node*&pHead,int delData){
  node*temp=pHead;
  node*pNode=NULL;
  while(temp!=NULL){
    if(temp->data==delData){
      break;
    }
    pNode=temp;
    temp=temp->link;
  }
  if(pNode==NULL){
    pHead=temp->link;
    delete temp;
    return ;
  }
  else {
    pNode->link=temp->link;
    delete temp;
    return ;
  }
  cout<<"cannot find\n";
}
node*ReverseList(node*root,int&n){
  node*pre=NULL;
  node*mid=root;
  node*post=root->link;
  while(1){
    if(post==NULL){
      mid->link=pre;
      root=mid;
      break;
    }
    mid->link=pre;
    pre=mid;
    mid=post;
    post=mid->link;
  }
  return root;
}
int main(){
  srand(time(NULL));
  node*list=CreateListRandom(10);
  travese(list);
  int a=5;
  int temp;
  int size=3;
  list=ReverseList(list,size);
  travese(list);
  // cout<<sum(list)<<endl;
  // cout<<PolyEval(list,1)<<endl;

  return 0;
}
