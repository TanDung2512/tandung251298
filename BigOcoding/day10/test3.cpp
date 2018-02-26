#include<iostream>
#include<queue>
using namespace std;
int main (){
  long long k,m ,n;
  cin>>k>>m>>n;
  long long sum=0;
  for(long long i=1;i<=n;i++){
    sum+=k*i;
  }
  int a=sum-m;
  if(a<=0){
    cout<<0<<endl;
    return 0;
  }
  cout<<a<<endl;
  return 0;
}
