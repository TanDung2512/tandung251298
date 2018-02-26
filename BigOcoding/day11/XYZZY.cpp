#include<iostream>
#include<vector>
#include<queue>
#define  INF 1e9
#define MAX 110
using namespace std;
struct triad{
  int u;
  int v;
  int weight;
};
vector< struct triad > graph;
vector< bool > check;
vector <int > dist;
int n,m;
bool canReach(int s,int t){
  queue<int > wait;
  wait.push(s);
  check=vector<bool > (n+5,false);
  check[s]=true;
  int temp;
  while(!wait.empty()){
    temp=wait.front();
    wait.pop();
    for(int i=0;i<graph.size()-1;i++){
      if(temp==graph[i].u && graph[i].v==false){
        wait.push(graph[i].v);
        check[graph[i].v]=true;
        if(graph[i].v==t){
          return true;
        }
      }
    }
  }
  return false;
}
int main(){
  struct triad temp;
  int temp1;
  while(cin>>n,n!=-1){
    graph.clear();
    for(int i=1;i<=n;i++){
      scanf("%d%d",&temp.weight,&temp1);
      temp.u=i;
      if(temp1!=0){
        for(int j=0;j<temp1;j++){
          scanf("%d",&temp.v);
          graph.push_back(temp);
        }
      }
      else {
        temp.weight=-INF;
        temp.v=0;
        graph.push_back(temp);
      }
    }
    dist=vector<int> (n+5 , -INF);
    dist[1]=100;
    for(int i=1;i<n;i++){
      for(int j=0;j<graph.size()-1;j++){
        if(dist[graph[j].u]<=0)
          continue;
        dist[graph[j].v]=max(dist[graph[j].v],dist[graph[j].u]+graph[j].weight);
      }
    }
    bool cycle=false;
    for(int j=0;j<graph.size()-1;j++){
      if(dist[graph[j].u]<=0)
        continue;
      if(dist[graph[j].v]<dist[graph[j].u]+graph[j].weight &&canReach(graph[j].u,n)){
        cycle = true;
        break;
      }
    }
    // for(int i=0;i<n;i++){
    //   cout<<dist[i]<<endl;
    // }
    cout<<((cycle || dist[n]>0)?("winnable"):("hopeless"))<<endl;
  }
  return 0;
}
