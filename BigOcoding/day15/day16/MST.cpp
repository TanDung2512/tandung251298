#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
#define ll long long
using namespace std;
vector < vector < pair < ll ,ll > > > graph;
vector < ll > dist;
vector < ll > path;
vector < bool > visited ;
void prim(ll source){
  priority_queue< pair< ll ,ll > , vector < pair < ll ,ll > > , greater < pair<ll,ll> > > pq;
  dist[source]=0;
  pq.push(make_pair (0,source));
  ll top;
  while(!pq.empty()){
    top=pq.top().second;
    pq.pop();
    visited[top]=true;
    for(ll i=0;i<graph[top].size();i++){
      ll v=graph[top][i].first;
      ll w=graph[top][i].second;
      if(!visited[v] && w<dist[v]){
        dist[v]=w;
        path[v]=top;

        pq.push(make_pair (w,v));
      }
    }
  }
}
ll price (){
  ll sum=0;

  for(ll i=0;i<graph.size();i++){
    //cout<<"# "<<dist[i]<<endl;
    if(dist[i]==INF){
      continue;
    }

    sum+=dist[i];
  }
  return sum;
}
int main(){
  ll n,m;
  cin>>n>>m;
  graph=vector < vector < pair < ll ,ll > > >(n);
  dist=vector < ll >(n,INF);
  path=vector < ll >( n , -1);
  visited=vector < bool > (n,false);
  ll temp;
  pair<ll ,ll > temp1;
  for (ll i=0;i<m;i++){
    cin>>temp>>temp1.first>>temp1.second;
    temp1.first=temp1.first-1;
    graph[temp-1].push_back(temp1);
    graph[temp1.first].push_back(make_pair(temp-1,temp1.second));
  }
  prim(1);
  cout<<price()<<endl;
  return 0;
}
