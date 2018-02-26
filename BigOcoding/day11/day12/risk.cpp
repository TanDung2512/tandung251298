#include<iostream>
#include<vector>
#define INF 3;
using namespace std;
vector< vector< int > >dis;
void FloyWarsher(vector < vector< int > >graph,vector < vector <int > >&dis){
  int k,i,j;
  for(int i=1;i<21;i++){
    for(int j=1;j<21;j++){
      dis[i][j]=graph[i][j];
    }
  }
  for(int k=1;k<21;k++){
    for(int i=1;i<21;i++){
      for(int j=1;j<21;j++){
        if(dis[i][j]>dis[i][k]+dis[k][j]){
          dis[i][j]=dis[i][k]+dis[k][j];
        }
      }
    }
  }
}
int main(){
  int temp;
  int test=1;
   while(cin>>temp){
  vector< vector < int > > graph(21,vector<int > (21));
  dis=vector< vector < int > > (21 , vector< int > (21));
  for(int i=1;i<21;i++){
    for(int j=1;j<21;j++){
      graph[i][j]=(i==j ? 0 : 1e9);
    }
  }
  int count=1;
  int temp1;
  for(int t=1;t<=temp;t++){
    scanf("%d",&temp1);
    graph[1][temp1]=1;
    graph[temp1][1]=1;
  }
  for(int i=2;i<20;i++){
    scanf("%d",&temp);
    for(int t=1;t<=temp;t++){
      scanf("%d",&temp1);
      graph[i][temp1]=1;
      graph[temp1][i]=1;
    }
  }

  int num;
  scanf("%d",&num);
  int start,end;
  FloyWarsher(graph,dis);
  // for(int i=1;i<21;i++){
  //      for(int j=1;j<21;j++){
  //        cout<<dis[i][j]<<" ";
  //      }
  //      cout<<endl;
  //    }
  printf("Test Set #%d\n",test);
  for(int i=0;i<num;i++){
    scanf("%d%d",&start,&end);
    if(start<10){
      printf(" %d",start);
    }else printf("%d",start);
    printf(" to ");
    if(end<10){
      printf(" %d: ",end);
    }
    else printf("%d: ",end);
    printf("%d\n",dis[start][end]);
  }
  printf("\n");
  test++;
}
  return 0;
}
