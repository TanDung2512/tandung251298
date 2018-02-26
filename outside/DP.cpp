#include<iostream>
#include<vector>
using namespace std;
vector<double>dpfi(100001,-1);
vector<double>dprod(100001,-1);

// double fibonanci(double n){
//   if(dp[n]!=-1){
//     return dp[n];
//   }
//   if (n==0){
//     dp[0]=1;
//     return 1;
//   }
//   if(n==1){
//     dp[1]=1;
//     return 1;
//   }
//   dp[n]=fibonanci(n-1)+fibonanci(n-2);
//   return dp[n];
// }
double cuttingrod(int n){
  for(int i=1;i<=n;i++){
    for(int j=1;j<i;j++){
      if(dprod[i]<dprod[j]+dprod[i-j]){
        dprod[i]=dprod[j]+dprod[i-j];
      }
    }
  }
  return dprod[n];
}
int main(){
  int size;
  cin>>size;
  int temp;
  for(int i=1;i<=size;i++){
    cin>>temp;
    dprod[i]=temp;
  }
  dprod[0]=0;
  cout<<cuttingrod(size)<<endl;
  for(int i=0;i<size;i++){
    cout<<dprod[i]<<endl;
  }
  return 0;
}
