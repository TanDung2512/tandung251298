#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
#include<iomanip>
#define double double
#define INF 1e18

using namespace std;
vector < vector < pair < int,double > > > graph;
vector < int > path;
vector < double > dist;
vector < bool > visited;
struct point{
  double x;double y;
};
double length(struct point x,struct point y){
  struct point vector1;
  vector1.x = x.x-y.x;
  vector1.y=x.y-y.y;
  return vector1.x*vector1.x+vector1.y*vector1.y;
}
void prim(){
  priority_queue<pair <double,int> , vector < pair <double,int> > , greater < pair < double,int > > >pq;
  dist[0]=0;
  pq.push(make_pair(0,0));
  int top;
  while(!pq.empty()){
    top=pq.top().second;
    pq.pop();
    visited[top]=true;
    for(int i=0;i<graph[top].size();i++){
      int v=graph[top][i].first;
      double w=graph[top][i].second;
      if(!visited[v] && w<dist[v]){
        dist[v]=w;
        path[v]=top;
        pq.push(make_pair(w,v));
      }
    }
  }
}
double price (){
  double sum=0;
  for(int i=0;i<graph.size();i++){
    //cout<<"# "<<dist[i]<<endl;
    if(path[i]==-1){
      continue;
    }
    sum+=sqrt(dist[i]);
  }
  return sum;
}
int main(){
  int n;
  int testcase ;
  cin>>testcase;
  while(testcase--){
    cin>>n;
    vector < struct point > build;
    graph=vector < vector < pair < int,double > > > (n);
    path=vector < int > (n,-1);
    dist=vector <double > (n,INF);
    visited=vector <bool > (n,false);
    struct point temp;
    for(int i=0;i<n;i ++ ){
      cin>>temp.x>>temp.y;
      build.push_back(temp);
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j){
          continue;
        }
        double lengthdis=length(build[i],build[j]);
        graph[i].push_back(make_pair(j,lengthdis));
      }
    }
    prim();
    cout<<fixed<<setprecision(2)<<price()<<endl;
  }

  return 0;
}
