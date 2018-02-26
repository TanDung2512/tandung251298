#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>array1(n+1);
  array1[0]=0;
  for(int i=1;i<n+1;i++){
    cin>>array1[i];
  }
  if(array1[n]!=90){
    array1.push_back(90);
  }
  int sum=0;
  int minus;
  for(int i=1;i<array1.size();i++){
    if(array1[i]-array1[i-1]<=15){
      sum+=array1[i]-array1[i-1];
    }
    else {
      cout<<sum+15<<endl;
      return 0;
    }
  }
  cout<<sum<<endl;
  return 0;
}
