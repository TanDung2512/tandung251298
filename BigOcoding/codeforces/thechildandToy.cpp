#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct data{
  int num;
  int order;
};
struct value{
  int data;
  bool check;
};
bool compare(const data &a,const data &b){
  return a.num<b.num;
}
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  struct data temp;
  vector<struct data > energy;
  for(int i=0;i<n;i++){
    scanf("%d",&temp.num);
    temp.order=i+1;
    energy.push_back(temp);
  }
  sort(energy.begin(),energy.end(),compare);
  vector < vector < struct value > > graph(n+1);
  int a,b;
  struct value temp1;

  for(int i=0;i<m;i++){
    scanf("%d%d",&a,&b);
    temp1.check=false;
    temp1.data=b;
    graph[a].push_back(temp1);
    temp1.data=a;
    graph[b].push_back(temp1);
  }
  int sum=0;
  bool checktemp=true;
  for(int t=0;t<n;t++){
      struct data temp3 = energy[t];
      for(int i=0;i<graph[temp3.order].size();i++){
        if(graph[temp3.order][i].check==false){
          graph[temp3.order][i].check=true;
          graph[graph[temp3.order][i].data][temp3.order].check=true;
          checktemp=false;
        }
      }
      if(checktemp==false){
        sum+=temp3.num;
      }
      checktemp=true;

  }
  cout<<sum<<endl;
  return 0;
}
