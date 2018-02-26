#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  int h;
  cin>>n>>h;
  vector<int>array1(n+2);
  for(int i=0;i<n;i++){
    cin>>array1[i];
  }
  int sum=0;
  for(int i=0;i<n;i++){
    if(array1[i]>h){
      sum+=2;
    }
    else sum+=1;
  }
  cout<<sum<<endl;
  return 0;
}
