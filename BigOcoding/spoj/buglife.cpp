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
#define vvi vector<vector<i> >
#define vi vector<i>
#define  FOR(iter,a,b) for(ll iter =a;iter<b;++iter)
#define INF 1e9;
void dfs(vvi graph,vi gender, vector<bool> check){
  stack<int> wait;
  wait.p(1);
  gender[1]=0;
  check[1]=true;
  ll temp;
  while(!wait.empty()){
    temp=wait.top();
    wait.pop();
    FOR(i,0,graph[temp].size()){
      int neighbor=graph[temp][i];
      // cout<<temp<<" "<<neighbor<<endl;
      // FOR(i,1,gender.size()){
      //   cout<<gender[i]<<" ";
      // }
      // cout<<endl;
      // FOR(i,1,check.size()){
      //   cout<<check[i]<<" ";
      // }
      // cout<<endl;
      if(gender[temp]==gender[neighbor] && gender[neighbor]!=-1)
      {
        cout<<"Suspicious bugs found!\n";
        return;
      }
      if(check[neighbor]==false){
        wait.push(neighbor);
        if(gender[temp]==0){
          gender[neighbor]=1;
        }
        else gender[neighbor]=0;
        check[neighbor]=true;
      }
    }

    if(wait.empty()){
      FOR(i,1,check.size()){
        if(check[i]==false){
          gender[i]=0;
          check[i]=true;
          wait.push(i);
          break;
        }
      }
    }
  }
  cout<<"No suspicious bugs found!\n";
}
int main(){
  i test;
  cin>>test;
  FOR(t,0,test){
    int N;
    ll interaction;
    cin>>N>>interaction;
    vvi graph(N+1);
    int a,b;
    FOR(i,0,interaction){
      cin>>a>>b;
      graph[a].pb(b);
      graph[b].pb(a);
    }
    vector<bool> check(N+1,false);
    vi gender(N+1,-1);
    cout<<"Scenario #"<<t+1<<":\n";
    dfs(graph,gender,check);
  }
  return 0;
}
