#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  long long n;
  cin>>n;
  vector< long long > array(n);
  for(long long  i=0;i<n;i++){
    cin>>array[i];
  }
  sort(array.begin(),array.end());
  cout<<array[n/2]<<endl;
  return 0;
}
