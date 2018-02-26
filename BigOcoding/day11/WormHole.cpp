#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;
struct triad{
  int source;
  int target;
  int weight;
};
bool BellManFord(int source , vector< struct triad> &graph, vector<int> &dist,vector<int> &path){
  dist[source]=0;
  int u,v,w;
  for(int i=1;i<dist.size()-1;i++){
    for(int j=0;j<graph.size();j++){
      u=graph[j].source;
      v=graph[j].target;
      w=graph[j].weight;
      if(dist[u]!=INF && dist[u]+w<dist[v]){
        dist[v]=dist[u]+w;
        path[v]=u;
      }
    }
  }
  for(int j=0;j<graph.size();j++){
    u=graph[j].source;
    v=graph[j].target;
    w=graph[j].weight;
    if(dist[u]!=INF && dist[u]+w<dist[v]){
      return false;
    }
  }
  return true;
}


int main(){
  int testcase;
  scanf("%d",&testcase);
  for(int test=0;test<testcase;test++){
    int m,n;
    scanf("%d%d",&n,&m);
    vector< struct triad > graph(m);
    int a,b,c;
    struct triad temp;
    for(int i=0;i<m;i++){
      scanf("%d%d%d",&a,&b,&c);
      temp.source=a;
      temp.target=b;
      temp.weight=c;
      graph[i]=temp;
    }
    vector < int > path(n,-1);
    vector< int > dist(n,INF);
    bool check=BellManFord(0,graph,dist,path);
    if(check==true){
      cout<<"not possible"<<endl;
    }else cout<<"possible"<<endl;
  }
  return 0;
}
