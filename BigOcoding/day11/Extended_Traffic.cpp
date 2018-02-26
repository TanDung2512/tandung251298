#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <functional>
#define INF 1e9
using namespace std;
int m,n;
struct triad{
  int source;
  int target;
  int weight;
};
void BellManFord(int source , vector< struct triad> &graph, vector<int> &dist,vector<int> &path){
  dist[source]=0;
  int u,v,w;
  for(int i=1;i<=n-1;i++){
    for(int j=0;j<m;j++){
      u=graph[j].source;
      v=graph[j].target;
      w=graph[j].weight;
      if(dist[u]!=INF && dist[u]+w<dist[v]){
        dist[v]=dist[u]+w;
        path[v]=u;
      }
    }
  }
  return ;
}

int main(){

  int testcase;
  cin>>testcase;
  for(int test=0;test<testcase;test++){
    cin>>n;
    vector< int > junction;
    junction.push_back(0);
    int temp3;
    for(int i=0;i<n;i++){
      scanf("%d",&temp3);
      junction.push_back(temp3);
    }
    cin>>m;
    vector<struct triad > graph;
    struct triad temp;
    for(int i=0;i<m;i++){
      scanf("%d%d",&temp.source,&temp.target);
      temp.weight=pow((junction[temp.target]-junction[temp.source]),3);
      graph.push_back(temp);
    }
    vector<int > path(n+1,-1);
    vector <int > dis (n+1,INF);
    BellManFord(1,graph,dis,path);

    int test1;
    int temp1;
    cin>>test1;
    for(int a=0;a<test1;a++){
      scanf("%d",&temp1);
        if(dis[temp1]>=3 && dis[temp1]!=INF){
          cout<<dis[temp1]<<endl;
        }
      else{
        cout<<'?'<<endl;
      }
    }
  }
  return 0;
}
