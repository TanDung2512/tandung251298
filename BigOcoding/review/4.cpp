#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int>array1(n);
  vector<int>count(100000+5);
  for(int i=0;i<n;i++){
    cin>>array1[i];
  }
  for(int i=0;i<100005;i++){
    count[i]=0;
  }
  int l,r;
  l=0;
  r=0;
  int sum=1;
  count[array1[0]]++;
  for(int i=0;i<n;i++){
    if(sum<m){
      r++;
      if(count[array1[r]]==0){
        sum++;
      }
    }
    else {
      count[array1[l]]--;
      l++;
    }
  }
}
