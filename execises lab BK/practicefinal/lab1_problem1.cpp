#include<iostream>
using namespace std;
char*upper(char *arr,int n){
  for(int i=0;i<n;i++){
    if(arr[i]>=97 && arr[i]<=122){
      arr[i]=(char)(arr[i]-32);
    }
  }
  return arr;
}
int main(){
  char arr[6]= {'a','B','c','d','3','\0'};
  cout<<arr<<endl;
  upper(arr,5);
  cout<<arr;
  return 0;
}
