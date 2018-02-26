#include<iostream>
#include<queue>
using namespace std;
int main(){
  int N;
  while(1){
    cin>>N;
    if(N==0){
      return 0 ;
    }
    long int temp;
    priority_queue<int,vector<int>,greater<int> > wait;
    for(int i=0;i<N;i++){
      cin>>temp;
      wait.push(temp);
    }
    int sum;
    long sum1=0;
    while(wait.size()!=1){
      sum=wait.top();
      wait.pop();
      sum+=wait.top();
      wait.pop();
      wait.push(sum);
      sum1+=sum;
    }
    cout<<sum1<<endl;
  }
  return 0;
}
