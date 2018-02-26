#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef int i;
#define pb push_back
#define p push
#define f first
#define s second
#define mp make_pair
#define c cout<<"check\n";
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<i> vi;
#define pq priority_queue<pii,vector<pii>,greater<pii> >
#define vvpii vector<vector<pii> >
#define  FOR(iter,a,b) for(ll iter =a;iter<b;++iter)
#define INF 1e9

int  disktra(vvpii graph, vi path, vi distance, int source,int Exit_cell,int Time){
  pq wait;
  pii temp;
  temp.f=0;
  temp.s=source;
  distance[source]=0;
  if(Exit_cell ==source){
    return 1;
  }
  wait.p(temp);
  pii neighbor;
  while(!wait.empty()){
    temp=wait.top();
    wait.pop();
    FOR(i,0,graph[temp.s].size()){
      neighbor=graph[temp.s][i];
      if(temp.f+ neighbor.s < distance[neighbor.f]){
        distance[neighbor.f]=temp.f+neighbor.s;
        wait.p(pii(distance[neighbor.f],neighbor.f));
        path[neighbor.f]=temp.s;

      }
    }

  }

  if(distance[Exit_cell]<=Time){
    return 1;
  }
  else return 0;
}
int main(){
  i N;
  cin>>N;
  i exit_cell,Time,M;
  cin>>exit_cell>>Time>>M;
  N++;
  vector<vector<pii> > graph(N);

  pii temp;
  int a,b,T;
  FOR(i,0,M){
    cin>>a>>b>>T;
    temp.f=b;
    temp.s=T;
    graph[a].pb(temp);
  }
  // FOR(i,0,N){
  //   cout<<i<<" : ";
  //   FOR(j,0,graph[i].size()){
  //     cout<<graph[i][j].f<<" "<<graph[i][j].s<<"    ";
  //   }
  //   cout<<endl;
  // }
  i sum=0;
  FOR(i,1,N){
  //  cout<<i<<" "<<exit_cell<<endl;
  vi path(N,-1);
  vi distance (N,INF);
    sum+=disktra(graph,path,distance,i,exit_cell,Time);
  //  cout<<sum<<endl;

  }
  cout<<sum<<endl;

  return 0;
}
