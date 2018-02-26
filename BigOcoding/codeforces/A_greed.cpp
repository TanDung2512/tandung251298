#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int main(){
  ll n;
  ll sum=0;
  ll temp;
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>temp;
    sum+=temp;
  }
  ll max,min;
  cin>>min>>max;
  if(max<min){
    swap(max,min);
  }
  for(ll i=2;i<n;i++){
    cin>>temp;
    if(temp>max){
      min=max;
      max=temp;
    }
    else if(temp<min){
      continue;
    }
    else {
      min=temp;
    }
  }
  if(sum<=max+min){
    cout<<"YES\n";
  }
  else {
    cout<<"NO\n";
  }
  return 0;
}
