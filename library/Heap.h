#include<iostream>
#include<vector>
#include<time.h>
#include<math.h>
using namespace std;
template < class Htemplate >
class Heaptree{
public:
  vector < Htemplate >heapAr;
  bool min;
public:
  Heaptree(bool min){
    heapAr=vector < Htemplate > ();
    this->min=min;
  }
  Heaptree(vector<Htemplate> array,bool min){
    this->min=min;
    heapAr=new vector < Htemplate > (array.size());
    for(int i=0;i<array.size();i++){
      heapAr[i]=array[i];
    }
    if(min==true){
      for(int i=array.size()/2-1;i>=0;--i){
        heapifyMin(i);
      }
    }
    else {
      for(int i=array.size()/2-1;i>=0;--i){
        heapifyMax(i);
      }
    }
  }
  void insert(Htemplate data){
    if(this->min==true){
      insertMin(data);
    }
    else insertMax(data);
  }
  void insertMin(Htemplate data){
    heapAr.push_back(data);
    int i;
    i=heapAr.size()-1;
    while ( i>=0 && ( heapAr[(i-1)/2] > heapAr[i] ) )
     {
      swap(heapAr[ (i-1)/2 ], heapAr[i]);
      i=(i-1)/2;
    }
  }
  void insertMax(Htemplate data){
    heapAr.push_back(data);
    int i;
    i=heapAr.size()-1;
    while ( i>=0 && ( heapAr[(i-1)/2] < heapAr[i] ) )
     {
      swap(heapAr[ (i-1)/2 ], heapAr[i]);
      i=(i-1)/2;
    }
  }
  Htemplate top(){
    if(heapAr.size()>0){
      return heapAr[0];
    }
    cout<<"no value "<<endl;
    return -1e9;
  }
  void pop(){
    if(this->min==true){
      popMin();
    }
    else popMax();
  }
  void popMin(){
    swap(heapAr[0],heapAr[heapAr.size()-1]);
    heapAr.pop_back();
    heapifyMin(0);
  }
  void popMax(){
    swap(heapAr[0],heapAr[heapAr.size()-1]);
    heapAr.pop_back();
    heapifyMax(0);
  }
  void heapifyMin(int a){
    long long left;
    long long right;
    long long min=a;
    long long i=a;
    long long size=heapAr.size();
    while(1){
      left=i*2+1;
      right=i*2+2;
      if(left<size && heapAr[min]>heapAr[left]){
        min=left;
      }
      if(right<size && heapAr[min]>heapAr[right]){
        min=right;
      }
      if(min==i){
        break;
      }
      else{
        swap(heapAr[min],heapAr[i]);
        i=min;
      }
    }
  }
  void heapifyMax(int a){
    long long left;
    long long right;
    long long max=a;
    long long i=a;
    long long size=heapAr.size();
    while(1){
      left=i*2+1;
      right=i*2+2;
      if(left<size && heapAr[min]<heapAr[left]){
        max=left;
      }
      if(right<size && heapAr[min]<heapAr[right]){
        max=right;
      }
      if(max==i){
        break;
      }
      else{
        swap(heapAr[max],heapAr[i]);
        i=max;
      }
    }
  }
  void display(){
    for(int i=0;i<heapAr.size();i++){
      cout<<heapAr[i]<<" ";
    }
    cout<<endl;
  }
bool checkIterator(){

    for(int i=0;i<heapAr.size()/2-1;i++){
      if(heapAr[i]>heapAr[i*2+1] || heapAr[i]>heapAr[i*2+2]){
      //  cout<<heapAr[i]<<" "<<heapAr[i*2+1]<<" "<<heapAr[i*2+2]<<endl;
        return false;
      }
    }
    return true;
  }
bool checkRecursion(int i){
    if(i>heapAr.size()/2-1){
      return true;
    }
    if(heapAr[i]<=heapAr[2*i+1] || heapAr[i]<=heapAr[2*i+2]){
       return checkRecursion(i+1);
    }
    return false;
  }
int heightofHeapRecusive(int i,int size){
  int s=1;
  for(int a=0;a<i;a++){
    s*=2;
  }
  int node=s-1;
  if(node>size-1){
    return 0;
  }
  return heightofHeapRecusive(i+1,size)+1;
}
int heightofHeapUsingEquation(int size){
  if(size==0){
    return 0;
  }
  return log2(size)+1;
}
};
