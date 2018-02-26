#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  string string1;
  vector<string> array1;
  while(cin>>string1){
    array1.push_back(string1);
  }
  for(int i=0;i<array1.size();i++){
    cout<<array1[i]<<endl;
  }
  return 0;
}
