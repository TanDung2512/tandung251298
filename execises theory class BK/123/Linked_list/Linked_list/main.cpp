//
//  main.cpp
//  Linked_list
//
//  Created by nguyen tan dung on 9/21/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
template <class type>
class Node{
  public:
    type data;
    Node*link;

    Node(){
        this->link=NULL;
    }
    Node(type data){
        this->data=data;
        this->link=NULL;
    }
};
template<class linked_list1>
class linked_list {
public:
    Node<linked_list1>*head;
    Node<linked_list1>*last;
    int count=0;
public:
    linked_list();
    ~linked_list();
    void insert_position(linked_list1 data,int position);
    void insert_last(linked_list1 data);
    void insert_first(linked_list1 data);
    void deleteHead();
    void deleteNode(int position);
    void deleteLast();
    void deleteLink_list();
    Node<linked_list1> search(int data);
    Node<linked_list1>*searchPosition(int position);
    linked_list clone();
    void reverse();
    void outputLink();
    void outputNodePosition(int position);
};
template<class linked_list1>
linked_list<linked_list1>::linked_list(){
    this->head=NULL;
    this->last=NULL;
    this->count=0;
}
template<class linked_list1>
void linked_list<linked_list1>::insert_last(linked_list1 data){
    if(last==NULL){
        Node<linked_list1>*p1=new Node<linked_list1>(data);
        this->head=p1;
        this->last=p1;
        
    }
    else {
        this->last->link= new Node<linked_list1> (data);
        this->last=this->last->link;
        this->count++;
    }
}
template<class linked_list1>
void linked_list<linked_list1>::insert_position(linked_list1 data,int position){
    int countposition=1;
    if(position > this->count){
        cout<<" position is greater than size of link"<<endl;
    }
    else{
        Node<linked_list1> *pre =this->head;
            while(pre->link!=NULL ){
                if(countposition+1==position){
                    Node<linked_list1> *a1=new Node<linked_list1>(data );
                    a1->link=pre->link;
                    pre->link=a1;
                    this->count++;
                    break;
                }
                pre=pre->link;
                countposition++;
            }
    }
}
template<class linked_list1>
void linked_list<linked_list1>::insert_first(linked_list1 data){
    if(last!=NULL){
        Node <linked_list1>*a=new Node<linked_list1> (data);
        a->link=this->head;
        head=a;
    }
    else {
        this->last=new Node<linked_list1>(data);
        this->head=this->last;
    }
    this->count++;
}
template<class linked_list1>
Node<linked_list1> linked_list<linked_list1>::search(int data){
    Node <linked_list1> *pre=head;
    if(pre!=NULL){
        while(pre->link!=NULL){
            if(pre->data==data){
                return pre;
            }
            pre=pre->link;
        }
    }
    cout<<"cannot found value in list"<<endl;
    return NULL;
}
template<class linked_list1>
Node<linked_list1>*linked_list<linked_list1>::searchPosition(int position){
    int countPosition=0;
    if(this->last!=NULL){
        Node <linked_list1> *pre=head;
        while(pre->link!=NULL){
            if(countPosition+1==position){
                return pre;
            }
            countPosition++;
            pre=pre->link;
        }
    }
    return NULL;
}

