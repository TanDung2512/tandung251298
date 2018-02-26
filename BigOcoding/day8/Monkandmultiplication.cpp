#include<iostream>
#include<vector>
using namespace std;
void swap(long int &a,long int &b){
  long int temp=a;
  a=b;
  b=temp;
}
void maxHeapify(vector<long int>&array,long int i,long int size){
   long int max=i;
   long int left=i*2+1;
   long int right=i*2+2;
   if(left<size && array[left]>array[max]){
     max=left;
   }
   if(right<size && array[right]>array[max]){
     max=right;
   }
   if(max!=i){
     swap(array[i],array[max]);
     maxHeapify(array,max,size);
   }
}

void outputarray(vector<long int>&array){
  for(long int i=0;i<array.size()/2-1;i++){
    cout<<i<<" : "<<array[i]<<" "<<array[i*2+1]<<" "<<array[i*2+2]<<endl;
  }
  for(long int i=0;i<array.size();i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}
void takeout(vector<long int> & array,long int&size){
  swap(array[0],array[size-1]);
  size--;
  maxHeapify(array,0,size);
}
long int buildHeap(vector<long int>array,long int size,long int&left,long int &right,long int&check1){
  long int product=1;
  for(long int i=size/2-1;i>=0;--i){
    maxHeapify(array,i,size);
  }
  product*=array[0];
  takeout(array,size);

  left=array[0];
  product*=array[0];
  takeout(array,size);
  right=array[0];
  product*=array[0];
  check1=min(left,right);
  return product;
}
void problem(vector<long int>array){
  vector<long int > array1;
  cout<<-1<<endl<<-1<<endl;
  long int check=0,left,right,check1;
  long int product;
  for(long int i=3;i<=array.size();i++){
    if(array[i-1]>=check){
    product=buildHeap(array,i,left,right,check1);
    cout<<product<<endl;
    check=check1;
    }
    else cout<<product<<endl;
    }

}
 int main(){
   long int n;
  cin>>n;
   long int temp;
  vector< long int> array;
  for(long int i=0;i<n;i++){
    cin>>temp;
    array.push_back(temp);
  }
  problem(array);
  return 0;
}
