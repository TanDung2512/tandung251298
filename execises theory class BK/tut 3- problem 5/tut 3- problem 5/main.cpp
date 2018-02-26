//
//  main.cpp
//  tut 3- problem 5
//
//  Created by nguyen tan dung on 9/28/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
class node{
public:
    node*link;
    int data;
    
    node(){
        this->link=NULL;
        this->data=0;
    }
    node(int data){
        this->link=NULL;
        this->data=data;
    }
    
};
int main(int argc, const char * argv[]) {
    int *array=new int[10];
    node *linkedlist=new node();
    node *temp=linkedlist;
    for(int i=1;i<10;i++){
        temp->link=new node();
        temp=temp->link;
    }
    for(int i=0;i<10;i++){
        cout<<"adress of array "<<i<<"th= "<<array+i<<endl;
    }
    temp=linkedlist;
    for(int i=0;i<10;i++){
        cout<<"adress of Node"<<i<<"th= "<<temp<<endl;
        temp=temp->link;
    }
    delete array;
    delete linkedlist;
    array=NULL;
    linkedlist=NULL;
    return 0;
}
