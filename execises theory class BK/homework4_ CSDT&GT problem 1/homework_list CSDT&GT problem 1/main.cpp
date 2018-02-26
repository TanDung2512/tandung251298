//
//  main.cpp
//  homework_list CSDT&GT problem 1
//
//  Created by nguyen tan dung on 10/1/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
template<class arrayType>
class arrayDynamic{
public:
    arrayType *storage;
    int capacity;
    int size;
    arrayDynamic();
    ~arrayDynamic();
    
    
    void setCapacity(int capacity);
    void ensureCapacity(int Newcapacity);
    void pack();
    void trim();
    void rangeCheck(int index);
    void set(int index,arrayType value);
    arrayType get(int index);
    void removeAt(int index);
    void insertAt(int index,arrayType value);
    void print();
    void searchvalue(arrayType value,int &index);
    void removeval(int val);
    arrayDynamic*merge2array(arrayDynamic<arrayType>*array1,arrayDynamic<arrayType>*array2);
    void frequentofmem();

};

int main(int argc, const char * argv[]) {
    arrayDynamic<int> *array=new arrayDynamic<int>();
    arrayDynamic<int> *array1=new arrayDynamic<int>();
    arrayDynamic<int> *newarray=new arrayDynamic<int>();
    int sizearray;
    cout<<"input your size "<<endl;
    cin>>sizearray;
    int value;

    for(int i=0;i<sizearray;i++){
        cout<<"please input value at position "<<i<<" :";
        cin>>value;
        array->insertAt(i, value);
    }
    int choose;
    int width =15;
    int position;
    do{
        cout<<setw(width+20)<<"Menu Dynamic Array "<<endl;
        cout<<setw(width)<<" ";
        cout<<left<<"1. set Capacity"<<endl;
        cout<<setw(width)<<" ";
        cout<<"2. pack"<<endl;
        cout<<setw(width)<<" ";
        cout<<"3. trim"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"4. set value int dynamic array at particular position"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"5. get value from dynamic array"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"6. remove value at particular position"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"7. insert value at particular position"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"8. print dynamic array to console"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"9. search value in dynamic array"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"10. remove value in dynamic array"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"11. merge 2 array "<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"12. frequent of each element in dynamic array"<<endl;
        cout<<setw(width)<<" ";
        
        cout<<"13. exit"<<endl;
        cout<<endl;
        
        cout<<"       your choose : ";
        cin>>choose;
        switch (choose)
        {
            case 1:
                cout<<"set your capacity: ";
                cin>>value;
                array->setCapacity(value);
                break;
            case 2:

                array->pack();
                break;
            case 3:
                array->trim();
                break;
            case 4:
                cout<<"input your value: ";
                cin>>value;
                cout<<"input position: ";
                cin>>position;
                array->set(position, value);
                break;
            case 5:
                cout<<"input position: ";
                cin>>position;
                value =array->get(position);
                cout<<"value of position "<<position<<": "<<value<<endl;;
                break;
            case 6:
                cout<<"please input position: ";
                cin>>position;
                array->removeAt(position);
                break;
            case 7:
                cout<<"input your value: ";
                cin>>value;
                cout<<"please input position: ";
                cin>>position;
                array->insertAt(position, value);
                break;
            case 8:
                array->print();
                break;
            case 9:
                cout<<"input your value that you would like to search: ";
                cin>>value;
                array->searchvalue(value, position);
                cout<<"the position that have that value: "<<position<<endl;
                break;
            case 10:
                cout<<"input your value that you would like to remove: ";
                cin>>value;
                array->removeval(value);
                break;
            case 11:
                int size;
                int value1;
                cout<<"please input size of new array: "<<endl;
                cin>>size;
                
                for(int i=0;i<size;i++){
                    cout<<"value at index "<<i<<" : ";
                    cin>>value1;
                    array1->insertAt(i, value1);
                }
                newarray=array->merge2array(array, array1);
                newarray->print();
                cout<<"2 arraies has been marged !!"<<endl;
                delete array1;
                delete newarray;
                array1=NULL;
                newarray=NULL;
                break;
            case 12:
                array->frequentofmem();
                break;
            case 13:
                delete array;
                break;
        }
        system("clear");
    }
    while(choose!=13);
    cout<<"             Thank you for using our programming !! "<<endl;
    return 0;
}

