#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  vector<int> graph;
  int temp;
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    graph.push_back(temp);
  }
  int min=100000000;
  for(int i=1;i<n;i++){
    if(min>abs(graph[i]-graph[i-1])){
      min=abs(graph[i]-graph[i-1]);
    }
  }
  cout<<min<<endl;
  return 0;
}
