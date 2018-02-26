#include<iostream>
#include<vector>
using namespace std;
int main(){
  string input;
  cin>>input;
  int sum=0;
  int count=0;
  int num=1;
  if(input.size()<3){
    cout<<0<<endl;
    return 0;
  }
  for(int i=0;i<input.size()-2;i++){
    if(input[i]=='Q'){
      for(int j=i+1;j<input.size()-1;j++){
        if(input[j]=='A'){
          for(int z=j+1;z<input.size();z++){
            if(input[z]=='Q'){
              sum++;
            }
          }
        }
      }
    }
  }
    cout<<sum<<endl;
  return 0;
}
