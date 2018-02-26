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
void disktra(vvpii graph,vi path,vi distance, int source , int des){
  pq wait;
  pii temp;
  wait.p(pii(0,source));
  pii neighbor;
  distance[source]=0;
  while(!wait.empty()){
    temp=wait.top();
    wait.pop();
    if(temp.s==des){
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
  cout<<distance[des]<<endl;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll numTest;
  ll n;
  cin>>numTest;
  pii temp;
  FOR(t,0,numTest){
    cin>>n;
    n++;
    map<string,int> NameCity;
    vvpii graph(n);
    i nNeighbor;
    string name;
    FOR(i,1,n){
      cin>>name;
      NameCity[name]=i;
      cin>>nNeighbor;
      FOR(j,1,nNeighbor+1){
        cin>>temp.f>>temp.s;
        graph[i].pb(temp);
      }
    }
    i nCity;
    vi path(n,-1);
    vi distance(n,INF);
    cin>>nCity;
    string start_city;
    string end_city;
    i start_num;
    i end_num;
    FOR(i,0,nCity){
      cin>>start_city>>end_city;
      start_num=NameCity.find(start_city)->second;
      end_num=NameCity.find(end_city)->second;
      disktra(graph,path,distance,start_num,end_num);
    }
  }
  return 0;
}
