#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
#include<iomanip>
#define ll long long
#define INF 1e9

using namespace std;
vector < vector < pair < ll,int > > > graph;
vector < int > path;
vector < int > dist;
vector < bool > visited;
struct point{
  int x;int y;
};
ll length(struct point x,struct point y){
  struct point vector1;
  vector1.x = x.x-y.x;
  vector1.y=x.y-y.y;
  return vector1.x*vector1.x+vector1.y*vector1.y;
}
void prim(){
  priority_queue<pair <ll,ll> , vector < pair <ll,ll> > , greater < pair < ll ,ll > > >pq;
  dist[0]=0;
  pq.push(make_pair(0,0));
  int top;
  while(!pq.empty()){
    top=pq.top().second;
    pq.pop();
    visited[top]=true;
    for(int i=0;i<graph[top].size();i++){
      int v=graph[top][i].first;
      int w=graph[top][i].second;
      if(!visited[v] && w<dist[v]){
        dist[v]=w;
        path[v]=top;
        pq.push(make_pair(w,v));
      }
    }
  }
}
double price (){
  double sum=0;

  for(ll i=0;i<graph.size();i++){
    //cout<<"# "<<dist[i]<<endl;
    if(path[i]==-1){
      continue;
    }
    sum+=sqrt(dist[i]);
  }
  return sum;
}
int main(){
  int n;
  while(cin>>n){
    vector < struct point > build;
    graph=vector < vector < pair < ll,int > > > (n);
    path=vector <int > (n,-1);
    dist=vector <int > (n,INF);
    visited=vector <bool > (n,false);
    struct point temp;
    for(int i=0;i< n;i ++ ){
      cin>>temp.x>>temp.y;
      build.push_back(temp);
    }
    int m;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j){
          continue;
        }
        ll lengthdis=length(build[i],build[j]);
        graph[i].push_back(make_pair(j,lengthdis));
      }
    }
    cin>>m;
    int a,b;
    for(int i=0;i<m;i++){
      cin>>a>>b;
      for(int j=0;j<graph[a-1].size();j++){
        if(graph[a-1][j].first==b-1){
          graph[a-1][j].second=0;
        }
      }
      for(int j=0;j<graph[b-1].size();j++){
        if(graph[b-1][j].first==a-1){
          graph[b-1][j].second=0;
        }
      }
    }
    prim();
    cout<<fixed<<setprecision(2)<<price()<<endl;

  }

  return 0;
}
