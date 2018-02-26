#include<iostream>
#include<vector>
#include<queue>
#define ll long long
#define i64d I64d
#define d d
#define INF 1e18
#define a cout<<1<<endl;
using namespace std;
vector < vector < pair < ll,ll > > > graph;
vector < ll > path;
vector < ll > dist;
vector < bool > visited;
int count;
void prim (int source){
  priority_queue<pair <ll,ll> , vector < pair <ll,ll> > , greater < pair < ll ,ll > > >pq;
  dist[source]=0;
  pq.push(make_pair(0,source));
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
ll price (){
  ll sum=0;
  for(int i=0;i<graph.size();i++){
    if(path[i]==-1){
      continue;
    }
    sum+=dist[i];
  }
  return sum;
}
int main(){
  int testcase,p,n,m;
  scanf("%d",&testcase);
  while(testcase--){
      scanf("%d%d%d",&p,&n,&m);
      graph=vector< vector < pair < ll , ll > > > (n);
      dist=vector < ll > (n,INF);
      path=vector < ll > (n, -1);
      visited = vector < bool > (n,false);
      pair < ll , ll > temp;
      ll temp1;
      ll w;

      for(int i=0;i<m;i++){
        cin>>temp1>>temp.first>>temp.second;
        temp.second*=p;
        temp.first--;
        graph[temp1-1].push_back(temp);
        //cout<<"#"<<temp.first<<endl;
        graph[temp.first].push_back(make_pair(temp1-1,temp.second));
      }
      prim (0);
      cout<<price()<<endl;

  }

  return 0;
}