template<class arrayType>
arrayDynamic<arrayType>::arrayDynamic(){
    this->capacity=10;
    this->size=0;
    storage=new arrayType[this->capacity];
}
template<class arrayType>
arrayDynamic<arrayType>::~arrayDynamic(){
    delete []storage;
}
template<class arrayType>
void arrayDynamic<arrayType>::setCapacity(int capacity){
    arrayType *newStorage=new arrayType[capacity];
    for(int i=0;i<this->capacity;i++){
        newStorage[i]=storage[i];
    }
    this->capacity=capacity;
    delete[]storage;
    storage=newStorage;
}
template<class arrayType>
void arrayDynamic<arrayType>::ensureCapacity(int mincapacity){
    if(mincapacity>capacity){
        int newCapacity=(capacity*3)/2 + 1;
        if(newCapacity<mincapacity){
            newCapacity=mincapacity;
        }
        setCapacity(newCapacity);
    }
}
template<class arrayType>
void arrayDynamic<arrayType>::pack(){
    if(size<=capacity/2){
        int newCapacity=(size*3)/2+1;
        setCapacity(newCapacity);
    }
}
template<class arrayType>
void arrayDynamic<arrayType>::trim(){
    int newCapacity=size;
    setCapacity(newCapacity);
}
template<class arrayType>
void arrayDynamic<arrayType>::rangeCheck(int index){
    if(index<0 || index >=size){
        throw "index out of bounds !";
    }
}
template<class arrayType>
void arrayDynamic<arrayType>::set(int index, arrayType value){
    rangeCheck(index);
    storage[index]=value;
}
template<class arrayType>
arrayType arrayDynamic<arrayType>::get(int index){
    rangeCheck(index);
    return storage[index];
}
template<class arrayType>
void arrayDynamic<arrayType>::insertAt(int index,arrayType value){
    if(index<0||index>size){
        throw "index out of bounds!";
    }
    ensureCapacity(size+1);
    int moveCount=size-index+1;
    int i=0;
    while(i<moveCount){
        storage[size-i]=storage[size-i-1];
        i++;
    }
    storage[index]=value;
    size++;
}
template<class arrayType>
void arrayDynamic<arrayType>::removeAt(int index){
    rangeCheck(index);
    for(int i=index;i<size-1;i++){
        storage[i]=storage[i+1];
    }
    size--;
    pack();
}
template<class arrayType>
void arrayDynamic<arrayType>::print(){
    for(int i=0;i<this->size;i++){
        cout<<storage[i]<<" ";
    }
    cout<<endl;
}
template<class arrayType>
void arrayDynamic<arrayType>::searchvalue(arrayType value, int&index){
    rangeCheck(index);
    for(int i=index;i<size;i++){
        if(storage[i]==value){
            index=i;
            return ;
        }
    }
}
template<class arrayType>
void arrayDynamic<arrayType>::removeval(int vol){
    for(int i=0;i<size;i++){
        if(storage[i]==vol){
            removeAt(i);
        }
    }
}
template<class arrayType>
arrayDynamic<arrayType> *arrayDynamic<arrayType>::merge2array(arrayDynamic<arrayType>*array1,arrayDynamic<arrayType>*array2)
{
    arrayDynamic<arrayType>*newStorage=new arrayDynamic<arrayType>();
    newStorage->setCapacity(array1->capacity+array2->capacity);
    int i=0;
    int j=0;
    int k=0;
    do{
        while(array1->storage[i]<=array2->storage[j] & i<array1->size){
            newStorage->insertAt(k,array1->storage[i]);
            k++,i++;
        }
        while(array1->storage[i]>array2->storage[j] & j<array2->size){
            newStorage->insertAt(k,array2->storage[j]);
            k++,j++;
        }
    }while(i<array1->size && j<array2->size);
    
    if(i<array1->size){
        cout<<1<<endl;
        for(int a=i;a<array1->size;a++){
            newStorage->insertAt(k,array1->storage[a]);
            k++;
        }
    }
    else if(k<array2->size){
        cout<<2<<endl;

        for(int a=j;a<array2->size;a++){
            newStorage->insertAt(k,array2->storage[a]);
            k++;
        }
    }
    return newStorage;
}
template<class arrayType>
void arrayDynamic<arrayType>::frequentofmem()
{
    arrayType max=storage[0];
    for(int i=1;i<size;i++){
        if(storage[i]>max){
            max=storage[i];
        }
    }
    arrayType *array=new arrayType[max+1];
    for(int i=0;i<max+1;i++){
        array[i]=0;
    }
    for(int i=0;i<size;i++){
        array[storage[i]]++;
    }
    for(int i=0;i<max+1;i++){
        if(array[i]!=0){
            cout<<i<<" "<<array[i]<<" ";
        }
    }
    cout<<endl;
}
