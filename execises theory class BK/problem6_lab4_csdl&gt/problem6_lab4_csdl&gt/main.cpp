//
//  main.cpp
//  problem6_lab4_csdl&gt
//
//  Created by nguyen tan dung on 10/4/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//
#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;
template<class nodeType>
class node{
public:
    nodeType datax;
    nodeType datay;
    node<nodeType>*link;
    node(){
        datax=0;
        datay=0;
        this->link=NULL;
    }
    node(nodeType datax ,nodeType datay){
        this->datax=datax;
        this->datay=datay;
        this->link=NULL;
    }
};
template<class stackType>
class stack{
public:
    node<stackType>*top;
    int count;
    stack(){
        this->top=NULL;
        this->count=0;
    }
    void push(stackType datax,stackType datay){
        node<stackType>*Nnode=new node<stackType>(datax,datay);
        Nnode->link=this->top;
        this->top=Nnode;
        this->count++;
    }
    void print(){
        node<stackType>*temp=this->top;
        while(temp!=NULL){
            cout<<temp->datax<<" "<<temp->datay<<" ";
            temp=temp->link;
        }
        cout<<endl;
    }
    node<stackType>* pop(){
        if(this->count!=0){
            node<stackType>*Nnode=this->top;
            this->top=this->top->link;
            this->count--;
            return Nnode;
        }
        return NULL;
    }
    bool isempty(){
        if(this->top!=NULL){
            return false;
        }
        else return true;
    }
    ~stack(){
        node<stackType>*temp;
        while(this->top!=NULL){
            temp=this->top;
            this->top=this->top->link;
            delete temp;
        }
    }
};
bool problem6(stack<int>*head,stack<int>*head1,int **matrix,int n){
    head->push(0,0);
    node<int>*temp;
    node<int>*temp1;
    int i;
    int j;
    bool check=false;
    while (head->count>0){
        temp=head->pop();
        i=temp->datax;
        j=temp->datay;
        if(matrix[i][j]==2){
            return true;
        }
        if(i+1<n){
            if(matrix[i+1][j]!=-1){
                head->push(i+1,j);
                check=true;
            }
        }
        if(i-1>=0){
            if(matrix[i-1][j]!=-1){
                head->push(i-1,j);
                check=true;
            }
        }
        if(j+1<n){
            if(matrix[i][j+1] != -1){
                head->push(i,j+1);

                check=true;
            }
        }
        if(j-1>=0 ){
            if(matrix[i][j-1]!=-1){
                head->push(i,j-1);
                check=true;
            }
        }

        matrix[i][j]=-1;
        if(check==true){
            head1->push(i,j);
        }
        else temp1=head1->pop();
        check=false;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int **matrix;
    int n;
    cin>>n;
    srand((unsigned int)time(NULL));
    matrix=new int* [n];
    int checknumber;
    for(int i=0;i<n;i++){
        matrix[i]=new int [n];
        
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            checknumber=rand()%3;
            if(checknumber==1){
                matrix[i][j]=-1;
            }
            else matrix[i][j]=1;
        }
    }
    matrix[0][0]=0;
    matrix[n-1][n-1]=2;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<setw(3)<<right<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    stack<int>*head=new stack<int>();
    stack<int>*head1=new stack<int>();

    bool check;
    check=problem6(head,head1,matrix,n);
    if(check==true){
        head1->print();
    }
    else{
        cout<<"cannot find a way"<<endl;
    }
    
    return 0;
}
