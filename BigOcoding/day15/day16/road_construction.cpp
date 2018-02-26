#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define a cout<<"#"<<endl;
#define INF 1e9

using namespace std;
vector < vector < pair < int ,int > > > graph;
vector < int > path,dist;
vector < bool > visited;
void prim(){
  priority_queue< pair < int ,int > , vector < pair < int , int > > , greater < pair <int ,int > > > pq;
  dist[0]=0;
  int top;
  pq.push(make_pair(0,0));
  while(!pq.empty()){
    top=pq.top().second;
    pq.pop();
    visited[top]=true;

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
}
int price (int count){
  int sum=0;
  path[0]=0;
  for(int i=0;i<count;i++){
//    cout<<"#"<<dist[i]<<endl;
    if(path[i]==-1){
      return -1;
    }
    sum+=dist[i];
  }

  return sum;
}
int main(){
  int testcase;
  cin>>testcase;
  for(int test=1;test<=testcase;test++){
    int m;
    cin>>m;
    map<string,int>city;
    string city1,city2;
    int cost;
    int count=0;
    graph=vector <vector < pair < int ,int > > >(100000);
    dist=vector < int > (100000,INF);
    path=vector < int > (100000,-1);
    visited=vector <bool > (100000,false);
    while(m--){
      cin>>city1>>city2>>cost;
      if(city.find(city1)==city.end()){
        city.insert(make_pair(city1,count));
        count++;
      }
      if(city.find(city2)==city.end()){
        city.insert(make_pair(city2,count));
        count++;
      }
      graph[city[city1]].push_back(make_pair(city[city2],cost));
      graph[city[city2]].push_back(make_pair(city[city1],cost));

    }
    prim();
    int sum=price(count);
    if(sum!=-1){
      cout<<"Case "<<test<<": "<<sum<<endl;;
      continue;
    }
    cout<<"Case "<<test<<": Impossible"<<endl;;

  }
  return 0;
}
