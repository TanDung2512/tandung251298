//
//  main.cpp
//  list
//
//  Created by nguyen tan dung on 9/20/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
template<class ItemType>
class Node{
    ItemType data;
    Node<ItemType>*link;
    public :
    Node(){
        this->link=NULL;
    }
    Node(ItemType data){
        this->data=data;
        this->link=NULL;
    }
};

template<class list_itemType>
class LinkedList{
protected:
    Node<list_itemType>*head;
    int count;
    public :
    LinkedList();
    ~LinkedList();
    
    void InsertFirst(list_itemType value);
    void InsertLast(list_itemType value);
    int InsertItem(list_itemType value, int position);
    void DeleteFirst();
    void DeleteLast();
    int DeleteItem(int position);
    int GetItem(int position ,list_itemType &dataOut);
    void Traverse();
    LinkedList <list_itemType>*Clone();
    void Print2console();
    void clear();
};
template <class list_itemType>
    LinkedList<list_itemType>::LinkedList(){
    this->head=NULL;
    this->count=0;
}
template<class list_itemType>
int LinkedList<list_itemType>::InsertNode(Node<List



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
