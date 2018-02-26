#include<iostream>
#include<vector>
#include<math.h>
#include<cmath>
#include<iomanip>
using namespace std;
#define MAX 110
#define INF 1e9
struct point {
  int x;
  int y;
};
int test;
double calculate(int x1,int x2,int y1,int y2){
  return ((double)sqrt((x1-y1)*(x1-y1)+(x2-y2)*(x2-y2)));
}
double makeround(double x1){
  double answer=abs(x1*10*10*10*10-floor(x1*10*10*10*10)-0.5);
  if(answer>0.01){
    return x1;
  }else return floor(x1);
}
int n;
void FloyWarsher(vector< vector < double  > > graph){
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(graph[i][j]>graph[i][k]+graph[k][j]){
          graph[i][j]=graph[i][k]+graph[k][j];
        }
      }
    }
  }
  double max=0.0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(graph[i][j]==INF){
        cout<<"Case #"<<test<<":\n";
        cout<<"Send Kurdy\n\n";

        return ;
      }
      if(graph[i][j]>max){
        max=graph[i][j];
      }
    }
  }
  cout<<"Case #"<<test<<":\n";
  cout<<fixed<<setprecision(4)<<makeround(max)<<"\n\n";

}
int main(){
  int testcase;
  cin>>testcase;
  for(test=1;test<=testcase;test++){
    vector< vector < double  > > graph ( MAX , vector < double > (MAX));
    scanf("%d",&n);
    vector<struct point > point;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        graph[i][j]=((i==j)?(0):(INF));
      }
    }
    struct point temp;
    for(int i=0;i<n;i++){
      cin>>temp.x>>temp.y;
      point.push_back(temp);
    }
    double egde;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(i==j){
          continue;
        }
        egde=calculate(point[i].x,point[i].y,point[j].x,point[j].y);
        if(egde>10.0){
         continue;
        }
        graph[i][j]=egde;
        graph[j][i]=egde;
      }
    }
    FloyWarsher(graph);

  }
    return 0;
}
