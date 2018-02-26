#include<iostream>
#include<vector>
#include<iomanip>
#define INF -1e9
using namespace std;
struct triad{
  int u;
  int v;
  double weight;
};
int n,m;
void BellManFor(int source,vector< struct triad > graph,vector< double >&dis){
  dis[source]=1;
  int u,v;
  double w;
  for(int i=1;i<n;i++){
    for(int j=0;j<graph.size();j++){
      u=graph[j].u;
      v=graph[j].v;
      w=graph[j].weight;
      dis[v]=max(dis[v],w*dis[u]);
      dis[u]=max(dis[u],w*dis[v]);
    }
  }
  return;
}
int main(){
  while(1){
    cin>>n;
    if(n==0){
      return 0;
    }
    cin>>m;
    vector< struct triad > graph;
    struct triad temp;
    for(int i=0;i<m;i++){
      scanf("%d%d%lf",&temp.u,&temp.v,&temp.weight);
      temp.weight=(double)temp.weight/100;
      graph.push_back(temp);
    }
    vector< double > dis (n+5,INF);
    BellManFor(1,graph,dis);
    cout<<fixed<<setprecision(6)<<dis[n]*100.0<<" percent"<<endl;
  //  cout<<fixed<<setprecision(6)<<backtracking(graph,path,dis,n,1)*100<<" percent"<<endl;
  }
  return 0;
}
