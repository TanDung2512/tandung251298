
#include<iostream>
#ifndef _FUNCTIONS_LINKEDLIST_
#define _FUNCTIONS_LINKEDLIST_
template<class tempNode>
class node{
public:
  tempNode data;
  node<tempNode>*link;
public:
  node(){
    this->data=0;
    this->link=NULL;
  }
  node(tempNode data){
    this->data=data;
    this->link=NULL;
  }
  void setData(tempNode data){
    this->data=data;
  }
  void setLink(node*link){
    this->link=link;
  }
  tempNode getData(){
    return getData;
  }
  node* getLink(){
    return this->link;
  }
};
template<class tempLinkedList>
class linkedList{
public:
  node<tempLinkedList>*head;
  int count;
public:
  node<tempLinkedList>*loc;
  node<tempLinkedList>*Pre;
  void insertNode(node<tempLinkedList>*Pre,tempLinkedList value);
  void searchNode(node<tempLinkedList>*Pre,node<tempLinkedList>*loc,int position);
  void deleteNode(node<tempLinkedList>*Pre,node<tempLinkedList>*loc);
public:
  linkedList();
  ~linkedList();
  void insertFirst(tempLinkedList value);
  void insertLast(tempLinkedList value);
  void insertItem(tempLinkedList value,int position);
  void deleteFirst();
  void deleteLast();
  void deleteItem(int position );
  int getItem(int position,tempLinkedList&dataOut);
  void Traverse();
  linkedList<tempLinkedList>*clone();
  void clear();
};
#endif
using namespace std;

template<class tempLinkedList>
linkedList<tempLinkedList>::linkedList(){
  loc=NULL;
  Pre=NULL;
  this->head=NULL;
  this->count=0;
}
template<class tempLinkedList>
linkedList<tempLinkedList>::~linkedList(){
  this->clear();
}

template<class tempLinkedList>
void linkedList<tempLinkedList>::insertNode(node<tempLinkedList>*Pre,tempLinkedList value){
  if(Pre==NULL && loc=NULL){
    this->head=new node<tempLinkedList>(value);
  }
  if(Pre==NULL && loc!=NULL){
    
  }
  else{
    node<tempLinkedList>*newNode=new node<tempLinkedList>(value);
    newNode->link=Pre->link;
    Pre->link=newNode;
  }
  this->count++;
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::searchNode(node<tempLinkedList>*Pre,node<tempLinkedList>*loc,int position){
  if(position<0 || position >count+1){
    throw"out of range";
  }
  Pre=NULL;
  loc=this->head;
  int countPosition=0;
  while(loc!=NULL && countPosition!=position){
    Pre=loc;
    loc=loc->link;
    countPosition++;
  }
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::deleteNode(node<tempLinkedList>*Pre,node<tempLinkedList>*loc){
  if(Pre==NULL){
    delete loc;
    this->head=NULL;
    loc=NULL;
  }
  else{
    if(loc==NULL){
      delete Pre;
      Pre=NULL;
    }
    else {
      Pre->link=loc->link;
      delete loc;
      loc=NULL;
    }
  }
  this->count--;
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::insertLast(tempLinkedList value){
  searchNode(Pre,loc,count+1);
  insertNode(Pre,value);
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::insertFirst(tempLinkedList value){
  searchNode(Pre,loc,0);
  insertNode(Pre,value);
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::insertItem(tempLinkedList value,int position){
  searchNode(Pre,loc,position);
  insertNode(value);
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::deleteFirst(){
  searchNode(this->Pre,this->loc,0);
  deleteNode(this->Pre,this->loc);
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::deleteLast(){
  searchNode(Pre,loc,count+1);
  deleteNode(Pre,loc);
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::deleteItem(int position){
  searchNode(Pre,loc,position);
  deleteNode(Pre,loc);
}
template<class tempLinkedList>
int linkedList<tempLinkedList>::getItem(int position ,tempLinkedList &dataout){
  search(Pre,loc,position);
  if(loc==NULL){
    return 0;
  }
  else{
    dataout=loc->data;
    return 1;
  }
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::Traverse(){
  loc=this->head;

  cout<<"element in list with "<<this->count<<" "<<endl;
  while(loc!=NULL){
    cout<<loc->data<<"#";
    loc=loc->link;
  }
}
template<class tempLinkedList>
linkedList<tempLinkedList>*linkedList<tempLinkedList>::clone(){
  linkedList<tempLinkedList>*clone1;
  node<tempLinkedList>*temp=this->head;
  for(int i=0;i<count;i++){
    clone1->insertLast(temp->data);
    temp=temp->link;
  }
  return clone1;
}
template<class tempLinkedList>
void linkedList<tempLinkedList>::clear(){
  while(this->count!=0){
    deleteFirst();
  }
}
