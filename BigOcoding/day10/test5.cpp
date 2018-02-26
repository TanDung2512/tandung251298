#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct point{
  int x;int y;
};
void bfs(vector< vector< int > >graph, struct point start1,struct point end1,int m,int n ){
  graph[end1.x][end1.y]=-2;
  int start=0,end=1;
  int sum=0;
  queue <struct point > wait;
  struct point temp,temp1;
  graph[start1.x][start1.y]=-1;
  wait.push(start1);
  while(!wait.empty()){
    temp=wait.front();
    wait.pop();
    ++start;
    for(int i=0;i<4;i++){
      int x=temp.x+dx[i];
      int y=temp.y+dy[i];
      if(x>=0 && x<m && y>=0 && y<n){
        if(graph[x][y]==-2){
          cout<<sum+1<<endl;
          return ;
        }
        if(graph[x][y]==0 ){
          temp1.x=x;
          temp1.y=y;
          graph[x][y]=-1;
          wait.push(temp1);
        }
      }
    }
    if(start==end){
        ++sum;
        start=0;
        end=wait.size();
    }
  }

}
int main(){
  int m,n;
  while(1){
    cin>>m>>n;
    if(m==0 && n==0){
      return 0;
    }
  vector< vector< int > > graph(m);

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      graph[i].push_back(0);
    }
  }
  int numlinebome;
  cin>>numlinebome;
  int a,b,c,d;
  for(int i=0;i<numlinebome;i++){
    cin>>a>>b>>c;
    graph[a][c]=-1;
    if(b!=1){
      for(int s=1;s<b;s++){
        cin>>d;
        graph[a][d]=-1;
      }
      continue;
    }
  }
  struct point start,end;
  cin>>start.x>>start.y;
  cin>>end.x>>end.y;
  bfs(graph,start,end,m,n);
}
  return 0;
}
