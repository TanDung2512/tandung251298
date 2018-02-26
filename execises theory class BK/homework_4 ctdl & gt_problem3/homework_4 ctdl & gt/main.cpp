//
//  main.cpp
//  homework_4 ctdl & gt
//
//  Created by nguyen tan dung on 9/29/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <sstream>
#include<math.h>
using namespace std;
template <class node_type>
class node{
    public:
    node_type data;
    node<node_type>*link;
    node(){
        this->link=NULL;
        this->data=0;
    }
    node(node_type data){
        this->link=NULL;
        this->data=data;
    }
};

template<class linkedlist1>
class linked_list{
public:
    node<linkedlist1>*head;
    node<linkedlist1>*tail;
    linked_list *link=NULL;
    int count;
    linked_list();
    ~linked_list();
    void insert_node(linkedlist1 data);
    void setdata(linkedlist1 data,int position);
    void deletelinkedlist();
    node<linkedlist1>* searchnode(int position);
    void deletehead();
    void checkzerohead();
    void coutpolimyal();
    void inserthead(linkedlist1 data);
};
template<class linkedlist1>
void linked_list<linkedlist1>::inserthead(linkedlist1 data){
    node<linkedlist1>*nNode=new node<linkedlist1>(data);
    nNode->link=this->head;
    this->head=nNode;
    this->count++;
}
template<class linkedlist1>
void linked_list<linkedlist1>::deletehead(){
    if(this->head!=NULL){
        node<linkedlist1>*temp=this->head;
        this->head=this->head->link;
        if(this->count>0){
            this->count--;
        }
        delete temp;
    }
}
template<class linkedlist1>
void linked_list<linkedlist1>::checkzerohead(){
    while(this->head->data==0 & this->count>0){
        node<linkedlist1>*temp=this->head;
        this->head=this->head->link;
        this->count--;
        delete temp;
    }
}
template<class linkedlist1>
linked_list<linkedlist1>::linked_list(){
    this->head=NULL;
    this->tail=NULL;
    this->count=0;
}
template<class linkedlist1>
void linked_list<linkedlist1>::insert_node(linkedlist1 data){
    if(this->head==NULL){
        node<linkedlist1>*Nnode=new node<linkedlist1>(data);
        this->head=Nnode;
        this->tail=Nnode;
    }
    else{
        this->tail->link=new node<linkedlist1>(data);
        this->tail=this->tail->link;
        this->count++;
    }
}
template<class linkedlist1>
void linked_list<linkedlist1>::deletelinkedlist(){
    node<linkedlist1>*delNode=NULL;
    while(this->head!=NULL){
        delNode=this->head;
        this->head=this->head->link;
        delete delNode;
    }
    delNode =NULL;
    this->head=NULL;
    this->count=0;
    this->tail=NULL;
}
template<class linkedlist1>
node<linkedlist1>* linked_list<linkedlist1>::searchnode(int position){
    node<linkedlist1>*temp=this->head;
    int i=0;
    while(i<position){
        temp=temp->link;
        i++;
    }
    return temp;
}
template<class linkedlist1>
void linked_list<linkedlist1>::setdata(linkedlist1 data,int position){
    node<linkedlist1>*temp=searchnode(position);
    cout<<data<<endl;
    temp->data+=data;
}
template<class linkedlist1>
linked_list<linkedlist1>::~linked_list(){
    deletelinkedlist();
}
template<class linkedlist1>
void linked_list<linkedlist1>::coutpolimyal(){
    node<linkedlist1>*temp=this->head;
    if(this->count!=0){
    if(temp->data != 0){
        cout<<temp->data<<"x^"<<this->count;
    }
    temp=temp->link;
    for (int i=1;i<this->count; i++) {
        if( temp->data>0){
            cout<<"+"<<temp->data<<"x^"<<this->count-i;
        }
        if( temp->data<0){
            cout<<temp->data<<"x^"<<this->count-i;
        }
        temp=temp->link;
    }
    if(temp->data>0 & this->count!=0){
        cout<<"+"<<temp->data;
    }
    else if( temp->data<0 ){
        cout<<temp->data;
    }
    cout<<endl;
    }
    else {
        cout<<temp->data<<endl;
    }
}
template<class linkedlist1>
class polynomial{
public:
    linked_list<linkedlist1>*head;
    int count;
    linked_list<linkedlist1>*tail;
    polynomial(){
        this->head=NULL;
        this->tail=NULL;
    }
    void insertpolynomial(linked_list<linkedlist1> *data){
        if(this->tail==NULL){
            this->tail=data;
            this->head=data;
            this->count=1;
        }
        else{
            this->tail->link=data;
            this->tail=this->tail->link;
            this->count++;
        }
    }
    ~polynomial(){
        linked_list<linkedlist1>*pdel=this->head;
        while(head!=NULL){
            pdel=this->head;
            this->head=this->head->link;
            delete pdel;
        }
        pdel=NULL;
        head=NULL;
        tail=NULL;
        this->count=1;
    }
// sum
        linked_list<linkedlist1>* sumconvertpositiontolinkedlist1(int position1,int position2){

        linked_list<linkedlist1>*temp=this->head;
        linked_list<linkedlist1>*a1templist=NULL;
        linked_list<linkedlist1>*a2templist=NULL;
        int count1=1;
        while(count1<=this->count){
            if(position1==count1){
                a1templist=temp;
            }
            if(position2==count1){
                a2templist=temp;
                break;
            }
            temp=temp->link;
            count1++;
        }
        return sumpolomial(a1templist, a2templist);
    }
        linked_list<linkedlist1>* subconvertpositiontolinkedlist1(int position1,int position2){
        
        linked_list<linkedlist1>*temp=this->head;
        linked_list<linkedlist1>*a1templist=NULL;
        linked_list<linkedlist1>*a2templist=NULL;
        int count1=1;
        while(count1<=this->count){
            if(position1==count1){
                a1templist=temp;
            }
            if(position2==count1){
                a2templist=temp;
                break;
            }
            temp=temp->link;
            count1++;
        }
        return subpolomial(a1templist, a2templist);
    }
        linked_list<linkedlist1>* mulconvertpositiontolinkedlist1(int position1,int position2){
        
        linked_list<linkedlist1>*temp=this->head;
        linked_list<linkedlist1>*a1templist=NULL;
        linked_list<linkedlist1>*a2templist=NULL;
        int count1=1;
        while(count1<=this->count){
            if(position1==count1){
                a1templist=temp;
            }
            if(position2==count1){
                a2templist=temp;
                break;
            }
            temp=temp->link;
            count1++;
        }
        return mulpolomial(a1templist, a2templist);
    }
        float* calconvertpositiontolinkedlist1(int position1,int num){
            linked_list<linkedlist1>*temp=this->head;
            linked_list<linkedlist1>*a1templist=NULL;
            int count1=1;
            while(count1<=this->count){
                if(position1==count1){
                    a1templist=temp;
                    break;
                }
                temp=temp->link;
                count1++;
            }
        return calculate(a1templist,num);
        }

