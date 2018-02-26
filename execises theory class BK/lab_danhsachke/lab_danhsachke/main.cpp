//
//  main.cpp
//  lab_danhsachke
//
//  Created by nguyen tan dung on 11/4/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
class point{
public:
    int data;
    point*link;
    bool check;
    point(){
        this->data=0;
        this->link=NULL;
        this->check=false;
    }
    point(int point){
        this->data=point;
        this->link=NULL;
        this->check=false;
    }
};
class list{
public:
    point*pointhead;
    point *pointnext;
    int count;
    list(){
        this->pointnext=NULL;
        this->pointhead=NULL;
        this->count=0;
    }
    void insert(int data){
        if(this->pointhead==NULL){
            this->pointhead=new point(data);
            
        }
        else{
            point*temp=this->pointhead;
            while(temp->link!=NULL){
                temp=temp->link;
            }
            temp->link=new point(data);
        }
        this->pointnext=this->pointhead->link;
        this->count++;
    }
    int nodenotcheck(){
        point*temp=this->pointnext;
        while(temp!=NULL){
            if(temp->check==false){
                temp->check=true;
                
                return temp->data;
            }
            temp=temp->link;

        }
        return -1;
        
    }
    void settrue(int i ){
        point*temp=this->pointnext;
        while(temp->data!=i){
            temp=temp->link;
        }
        temp->check=true;
    }
    void print(){
        if(this->pointnext!=NULL){
            point*temp=this->pointnext;
            while(temp!=NULL){
                cout<<this->pointhead->data<<" "<<temp->data<<endl;
                temp=temp->link;
            }
        }
    }
};
bool euler(list *listpoint,int i,int head){
    int a;
    bool check;
    a= listpoint[i].nodenotcheck();
    if(a==-1){
        if(i==head){
            return true;
        }
        else return false;
    }
    else{
        listpoint[a].settrue(i);

        check=euler(listpoint, a, head);
        if (check==true){
            return true;
        }
        else return false;
    }
}

    
    

int main(int argc, const char * argv[]) {
    int n;
    int point;
    cin>>n;
    list *listpoint=new list[n];
    for(int i=0;i<n;i++){
        listpoint[i].insert(i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>point;
            if(point==1){
                listpoint[i].insert(j);
            }
        }
    }
    for(int i=0;i<n;i++){
        listpoint[i].print();
    }
    bool check=euler(listpoint,0,0);
    if(check==true){
        cout<<"co duong di euler"   <<endl;
    }
    return 0;
}
