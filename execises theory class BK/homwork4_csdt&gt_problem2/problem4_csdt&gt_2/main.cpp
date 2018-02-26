//
//  main.cpp
//  problem4_csdt&gt_2
//
//  Created by nguyen tan dung on 10/5/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
template<class typeNode>
class node{
public:
    typeNode data;
    node<typeNode>*link;
    node(){
        this->data=0;
        this->link=NULL;
    }
    node(typeNode data){
        this->data=data;
        this->link=NULL;
    }
};
template<class linkType>
class linkedlist{
public:
    node<linkType>*head;
    int count;
    linkedlist();
    ~linkedlist();
    
    void insertFirst(linkType value);
    void insertLast(linkType value);
    void insertItem(linkType value,int position);
    void deleteFirst();
    void deleteLast();
    int deleteItem(int position);
    void getItem(int position,linkType &dataOut);
    void Traverse();
    linkedlist<linkType>*Clone();
    void print2Console();
    void Clear();
    int deleteValue(linkType value);
    void reverse();
};
int main(int argc, const char * argv[]) {
    linkedlist<int>*link=new linkedlist<int>();
    linkedlist<int>*clone1=NULL;
    int choose;
    int width =20;
    int value;
    int position;
    do{
        cout<<setw(width+20)<<"Menu linked list "<<endl;
        cout<<setw(width)<<" ";
        
        cout<<left<<"1. insert First"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"2. insert Last"<<endl;
        cout<<setw(width)<<" ";

        cout<<"3. insert Item"<<endl;
        cout<<setw(width)<<" ";

        cout<<"4. delete First"<<endl;
        cout<<setw(width)<<" ";

        cout<<"5. delete Last"<<endl;
        cout<<setw(width)<<" ";

        cout<<"6. delete Item"<<endl;
        cout<<setw(width)<<" ";

        cout<<"7. get Item"<<endl;
        cout<<setw(width)<<" ";

        cout<<"8. traverse"<<endl;
        cout<<setw(width)<<" ";

        cout<<"9. deleteValue"<<endl;
        cout<<setw(width)<<" ";

        cout<<"10. print to console"<<endl;
        cout<<setw(width)<<" ";

        cout<<"11. create clone"<<endl;
        cout<<setw(width)<<" ";

        cout<<"12. reverse"<<endl;
        cout<<setw(width)<<" ";

        cout<<"13. exit"<<endl;
        cout<<endl;

        cout<<"       your choose : ";
        cin>>choose;
        switch (choose)
    {
            case 1:
                cout<<"please insert value: ";
                cin>>value;
                link->insertFirst(value);
                break;
            case 2:
                cout<<"please insert value: ";
                cin>>value;
                link->insertLast(value);
                break;
            case 3:
                cout<<"please insert value: ";
                cin>>value;
                cout<<"please input position: ";
                cin>>position;
                link->insertItem(value, position);
                break;
            case 4:
                link->deleteFirst();
                break;
            case 5:
                link->deleteLast();
                break;
            case 6:
                cout<<"please input position: ";
                cin>>position;
                link->deleteItem(position);
                break;
            case 7:
                cout<<"please input position: ";
                cin>>position;
                int dataout;
                link->getItem(position, dataout);
                cout<<"Item of position "<<position<<"th: "<<dataout<<endl;
                break;
            case 8:
                link->Traverse();
                cout<<"traverse has been done !!"<<endl;
                break;
            case 9:
            cout<<"please input value: ";
            cin>>value;
            link->deleteValue(value);
                break;
            case 10:
                link->print2Console();
                cout<<"printing linkedlist to console has been done !!"<<endl;
                break;
            case 11:

                clone1=link->Clone();
                clone1->print2Console();
                cout<<"clone has been created !!"<<endl;
                break;
            case 12:
                link->reverse();
                cout<<"linked list has been traversed"<<endl;
                break;
            case 13:
                delete link;
                break;
        }
    }
    while(choose!=13);
    cout<<"             Thank you for using our programming !! "<<endl;
    return 0;
}
template<class linkType>
linkedlist<linkType>::linkedlist(){
    this->head=NULL;
    this->count=0;
}
template<class linkType>
void linkedlist<linkType>::insertFirst(linkType value){
    node<linkType>*nNode=new node<linkType>(value);
    nNode->link=this->head;
    this->head=nNode;
    this->count++;
}
template<class linkType>
void linkedlist<linkType>::insertLast(linkType value){
    node<linkType>*nNode=new node<linkType>(value);
    if(this->head==NULL){
        this->head=nNode;
    }
    else {
        node<linkType>*temp=this->head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=nNode;
    }
    this->count++;
}
template<class linkType>
void linkedlist<linkType>::insertItem(linkType value,int position){
    if(position<=0 || position >this->count+1){
        throw "out of the range of linked list";
    }
    else{
        node<linkType>*nNode=new node<linkType>(value);
        node<linkType>*temp=this->head;
        int count=1;
        while(temp->link!=NULL && count!=position-1){
            temp=temp->link;
            count++;
        }
        nNode->link=temp->link;
        temp->link=nNode;
        this->count++;
    }
}
template<class linkType>
void linkedlist<linkType>::deleteFirst(){
    if(this->head!=NULL){
        node<linkType>*delNode=this->head;
        this->head=this->head->link;
        delete delNode;
        this->count--;
    }
}
template<class linkType>
void linkedlist<linkType>::deleteLast(){
    if(this->head!=NULL){
        node<linkType>*delNode=this->head;
        if(this->count==1){
            this->head=this->head->link;
            delete delNode;
            this->count=0;
            return ;
        }
        else{
            int count=1;
            while(count!=this->count-1){
                delNode=delNode->link;
                count++;
            }
            delNode->link=NULL;
            this->count--;
            return ;
        }
        
    }
    
}
template<class linkType>
int linkedlist<linkType>::deleteItem(int position){
    if(position<0||position>this->count){
        throw "out of range of linked list";
    }
    else{
        int count=1;
        int backup;
        if(this->count==1){
            backup=this->head->data;
            this->head=NULL;
            this->count=0;
            return backup;
        }
        else{
            node<linkType>*temp=this->head;
            
            while(count!=this->count-1){
                temp=temp->link;
                count++;
            }
            node<linkType>*delNode=temp->link;
            backup=delNode->data;
            temp->link=delNode->link;
            this->count--;
            return backup;
        }
    }
}
template<class linkType>
void linkedlist<linkType>::getItem(int position,linkType &dataOut){
    if(position<0||position>this->count){
        throw "out of range of linked list";
    }
    else{
        int count=1;
        node<linkType>*get=this->head;
        while(count!=position){
            get=get->link;
            count++;
        }
        dataOut=get->data;
    }
}
template<class linkType>
void linkedlist<linkType>::Traverse(){
    node<linkType>*traverse=this->head;
    while(traverse!=NULL){
        traverse=traverse->link;
    }
}
template<class linkType>
linkedlist<linkType>*linkedlist<linkType>::Clone(){
    linkedlist<linkType>*result=new linkedlist<linkType>();
    node<linkType>*p=this->head;
    while(p!=NULL){
        result->insertLast(p->data);
        p=p->link;
    }
    result->count=this->count;
    return result;
}
template<class linkType>
void linkedlist<linkType>::print2Console(){
    node<linkType>*traverse=this->head;
    while(traverse!=NULL){
        cout<<traverse->data<<" ";
        traverse=traverse->link;
    }
    cout<<endl;
}
template<class linkType>
void linkedlist<linkType>::Clear(){
    node<linkType>*delNode;
    while(this->head!=NULL){
        delNode=this->head;
        this->head=this->head->link;
        delete delNode;
        this->count--;
    }
}
template<class linkType>
linkedlist<linkType>::~linkedlist(){
    Clear();
}
template<class linkType>
int linkedlist<linkType>::deleteValue(linkType value){
    node<linkType>*delVal =this->head;
    node<linkType>*pre=this->head->link;
    int backup;
    if(this->head==NULL){
        cout<<"value doesn't coincide with anyvalue in linkedlist"<<endl;
        return 0;
    }
    if(this->head->data==value){
        this->head=this->head->link;
        backup=delVal->data;
        return backup;
    }
    while(pre!=NULL){
        if(pre->data==value){
            
            backup=pre->data;
            delVal->link=pre->link;
            delete pre;
            return backup;
        }
        delVal=delVal->link;
        pre=pre->link;
    }
    cout<<"value doesn't coincide with anyvalue in linkedlist"<<endl;
    return 0;
}
template<class linkType>
void linkedlist<linkType>::reverse(){
    linkType *array=new linkType[this->count];
    node<linkType>*temp=this->head;
    int count=0;
    while(temp!=NULL){
        array[count]=temp->data;
        count++;
        temp=temp->link;
    }
    temp=this->head;
    count--;
    for(int i=0;i<=count;i++){
        temp->data=array[count-i];
        temp=temp->link;
    }
    this->print2Console();
}
