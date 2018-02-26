#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
#define  FOR(iter,a,b) for(ll iter =a;iter<b;++iter)
#define INF 1e9
void disktra(vvpii graph,vi path, vi distance,int start,int end,int a){

  pq wait;
  pii temp;
  wait.p(pii(0,start));
  distance[start]=0;
  pii neighbor;
  while(!wait.empty()){
    temp=wait.top();
    wait.pop();
    if(temp.s==end){
      break;
    }
    FOR(i,0,graph[temp.s].size()){
      neighbor=graph[temp.s][i];
      if(neighbor.s+temp.f<distance[neighbor.f]){
        distance[neighbor.f]=neighbor.s+temp.f;
        path[neighbor.f]=temp.s;
        wait.p(pii(distance[neighbor.f],neighbor.f));
      }
    }
  }
  if(distance[end]==INF){
    cout<<"Case #"<<a<<": unreachable\n";
  }else cout<<"Case #"<<a<<": "<<distance[end]<<"\n";
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int testcase;
  cin>>testcase;
  FOR(ac,0,testcase){
    ll n,m,s,t,ab;
    cin>>n>>m>>s>>t;
    vvpii graph(n);
    ll a,b,w;
    pii temp;
    FOR(i,0,m){
      cin>>a>>b>>w;
      temp.f=b;
      temp.s=w;
      graph[a].pb(temp);
      temp.f=a;
      graph[b].pb(temp);
    }
    vi path(n,-1);
    vi distance(n,INF);
    disktra(graph,path,distance,s,t,ac+1);
  }
  return 0;
}
