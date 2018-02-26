#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
struct data {
  int u,v;
};
int n;
vector < vector < pair < int ,int > > > graph;
vector < int > dist;
vector <int > path;
vector < bool > visited ;
priority_queue< pair<int ,int > , vector <pair <int ,int > > , greater <pair<int ,int > > > pq;
priority_queue< pair<int ,pair<int , int > >, vector <pair <int ,pair<int ,int > > > , greater <pair<int ,pair<int,int> > > > pq1;

int prim(){
  path=vector < int > (n,-1);
  dist=vector < int > (n,INF);
  visited=vector <bool > (n,false);
  pq=priority_queue< pair<int ,int > , vector <pair <int ,int > > , greater <pair<int ,int > > >();
  dist[0]=0;
//  int count=graph.size();
//  cout<<"$"<<count<<endl;
  vector < struct data > edge;
  pq.push(make_pair(0,0));
  int top;
  while(!pq.empty()){
    // if(count==0){
    //   break;
    // }
    top=pq.top().second;
    visited[top]=true;
    pq.pop();
  //  count--;
    for(int i=0;i<graph[top].size();i++){
      int v=graph[top][i].first;
      int w=graph[top][i].second;
      if(!visited[v] && w<dist[v]){
        dist[v]=w;
        path[v]=top;
        pq.push(make_pair(w,v));
      }
    }
  }
  int sum=0;
  for(int i=0;i<graph.size();i++){
    if(path[i]==-1){
      continue;
    }
    sum+=dist[i];
  }
  return sum;
}
int main(){
  int testcase;
  cin>>testcase;
  while(testcase--){
    int m;
    cin >>n>>m;
    graph=vector < vector < pair < int ,int > > > (n);
    vector < struct data > edge;
    pair<int ,int > temp;
    struct data temp2;
    int temp1;
    for(int i=0;i<m;i++){
      cin>>temp1>>temp.first>>temp.second;
      temp.first--;

      graph[temp1-1].push_back(temp);
      graph[temp.first].push_back(make_pair(temp1-1,temp.second));
    }
    int result =prim();

    pair <int,pair<int,int > >  temp3;
//    pq1=priority_queue< pair<int ,pair<int , int > >, vector <pair <int ,pair<int ,int > > > , greater <pair<int ,pair<int,int> > > >();
  int length1;
  int min,min1;min=INF,min1=INF;
  vector<int >path1=vector < int > (n,-1);
  for(int i=0;i<path1.size();i++){
    path1[i]=path[i];
  }
    cout<<result<<" ";
    for(int i=0;i<path1.size();i++){
      if(path1[i]==-1){
        continue;
      }
      for(int j=0;j<graph[i].size();j++){
        if(graph[i][j].first==path1[i]){
          length1=graph[i][j].second;
          graph[i][j].second=INF;
          break;
        }
      }
      for(int j=0;j<graph[path1[i]].size();j++){
        if(graph[path1[i]][j].first==i){
          graph[path1[i]][j].second=INF;
          break;

        }
      }
      min1=prim();
      if(min1<min && min1>=result){
        if(min1==result)
          for(int k=0;k<path.size();k++){
            if(path[k]!=path1[k]){
              min=min1;
              break;
            }
          }
        else min=min1;
      }
      for(int j=0;j<graph[i].size();j++){
          if(graph[i][j].first==path1[i]){
            graph[i][j].second=length1;
            break;
          }
        }

        for(int j=0;j<graph[path1[i]].size();j++){
          if(graph[path1[i]][j].first==i){
            graph[path1[i]][j].second=length1;
            break;
          }
        }
    }
    cout<<min<<endl;
}
  return 0;
}
