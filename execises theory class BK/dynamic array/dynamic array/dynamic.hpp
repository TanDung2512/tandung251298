//
//  dynamic.hpp
//  dynamic array
//
//  Created by nguyen tan dung on 9/13/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#ifndef dynamic_hpp
#define dynamic_hpp

#include <stdio.h>
class DynamicArray
{
private:
    int size;
    int capacity;
    int *storage;
public:
    DynamicArray();
    DynamicArray(int capacity);
    ~DynamicArray();
    void setCapacity(int NewCapacity);
    void ensureCapacity(int minCapacity);
    void pack();
    void trim();
    void rangeCheck(int index);
    void set(int index,int value);
    int get(int index);
    void removeAt(int index);
    void insertAt(int index);
    
};
#endif /* dynamic_hpp */
