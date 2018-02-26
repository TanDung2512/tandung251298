//
//  dynamic.cpp
//  dynamic array
//
//  Created by nguyen tan dung on 9/13/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include "dynamic.hpp"
#include "String.h"
using namespace std;
void DynamicArray:: setCapacity(int NewCapacity)
{
    int *newStorage=new int [NewCapacity];
    memcpy(newStorage,storage,sizeof(int)*size);
    capacity=NewCapacity;
    delete[] storage;
    storage=newStorage;
}
DynamicArray::DynamicArray(int capacity){
    this->capacity=capacity;
    size=0;
    storage=new int[capacity];
    
}
DynamicArray::~DynamicArray(){
    delete [] storage;
}
void DynamicArray::ensureCapacity(int minCapacity){
    if(minCapacity>capacity){
        int newCapacity=(capacity*3)/2+1;
        if(newCapacity<minCapacity)
            newCapacity=minCapacity;
        setCapacity(newCapacity);
        }
}
void DynamicArray::pack(){
    if(size<=capacity/2){
        int newCapacity=(size*3)/2+1;
    setCapacity(newCapacity);
    }
}
void DynamicArray::trim(){
    int newCapacity=size;
    setCapacity(newCapacity);
}
void DynamicArray::rangeCheck(int index){
    if(index<0 || index>=size)
        throw "index out of bounds";
}
void DynamicArray::set(int index,int value){
    rangeCheck(index);
    storage[index]=value;
    
}
int DynamicArray::get(int index){
    rangeCheck(index);
    return storage[index];
}
void DynamicArray::insertAt(int index,int value){
    if(index<0||index>size)
        throw "index out of bounds!";
    ensureCapacity(size+1);
    int moveCount = size-index;
    if(moveCount!=0){
        memmove(storage+index+1, storage+index, sizeof(int )*moveCount);
    }
    storage[index]=value;
    size++;
}
void DynamicArray::removeAt(int index){
    rangeCheck(index);
    int moveCount=size-index-1;
    if(moveCount>0){
        memmove(storage+index, storage+(index+1), sizeof(int)*moveCount );
        
    }
    size--;
    pack();
}
void DynamicArray::print(){
    for(int i=0;i<this->size;i++){
        cout<<storage[i]<<" ";
    }
}