template<class linked_list1>
void linked_list<linked_list1>::deleteLast(){
    if(head!=NULL){
        int countposition=0;
        Node<linked_list1>*temp=this->head;
        while(countposition!=this->count-1){
            temp=temp->link;
            countposition++;
        }
        this->last=temp;
        delete temp;
        temp=NULL;
    }
    
}
template<class linked_list1>
void linked_list<linked_list1>::deleteHead(){
    if(last!=NULL){
        Node<linked_list1> *temp=this->head;
        this->head=this->head->link;
        delete temp;
        temp=NULL;
    }
    else cout<<"there is no head"<<endl;
}
template<class linked_list1>
void linked_list<linked_list1>::deleteNode(int position){
    Node<linked_list1>*a=searchPosition(position-1);
    
    if(a !=NULL ){
        Node<linked_list1>*temp=a->link;
        a->link=temp->link;
        delete temp;
        temp=NULL;
    }
    else{
        cout<<"cannot delete Node because position is bigger than size"<<endl;
    }
}
template<class linked_list1>
linked_list<linked_list1> linked_list<linked_list1>::clone(){
    if(this->last!=NULL){
        linked_list<linked_list1> *clone =this->head;
        return clone;
    }
    else return NULL;
}
template<class linked_list1>
void linked_list<linked_list1>::outputLink(){
    if(this->last!=NULL){
        int position=0;
        Node<linked_list1> *a=this->head;
        while(a!=NULL){
            cout<<"Node "<<position<<": "<<a->data<<endl;
            position++;
            a=a->link;
        }
    }
}
template<class linked_list1>
void linked_list<linked_list1>::outputNodePosition(int position){

    if(position<= this->count){
        Node<linked_list1>*a;
        a=searchPosition(position);
        if(a!=NULL){
            cout<<a->data<<endl;
        }
        delete a;
        a=NULL;
        
    }
}
template<class linked_list1>
void linked_list<linked_list1>::deleteLink_list(){
        Node<linked_list1>*temp=NULL;
        while(this->head!=NULL){
            temp=this->head;
            this->head=this->head->link;
            delete temp;
            temp=NULL;
        }
        head=NULL;
        last=NULL;
        this->count=0;
}

template<class linked_list1>
linked_list<linked_list1>::~linked_list(){
    deleteLink_list();
}
template<class linked_list1>
void linked_list<linked_list1>::reverse(){
    linked_list1 *a=new linked_list1[this->count];
    Node<linked_list1> *temp=this->head;
    for(int i=0;i<=this->count;i++){
        a[i]=temp->data;
        temp=temp->link;
    }
    temp=this->head;
    for(int i=0;i<=this->count;i++ ){
        temp->data=a[this->count-i];
        temp=temp->link;
    }
}
int main(int argc, const char * argv[]) {
    linked_list<int> *list1=new linked_list<int>();
    int n;
    int choose;
    int temp;

    do{
        cout<<"what do you want ?"<<endl;
        cout<<"1.size of linked list"<<endl;
        cout<<"2.insert at first "<<endl;
        cout<<"3.insert at position"<<endl;
        cout<<"4.insert at last"<<endl;
        cout<<"5.Delete Node at head "<<endl;
        cout<<"6.Delete Node at position"<<endl;
        cout<<"7.Delete Node at last"<<endl;
        cout<<"8.Delete Linked List"<<endl;
        cout<<"9.Travese "<<endl;
        cout<<"10.Output link"<<endl;
        cout<<"11.Output Node at position"<<endl;
        cout<<"12.reverse"<<endl;
        cout<<"13.break"<<endl;
        cin>>choose;
        if(choose<=0 || choose>12){
            cout<<"nhap lai "<<endl;
        }
        else{
            
            switch (choose) {

                case 1:
                    cout<<"input your size= ";
                    cin>>n;
                    cout<<"input your data= ";
                    for(int i=0;i<n;i++){
                        cin>>temp;
                        list1->insert_last(temp);
                    }
                    break;
                case 2:
                    cout<<"input your dâta: ";
                    cin>>temp;
                    list1->insert_first(temp);
                    break;
                case 3:
                    cout<<"input your dâta: ";
                    cin>>temp;
                    cout<<"the position that you wanna insert: ";
                    int position;
                    cin>>position;
                    list1->insert_position(temp, position);
                    break;
                case 4:
                    cin>>temp;
                    list1->insert_last(temp);
                    break;
                case 5:
                    list1->deleteHead();
                    break;
                case 6:
                    cout<<"the position that you wanna delete: ";
                    cin>>position;
                    list1->deleteNode(position);
                    break;
                case 7:
                    list1->deleteLast();
                    break;
                case 8:
                    list1->deleteLink_list();
                    break;
                case 9:
//                    list1->traverse();
                    break;
                case 10:
                    list1->outputLink();
                    break;
                case 11:
                    cout<<"the position that you wanna output: ";
                    cin>>position;
                    list1->outputNodePosition(position);
                    break;
                case 12:
                    list1->reverse();
                    break;
                case 13:
                    delete list1;
                    break;
            }
        }
        }while(choose!=13);

    return 0;
}
