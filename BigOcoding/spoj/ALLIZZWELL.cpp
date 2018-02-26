#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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
struct point {
  int x;int y;
};
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
bool dfs(vector<string> graph,string all,vector<vector< bool > >&check,struct point start){
  stack<struct point> wait;
  wait.p(start);
  char temp;
  struct point tempp,temp1;
  int x,y;
  int cnt=1;
  while(!wait.empty()){
    tempp=wait.top();
    wait.pop();
    FOR(i,0,8){
      x=tempp.x+dx[i];
      y=tempp.y+dy[i];
      if(x>=0 && x<graph.size() && y>=0 && y<graph[0].size()){
        if(!check[x][y] && graph[x][y]==all[cnt]){
          check[x][y]=true;
          temp1.x=x;
          temp1.y=y;
          wait.p(temp1);
          cnt++;
          if(cnt==all.size()){
            return true;
          }
        }
      }
    }
  }
  return false;
}
void run(vector<string> graph,string all,vector<vector< bool > >check,int R,int C){
  FOR(i,0,R){
    FOR(j,0,C){
      if(graph[i][j]=='A'){
        struct point temp;
        temp.x=i;
        temp.y=j;
        bool checkbool=dfs(graph,all,check,temp);
        if(checkbool ==true){
          cout<<"YES"<<endl;
          return ;
        }
      }
    }
  }
  cout<<"NO"<<endl;
}
int main(){
  int t;
  cin>>t;
  string all="ALLIZZWELL";

  FOR(a,0,t){
    int R,C;
    cin>>R>>C;
    vector<string > graph(R);
    string input;
    FOR(i,0,R){
      cin>>input;
      graph[i]=input;
    }
    vector<vector< bool > >check(R);
    FOR(i,0,R){
      FOR(j,0,C){
        check[i].pb(false);
      }
    }
    run(graph,all,check,R,C);
    // FOR(i,0,R){
    //   cout<<graph[i]<<endl;
    // }
  }
  return 0;
}