    void divconvertpositiontolinkedlist1(int position1,int position2){
        
        linked_list<linkedlist1>*temp=this->head;
        linked_list<linkedlist1>*a1templist=NULL;
        linked_list<linkedlist1>*a2templist=NULL;
        int count1=1;
        while(count1<=this->count){
            if(position1==count1){
                a1templist=temp;
            }
            if(position2==count1){
                a2templist=temp;
                break;
            }
            temp=temp->link;
            count1++;
        }
         divpolomial(a1templist, a2templist);
    }

    linked_list<linkedlist1>*sumpolomial(linked_list<linkedlist1>*a1templist,linked_list<linkedlist1>*a2templist){
        linked_list<linkedlist1>*sum=new linked_list<linkedlist1>();
        node<linkedlist1>*a1temp=NULL;
        node<linkedlist1>*a2temp=NULL;
        a1temp=a1templist->head;
        a2temp=a2templist->head;
        int minus=a1templist->count-a2templist->count;
        if(minus<0){
            minus=minus*(-1);
        }
        int max=a1templist->count;
        if(max<a2templist->count){
            max=a2templist->count;
        }
        for(int i=0;i<=max;i++){
            sum->insert_node(0);
        }

        if(a2templist->count < a1templist->count ){
            for(int i=1;i<=minus;i++){
                a2templist -> inserthead(0);
            }
        }
        else if(a2templist->count > a1templist->count ){
            for(int i=1;i<=minus;i++){
                a1templist -> inserthead(0);
            }
        }
        node<linkedlist1>*check=a2templist->head;

        for(int i=0;i<=a2templist->count;i++){
            cout<<"data : "<<check->data<<endl;
            check=check->link;
        }
        a1temp=a1templist->head;
        a2temp=a2templist->head;
        for(int i=0;i<=max;i++){
            sum->setdata(a1temp->data + a2temp->data,i);
            a1temp=a1temp->link;
            a2temp=a2temp->link;
        }
        a2templist->checkzerohead();
        a1templist->checkzerohead();
        sum->checkzerohead();
        return sum;
    }
    linked_list<linkedlist1>*subpolomial(linked_list<linkedlist1>*a1templist,linked_list<linkedlist1>*a2templist){

        linked_list<linkedlist1>*sub=new linked_list<linkedlist1>();
        node<linkedlist1>*a1temp=NULL;
        node<linkedlist1>*a2temp=NULL;
        a1temp=a1templist->head;
        a2temp=a2templist->head;
        int minus=a1templist->count-a2templist->count;
        if(minus<0){
            minus=minus*(-1);
        }
        int max=a1templist->count;
        if(max<a2templist->count){
            max=a2templist->count;
        }
        for(int i=0;i<=max;i++){
            sub->insert_node(0);
        }
        if(a2templist->count < a1templist->count){
            for(int i=1;i<=minus;i++){
                a2templist->inserthead(0);
            }
        }
        else if(a2templist->count>a1templist->count){
            for(int i=1;i<=minus;i++){
                a1templist->inserthead(0);
            }
        }
        a1temp=a1templist->head;
        a2temp=a2templist->head;
        for(int i=0;i<=max;i++){
            sub->setdata(a1temp->data-a2temp->data,i);
            a1temp=a1temp->link;
            a2temp=a2temp->link;
        }
        a2templist->checkzerohead();
        a1templist->checkzerohead();
        sub->checkzerohead();
        return sub;
    }
     linked_list<linkedlist1>*mulpolomial(linked_list<linkedlist1>*a1templist,linked_list<linkedlist1>*a2templist){
         linked_list<linkedlist1>*mul=new linked_list<linkedlist1>();
         node<linkedlist1>*a1temp=NULL;
         node<linkedlist1>*a2temp=NULL;
         a1temp=a1templist->head;
         a2temp=a2templist->head;
         int condition=a1templist->count+a2templist->count;
         node<linkedlist1>*temp1=a2temp;
         for(int i=0;i<=condition;i++){
             mul->insert_node(0);
         }
         for(int i=0;i<=a1templist->count;i++){
             for(int j=0;j<=a2templist->count;j++){
                 mul->setdata(temp1->data*a1temp->data,a2templist->count-j+a1templist->count-i);
                 temp1=temp1->link;
             }
             temp1=a2temp;
             a1temp=a1temp->link;
         }
         
         mul->checkzerohead();
         return mul;
     }
    void divpolomial(linked_list<linkedlist1>*a1templist,linked_list<linkedlist1>*a2templist){
        node<linkedlist1>*a1temp=NULL;
        node<linkedlist1>*a2temp=NULL;
        a1temp=a1templist->head;
        a2temp=a2templist->head;
        int order=a1templist->count-a2templist->count;
        if(order<0){
             cout<<"cannot divide"<<endl;
        }
        int minus=a1templist->count-a2templist->count;
        linked_list<linkedlist1>*divident=new linked_list<linkedlist1>();
        for(int i=0;i<=minus;i++){
            divident->insert_node(0);
        }
        linked_list<linkedlist1>*remainder=NULL;
        if(order>=0){
             divident=recursive(a1templist,a2templist,divident,remainder);
        }
        divident->coutpolimyal();
        remainder->coutpolimyal();
    }
    linked_list<linkedlist1>*recursive(linked_list<linkedlist1>*divisor,linked_list<linkedlist1>*quotient,linked_list<linkedlist1>*divident,linked_list<linkedlist1>*&remainder){
        if(divisor->count<quotient->count){
            remainder=divisor;
            return divident;
        }
        else {
            node<linkedlist1>*first1=divisor->head;
            node<linkedlist1>*first2=quotient->head;
            int minus=divisor->count-quotient->count;
            float divi=(float)first1->data/first2->data;
            divident->setdata(divi,divident->count-minus);
            linked_list<linkedlist1>*newquotient=new linked_list<linkedlist1>();
            
            for(int i=0;i<=quotient->count;i++){
                newquotient->insert_node(first2->data*divi);
                first2=first2->link;
            }
            for(int i=1;i<=minus;i++){
                newquotient->insert_node(0);
            }
            
            cout<<"quotienmt: ";
            quotient->coutpolimyal();
            cout<<"newquotient: ";
            newquotient->coutpolimyal();
            first1=divisor->head;
            first2=newquotient->head;
            linked_list<linkedlist1>*newdivisor=new linked_list<linkedlist1>();
            divisor->coutpolimyal();
            newquotient->coutpolimyal();
            if((first1->data>0 & first2->data<0) ||(first1->data<0 &first2->data>0)){
                newdivisor=sumpolomial(divisor, newquotient);
            }
            else{
                newdivisor=subpolomial(divisor, newquotient);
            }
            
            return recursive(newdivisor,quotient,divident,remainder);
        }
    }
    float*calculate(linked_list<linkedlist1>*cal,int num){
        float *mul=new float();
        *mul=0;
        node<linkedlist1>*temp=cal->head;
        for(int i=0;i<=cal->count;i++){
            *mul+=temp->data*powf(num, cal->count-i);
            temp=temp->link;
        }
        return mul;
    }
};

