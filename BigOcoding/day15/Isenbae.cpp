#include<iostream>
#include<queue>
#include<map>
using namespace std;
void bfs(int source,vector<vector<int > > & graph, vector < bool >&check , vector <int >&distance ){
  check[source]=true;
  queue<int > wait;
  wait.push(source);
  int temp;
  //cout<<source<<endl;
  distance[source]=0;
  int neighbor;
  while(!wait.empty()){
    temp=wait.front();
    wait.pop();
    for(int i=0;i<graph[temp].size();i++){
      neighbor=graph[temp][i];
      if(!check[neighbor]){
        check[neighbor]=true;
    //    cout<<"#"<<temp<<" "<<distance[temp]<<" "<<neighbor<<endl;

        distance[neighbor]=distance[temp]+1;
        wait.push(neighbor);
      }
    }
  }
}
int main(){
  map<string,int> map1;
  int n;
  scanf("%d",&n);
  string temp1,temp2,temp3;
  vector<vector < int > > graph(1000000);
  int p=0;

  for(int i=0;i<n;i++){
    cin>>temp1;
    cin>>temp2;
    cin>>temp3;
    if(map1.find(temp1)==map1.end()){
      map1[temp1]=p;
      p++;
    }
    if(map1.find(temp2)==map1.end()){
      map1[temp2]=p;
      p++;
    }
    if(map1.find(temp3)==map1.end()){
      map1[temp3]=p;
      p++;
    }
    graph[map1[temp3]].push_back(map1[temp2]);
    graph[map1[temp3]].push_back(map1[temp1]);
    graph[map1[temp2]].push_back(map1[temp1]);
    graph[map1[temp2]].push_back(map1[temp3]);
    graph[map1[temp1]].push_back(map1[temp3]);
    graph[map1[temp1]].push_back(map1[temp2]);
  }
//  cout<<map1["Isenbaev"]<<endl;
  vector<bool> check(100000,false);
  vector<int > distance(1000000,0);
  if(map1.find("Isenbaev")!=map1.end())
    bfs(map1["Isenbaev"],graph,check,distance);
  for(map<string,int>::iterator it=map1.begin();it!=map1.end();it++){
    cout<<(*it).first<<" ";
    if(!check[(*it).second]){
      cout<<"undefined"<<endl;
    }
    else {
      cout<<distance[(*it).second]<<endl;
    }
  }
  return 0;
}
