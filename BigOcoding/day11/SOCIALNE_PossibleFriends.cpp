#include<iostream>
#include<vector>
#include<string>
#define MAX 55
#define INF 1e9
using namespace std;
vector< vector< int > > graph;
vector<vector < int > > dis;
void FloyWarshall(vector< vector< int > >&graph,vector<vector < int > >&dis,int size){
  int i,j,k;
  int n=size;
  for( k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(dis[i][j]>dis[i][k]+dis[k][j]){
          dis[i][j]=dis[i][k]+dis[k][j];
        }
      }
    }
  }
}
int main(){
  int n;
  scanf("%d",&n);
  string stringtemp;
  for(int test=0;test<n;test++){
    cin>>stringtemp;
    graph=vector< vector< int> >(stringtemp.size(),vector<int> (stringtemp.size()));
    dis=vector< vector< int> >(stringtemp.size(),vector<int> (stringtemp.size()));
    graph[0][0]=0;
    dis[0][0]=0;
    for(int i=1;i<stringtemp.size();i++){

      if(stringtemp[i]=='Y'){
        graph[0][i]=1;
        dis[0][i]=1;
      }else {graph[0][i]=INF;
        dis[0][i]=INF;
      }
    }
    for(int i=1;i<stringtemp.size();i++){
      cin>>stringtemp;
      for(int j=0;j<stringtemp.size();j++){
        if(i==j){
          graph[i][j]=0;
          dis[i][j]=0;
          continue;
        }
        if(stringtemp[j]=='Y'){
          graph[i][j]=1;
          dis[i][j]=1;
        }else {graph[i][j]=INF;
          dis[i][j]=INF;
        }
      }
    }
    FloyWarshall(graph,dis,stringtemp.size());
    int sum,maxi=0,maxsum=0;
    for(int i=0;i<stringtemp.size();i++){
      sum=0;
      for(int j=0;j<stringtemp.size();j++){
        if(dis[i][j]==2){
          sum++;
        }
      }
      if(sum>maxsum){
        maxi=i;
        maxsum=sum;
      }
    }
    cout<<maxi<<" "<<maxsum<<endl;
//     for(int i=0;i<stringtemp.size();i++){
//       for(int j=0;j<stringtemp.size();j++){
//         cout<<graph[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   for(int i=0;i<stringtemp.size();i++){
//     for(int j=0;j<stringtemp.size();j++){
//       cout<<dis[i][j]<<" ";
//   }
//   cout<<endl;
// }
// for(int i=0;i<stringtemp.size();i++){
//   for(int j=0;j<stringtemp.size();j++){
//     cout<<path[i][j]<<" ";
// }
// cout<<endl;
// }
}
  return 0;
}