int order_polinomial(string input){
    stringstream ss;
    int temp=0;
    bool check=false;
    for(int i=0;i<input.length();i++){
        if(input[i]=='^'){
            check=true;
            ss<<input[i+1];
            ss>>temp;
            break;
        }
    }
    if(check==false){
        temp=1;
    }
    return temp;
}
string checkinput(string &input){
    stringstream ss;
    ss<<input;
    string temp;
    string temp1;
    while(ss>>temp1){
        temp.append(temp1);
        temp1.clear();
    };
    return temp;
}
template<class linkedlist1>
linked_list<linkedlist1>*convertStringtolinkedlist(string input){
    stringstream ss;
    linked_list<linkedlist1>*temp=new linked_list<linkedlist1>();
    linkedlist1 ssint,ssint2;
    int max=1;
    for(int i=0;i<input.length();i++){
        if(input[i]=='^'){
            ss<<input[i+1];
            ss>>ssint;
            if(ssint>max){
                max=ssint;
            }
            ss.clear();
        }
    }
    for(int i=0;i<=max;i++){
        temp->insert_node(0);
    }
    char ch=' ';
    input.append(&ch);
    input.append(&ch);
    input.append(&ch);
    input.append(&ch);

    cout<<input<<endl;

    int a=0;
    bool check=false;
    while(input[a]!='+' & a<4){
        a++;
        if(input[a]=='+'){
            check=true;
        }
    }
    if(check==false){
        if(input[0]=='x'){
            if(input[1]=='^'){
                ss<<input[2];
                ss>>ssint;
                ss.clear();
                temp->setdata(1,temp->count-ssint);
            }
            else{
                temp->setdata(1,temp->count-1);
            }
        }
        else{
            if(input[1]=='x'||input[1]=='X'){
                if(input[2]=='^'){
                    ss<<input[3];
                    ss>>ssint;
                    ss.clear();
                    ss<<input[0];
                    ss>>ssint2;
                    ss.clear();
                    temp->setdata(ssint2,temp->count-ssint);
                }
                else{
                    ss<<input[0];
                    ss>>ssint2;
                    ss.clear();
                    temp->setdata(ssint2,temp->count-1);
                }
            }
            else{
                ss<<input[0];
                ss>>ssint2;
                temp->setdata(ssint2,temp->count);
                ss.clear();
            }
        }
    }
    else{
//    if(a==4){
//        ss<<input[a-1];
//        ss>>ssint;
//        ss.clear();
//        ss<<input[a-4];
//        ss>>ssint2;
//        ss.clear();
//        temp->setdata(ssint2,temp->count-ssint);
//    }
//    else if(a==3){
//        ss<<input[a-1];
//        ss>>ssint;
//        ss.clear();
//
//        temp->setdata(1,temp->count-ssint);
//    }
//    else if(a==2){
//        ss<<input[a-1];
//        ss>>ssint;
//        ss.clear();
//
//        temp->setdata(ssint,temp->count-0);
//    }
    for(int i=a;i<input.length()-4;i++){
        if(input[i]=='+' || input[i]=='-'){
            if(input[i+1]=='x'||input[i+1]=='X'){
                if(input[i+2]=='^'){
                    ss<<input[i+3];
                    ss>>ssint;
                    ss.clear();
                    if(input[i]=='+'){
                        temp->setdata(1,temp->count-ssint);
                    }
                    else
                        temp->setdata(-1,temp->count-ssint);
                    i+=3;
                }
                else{
                    if(input[i]=='+'){
                        temp->setdata(1,temp->count-1);
                    }
                    else
                        temp->setdata(-1,temp->count-1);
                    i+=1;
                }
            }
            else{
                if(input[i+3]=='^'){
                    ss<<input[i+4];
                    ss>>ssint;
                    ss.clear();
                    ss<<input[i+1];
                    ss>>ssint2;
                    ss.clear();
                    if(input[i]=='+'){
                        temp->setdata(ssint2,temp->count-ssint);
                    }
                    else
                        temp->setdata(-ssint2,temp->count-ssint);
                    i+=4;
                }
                else if(input[i+2]=='x'||input[i+2]=='X')
                {
                    ss<<input[i+1];
                    ss>>ssint2;
                    ss.clear();
                    if(input[i]=='+'){
                        temp->setdata(ssint2,temp->count-1);
                    }
                    else
                        temp->setdata(-ssint2,temp->count-1);
                    i+=2;
                }
                else{
                    ss<<input[i+1];
                    ss>>ssint2;
                    ss.clear();
                    if(input[i]=='+'){
                        temp->setdata(ssint2,temp->count);
                    }
                    else
                        temp->setdata(-ssint2,temp->count);
                    i+=1;
                }
            }
        }
    }
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    string input;
    char check;
    string operator1;

    int position[2];

    stringstream ss;
    bool check_true;
    char ch;
    int countP=1;
    polynomial<float>*listpolinomial = new polynomial<float>();
    linked_list<float> *result=NULL;
    cout<<"start to input polynomial"<<endl;
    do{
        cout<<"input polynomial P"<<countP<<": ";
        
        ch=getchar();
        getline(std::cin,input);
        input.insert(0,1,ch);
        cout<<input<<endl;
        listpolinomial->insertpolynomial(convertStringtolinkedlist<float>(     checkinput(input)));
        cout<<"continue input polynomial or not ( Y/N )"<<endl;
        cin>>check;
        if(check=='y'||check=='Y'){
            check_true=true;
            countP++;
        }
        else {
            check_true=false;
            cout<<" stop inputing polynomial !"<<endl;
        }
    }while(check_true==true);
    
    do{
        cout<<"Perform math operations: (P_i add sub mul div P_j)"<<endl;
        input.clear();
        getchar();
        getline(cin,input);
        operator1=checkinput(input);
        string temp;
        int count1=0;
        int tempint;
        temp=operator1.substr(2,3);
        cout<<temp<<endl;
        for(int i=0;i<input.length();i++){
            if(input[i]=='P'||input[i]=='p'){
                ss.clear();
                ss<<input.at(i+1);
                ss>>tempint;
                position[count1]=tempint;
                count1++;
            }
            
        }
        if(position[0]>position[1]){
            int temp123=position[0];
            position[0]=position[1];
            position[1]=temp123;
        }
        if(temp=="add"){
            result=listpolinomial->sumconvertpositiontolinkedlist1(position[0], position[1]);
            result->coutpolimyal();
        }
        if(temp=="sub"){
            result=listpolinomial->subconvertpositiontolinkedlist1(position[0],position[1]);
            result->coutpolimyal();
        }
        if(temp=="mul"){
            result=listpolinomial->mulconvertpositiontolinkedlist1(position[0], position[1]);
            result->coutpolimyal();
        }
        if(temp=="div"){
            listpolinomial->divconvertpositiontolinkedlist1(position[0], position[1]);
        }
        if(temp=="cal"){
            cout<<"replaced x by : ";
            int n;
            cin>>n;
            float *resultcal=listpolinomial->calconvertpositiontolinkedlist1(position[0],n);
            cout<<*resultcal<<endl;
            }
        delete result;
        result=NULL;
        
        cout<<"continue or not "<<endl;
        cin>>check;
        if(check=='y'||check=='Y'){
            check_true=true;
            countP++;
        }
        else {
            check_true=false;
            cout<<" stop inputing polynomial !"<<endl;
        }
    }while(check_true==true);
    delete listpolinomial;
    listpolinomial=NULL;
    return 0;
}
