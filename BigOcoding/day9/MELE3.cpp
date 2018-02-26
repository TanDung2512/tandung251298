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
void disktra(vvpii graph,vi path, vi distance){
  pq wait;
  pii temp;
  temp.f=0;
  temp.s=1;
  wait.p(temp);
  pii neighbor;
  while(!wait.empty()){
    temp=wait.top();
    wait.pop();
    if(temp.s==graph.size()){
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
  cout<<distance[graph.size()]<<"\n";
}
int main(){
  string input;
  while(1){
    cin>>input;
    if(input!="liftovi.in"){
      break;
    }
    int E,N;
    cin>>N>>E;
    vvpii graph(N+1);
    pii temp;
    int a,b,w;
    FOR(i,0,E){
      cin>>a>>b;
      w=((b-a)*5);
      graph[a].pb(pii(b,w));
    }
    vi path(N+1,-1);
    vi distance(N+1,INF);
    disktra(graph,path,distance);
    cin>>input;
  }
  return 0;
}
