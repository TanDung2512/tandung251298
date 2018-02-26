#include<iostream>
#include<vector>
using namespace std;
vector<int>parent;
int findset(int u){
  while(u!=parent[u]){
    u=parent[u];
  }
  return u;
}
void unionset(int u ,int v){
  int up=findset(u);
  int vp=findset(v);
  parent[vp]=up;
}
int main(){
  int m,n;
  int testcase=1;
  cin>>m>>n;
  while(m!=0 && n!=0){
    cout<<"Case "<<testcase<<": ";
    testcase++;
    parent=vector<int>(m+1000);
    for(int i=0;i<m;i++){
      parent[i]=i;
    }
    int a,b;
    for(int i=0;i<n;i++){
      cin>>a>>b;
      unionset(a,b);
    }
    int sum=0;
    vector<int>parentcheck(m+1000,false);
    for(int i=0;i<m;i++){
      int a=findset(i);
      if(parentcheck[a]==false){
        sum++;
        parentcheck[a]=true;
      }
    }
    parentcheck.clear();
    parent.clear();
    cout<<sum<<endl;
    cin>>m>>n;
  }
  return 0;
}
