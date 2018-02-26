#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include<iostream>
#define MAX 10000
using namespace std;
template <class TPlateAr>
class DynamicArray{
private:
  TPlateAr*Storage;
  int size;
  int capacity;
public:
  DynamicArray(){
    Storage=new TPlateAr[MAX];
    capacity=MAX;
    size=0;
  }
  ~DynamicArray(){
    delete[]Storage;
    Storage=NULL;
    capacity=0;
    size=0;
  }
  void setCapacity(int NewCapacity);
  void ensureCapacity(int size);
  void pack();
  void trim();
  void rangeCheck(int index);
  void set(int index, int value);
  TPlateAr get(int index);
  void removeAt(int index);
  void insertAt(int index,int value);
  void print();
  int sizeAr(){
    return size;
  }
  int getCapacity(){
    return this->capacity;
  }
};
#endif
template<class TPlateAr>
void DynamicArray<TPlateAr>::setCapacity(int NewCapacity)
{
  TPlateAr*NewStorage=new TPlateAr[NewCapacity];
  for(int i=0;i<size;i++){
    NewStorage[i]=Storage[i];
  }
  capacity=NewCapacity;
  delete[]Storage;
  Storage=NewStorage;
}
template<class TPlateAr>
void DynamicArray<TPlateAr>::ensureCapacity(int minCapacity){
  if(minCapacity>capacity){
    int newCapacity=(capacity*3)/2+1;
    if(newCapacity<minCapacity){
      newCapacity=minCapacity;
    }
    setCapacity(newCapacity);
  }
}
template<class TPlateAr>
void DynamicArray<TPlateAr>::pack(){
  if(size<=capacity/2){
    int newCapacity=(size*3)/2+1;
    setCapacity(newCapacity);
  }
}
template<class TPlateAr>
void DynamicArray<TPlateAr>::trim(){
  int newCapacity=size;
  setCapacity(newCapacity);
}
template<class TPlateAr>
void DynamicArray<TPlateAr>::rangeCheck(int index){
  if(index<0 || index>=size){
    throw "index out of bounds!";
  }
}
template<class TPlateAr>
void DynamicArray<TPlateAr>::set(int index,int value){
  rangeCheck(index);
  Storage[index]=value;



}
template<class TPlateAr>
TPlateAr DynamicArray<TPlateAr>::get(int index)
{
  rangeCheck(index);
  return Storage[index];
}

template<class TPlateAr>
void DynamicArray<TPlateAr>::insertAt(int index,int value){
  if(index<0||index>size){
    throw "Index out of bounds!";
  }
  ensureCapacity(size+1);
  for(int i=size;i>index;i--){
    Storage[i]=Storage[i-1];
  }
  Storage[index]=value;
  size++;
}
template<class TPlateAr>
void DynamicArray<TPlateAr>::removeAt(int index){
  rangeCheck(index);
  for(int i=index;i<size-1;i++){
    Storage[i]=Storage[i+1];
  }
  size--;
  pack();

}
template<class TPlateAr>
void DynamicArray<TPlateAr>::print(){
  cout<<"Dynamic Array"<<" has "<<this->size<<" :"<<endl;
  for(int i=0;i<size;i++){
    cout<<Storage[i]<<" ";
  }
  cout<<endl;
}
