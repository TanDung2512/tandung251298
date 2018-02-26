#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
using namespace std;
typedef int i;
#define pb push_back
#define p push
#define f first
#define s second
#define mp make_pair
#define c cout<<"check\n";
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
#define pq priority_queue<pii,vector<pii>,greater<pii> >
#define vvpii vector<vector<pii> >
#define vvi vector<vector<ll> >
#define vi vector<ll>
#define  FOR(iter,a,b) for(ll iter =a;iter<b;++iter)
#define INF 1e9;
void dijktra(vvpii graph,vi&path, vi&distance,int source){
  pq wait;
  wait.p(pii(0,source));
  distance[source]=0;
  pii temp,neighbor;
  while(!wait.empty()){
    temp=wait.top();
    wait.pop();
    FOR(i,0,graph[temp.s].size()){
      neighbor=graph[temp.s][i];
      if(temp.f+neighbor.s<distance[neighbor.f]){
        path[neighbor.f]=temp.s;
        distance[neighbor.f]=temp.f+neighbor.s;
        wait.p(pii(distance[neighbor.f],neighbor.f));
      }
    }
  }
}
int main(){
  ll Testcase;
  scanf("%lld",&Testcase);
  FOR(t,0,Testcase){
    ll N,M;
    scanf("%lld%lld",&N,&M);
    vvpii graph(N+1);
    ll a,b,w;
    FOR(i,0,M){
      scanf("%lld%lld%lld",&a,&b,&w);
      graph[a].pb(pii(b,w));
      graph[b].pb(pii(a,w));
    }
    vi path(N+1,-1);
    vi distance(N+1,1e9);
    ll starting_point;
    scanf("%lld",&starting_point);
    dijktra(graph,path,distance,starting_point);
    FOR(i,1,N+1){
      if(starting_point!=i){
        if(path[i]!=-1){
        cout<<distance[i]<<"\n";
      }
      else{
        cout<<-1<<"\n";
      }
       }
    }
  }
}
