#include <iostream>
#include<vector>
#include<queue>
#define MAX 100000
using namespace std;
void BFS(long int*array,long int numKey,long int Key,long int SamKey,int *check);
int main(int argc, const char * argv[]){
  long int SamKey,LockKey,numKey;
  long int*array=new long int[1001];
  int *check=new int [100000];
  long int i;
  cin>>SamKey>>LockKey>>numKey;
  for(i=numKey-1;i>=0;--i)
  {
    cin>>array[i];
  }
  for(i=MAX-1;i>=0;--i){
    check[i]=-1;
  }
  BFS(array,numKey,LockKey,SamKey,check);
  return 0;
}
void BFS(long int *array,long int numKey,long int Key,long int SamKey,int *check){
  queue<long int> wait;
  int start=1,end=numKey;
  int sum=1;
  wait.push(SamKey);
  long int temp;
  long int product;
  while(!wait.empty()){
    temp=wait.front();
    wait.pop();
    ++start;
    if(start==end){
      ++sum;
      start=1;
      end=wait.size();
    }
    for(int i=numKey-1;i>=0;--i){
      product=(temp*array[i])%100000;
      if(product==Key){
        cout<<sum<<endl;
        return ;
      }
      if(check[product]==-1){
        wait.push(product);
      }
      ++check[product];
    }
  }
   cout<<-1<<endl;
}
