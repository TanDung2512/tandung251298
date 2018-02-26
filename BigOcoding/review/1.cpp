#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>array(n+2);
  for(int i=0;i<n;i++){
    cin>>array[i];
  }
  if(n==1){
    if(array[0]==1){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  else {
    int num=0;
    for(int i=0;i<n;i++){
      if(num>1){
        cout<<"NO";
        return 0;
      }
      if(array[i]==0 ){
        num++;
      }
    }
    if(num==1){
      cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
  }
}
