#include<iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
struct point{
  int i,j;
};
struct area{
  int i,j;
  int area;
};
void input(vector<vector<char > >&map,int m){
  char temp;
  for(int i=0;i!=map.size();++i){
    for(int j=0;j!=m;++j){
      cin>>temp;
      map[i].push_back(temp);
    }
  }
}
void output(vector<vector<char > >&map){
  for(int i=0;i!=map.size();++i){
    for(int j=0;j!=map[i].size();++j){
      cout<<map[i][j];
    }
    cout<<endl;
  }
}
bool checkLine(struct point temp,int n,int m){
  if(temp.i==n-1 || temp.i ==0 || temp.j == m-1 || temp.j==0){
    return true;
  }
  else return false;
}
bool getTop(struct point&temp,struct point&temp2,int n,int m){
  if(temp.i-1>=0){
    temp2.i=temp.i-1;
    temp2.j=temp.j;
    return true;
  }else return false;
}
bool getBottom(struct point&temp,struct point&temp2,int n,int m){
  if(temp.i+1<n){
    temp2.i=temp.i+1;
    temp2.j=temp.j;
    return true;
  }else return false;
}
bool getLeft(struct point&temp,struct point&temp2,int n,int m){
  if(temp.j-1>=0){
    temp2.j=temp.j-1;
    temp2.i=temp.i;
    return true;
  }else return false;
}
bool getRight(struct point&temp,struct point&temp2,int n,int m){
  if(temp.j+1<m){
    temp2.j=temp.j+1;
    temp2.i=temp.i;
    return true;
  }else return false;
}
void BFS(vector<vector<char > >&map,int i,int j,vector<struct area>&area1,int n,int m){
  struct point temp,temp1;
  int area=1;
  queue<struct point>wait;
  temp.i=i;
  temp.j=j;
  bool checkOcean=false;
  wait.push(temp);
  while(!wait.empty()){
    temp=wait.front();
    wait.pop();
    if(checkLine(temp,n,m)){
      checkOcean=true;
    }
    if(getTop(temp,temp1,n,m)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='x';
        area++;
      }
    }
    if(getLeft(temp,temp1,n,m)){
      if(map[temp1.i][temp1.j]=='.'){

        wait.push(temp1);
        map[temp1.i][temp1.j]='x';

        area++;
      }
    }
    if(getRight(temp,temp1,n,m)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='x';
        area++;
      }
    }
    if(getBottom(temp,temp1,n,m)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='x';
        area++;
      }
    }
  }
  if(checkOcean==false){
  struct area temp123;
  temp123.area=area;
  temp123.i=i;
  temp123.j=j;
  area1.push_back(temp123);
}
}
bool myfunction (struct area i,struct area j) { return (i.area<j.area); }
void map123(vector<vector<char > >map,vector<struct area>&area1){
  struct point temp;
  for(int i=0;i!=map.size();++i){
    for(int j=0;j!=map[i].size();++j){
      if(map[i][j]=='.'){
        map[i][j]='x';
        BFS(map,i,j,area1,map.size(),map[0].size());
      }
    }
  }
}
void BFSmakex(vector<vector<char > >&map,int i ,int j,int n,int m){
  struct point temp,temp1;
  queue<struct point>wait;
  temp.i=i;
  temp.j=j;
  wait.push(temp);
  map[i][j]='*';
  while(!wait.empty()){
    temp=wait.front();
    wait.pop();
    if(getTop(temp,temp1,n,m)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='*';
      }
    }
    if(getLeft(temp,temp1,n,m)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='*';
      }
    }
    if(getRight(temp,temp1,n,m)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='*';
      }
    }
    if(getBottom(temp,temp1,n,m)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='*';
      }
    }
  }
}

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<vector<char > >map(n);
  vector<vector<char > >check(n);
  vector<struct area> area1;
  input(map,m);
  map123(map,area1);
  // cout<<endl;
  // output(map);
  // for(int i=0;i<area1.size();++i){
  //   cout<<"i= "<<area1[i].i<<".... j= "<<area1[i].j<<"... area= "<<area1[i].area<<endl;
  // };
  int sum=0;
  std::sort(area1.begin(),area1.end(),myfunction);
  for(int i=k;i<area1.size();i++){
    sum+=area1[area1.size()-i-1].area;
    BFSmakex(map,area1[area1.size()-i-1].i,area1[area1.size()-1-i].j,n,m);
  }
  cout<<sum<<endl;
  output(map);
  return 0;
}
