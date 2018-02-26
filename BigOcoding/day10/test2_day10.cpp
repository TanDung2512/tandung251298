#include<iostream>
#include<vector>
#include <string>
using namespace std;
int main(){
  string input;
  vector<int > array(300,0);
  int n;
  cin>>n>>input;
  for(int i=0;i<n;++i){
    if(isupper(input[i])!=0){
      input[i]=tolower(input[i]);
    }
    array[(int)input[i]]++;
  }
  for(int i=97;i<123;i++){
    if(array[i]==0){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
