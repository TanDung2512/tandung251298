#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int main(){
  ll n;
  scanf("%lld",&n);
  vector<ll > array (n);
  for(ll i=0;i<n;i++){
    scanf("%lld",&array[i]);
  }
  ll size=n-1;
  ll left =size-array[n-1];

  ll sum =1;
  bool check =false;
  for(ll i=n-2;i>=0;i--){
    if( i<left && check==false){
      sum++;
      check =true;
    }
    else if(array[i]<left){
      left =i-array[i];
      check=false;
    }
  }
  cout<<sum<<endl;
  return 0;
}
