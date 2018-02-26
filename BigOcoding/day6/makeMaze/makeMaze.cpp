#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct point{
  int i,j;
};
void getTop(struct point&temp,struct point&temp1){
  if(temp.i-1>=0){
    temp1.i=temp.i-1;
    temp1.j=temp.j;
  }
  else {
    temp1.i=-1;
  }
}
void getRight(struct point&temp,struct point&temp1,int n){
  if(temp.j+1<n){
    temp1.j=temp.j+1;
    temp1.i=temp.i;
  }else {
    temp1.i=-1;
  }
}
void getLeft(struct point&temp,struct point&temp1){
  if(temp.j-1>=0){
    temp1.j=temp.j-1;
    temp1.i=temp.i;
  }else {
    temp1.i=-1;
  }
}
void getBottom(struct point&temp,struct point&temp1,int m){
  if(temp.i+1<m){
    temp1.i=temp.i+1;
    temp1.j=temp.j;
  }else {
    temp1.i=-1;
  }
}
bool checkLine(struct point temp,vector<vector< char> >maze,int m ,int n){
  if(temp.i==0 || temp.i==m-1 || temp.j==n-1 || temp.j==0){
   return true;
  }
  return false;
}
void BFS(vector<vector< char> >&maze,int m,int n,struct point start){
  queue<struct point>wait;
  struct point temp,temp1;
  wait.push(start);
  bool check=false;
  // maze[start.i][start.j]='#';
  while(!wait.empty()){
    temp=wait.front();
    wait.pop();
    getTop(temp,temp1);
    if(temp1.i!=-1 && maze[temp1.i][temp1.j]!='#'){
      if(checkLine(temp1,maze,m,n)){
        cout<<"valid"<<endl;
        return;
      }
      wait.push(temp1);
      maze[temp1.i][temp1.j]='#';
      check=true;
    }
    getRight(temp,temp1,n);
    if(temp1.i!=-1 && maze[temp1.i][temp1.j]!='#'){
      if(checkLine(temp1,maze,m,n)){
      cout<<"valid"<<endl;
        return;
      }
      wait.push(temp1);
      maze[temp1.i][temp1.j]='#';
      check=true;
    }
    getLeft(temp,temp1);
    if(temp1.i!=-1 && maze[temp1.i][temp1.j]!='#'){
      if(checkLine(temp1,maze,m,n)){
      cout<<"valid"<<endl;
        return;
      }
      wait.push(temp1);
      maze[temp1.i][temp1.j]='#';
      check=true;
    }
    getBottom(temp,temp1,m);
    if(temp1.i!=-1 && maze[temp1.i][temp1.j]!='#'){
      if(checkLine(temp1,maze,m,n)){
      cout<<"valid"<<endl;
        return;
      }
      wait.push(temp1);
      maze[temp1.i][temp1.j]='#';
      check=true;
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cout<<maze[i][j]<<"  ";
      }
      cout<<endl;
    }
    if(check==false){
      cout<<"invalid"<<endl;
      return ;
    }
    check=false;

  }
  cout<<"invalid"<<endl;
}
int  main(){
  int testcase;
  cin>>testcase;
  for(int a=0;a<testcase;a++){
    int numpoint=0;
    int m,n;
    struct point start;
    cin>>m>>n;
    char input;
    vector<vector< char> >maze(m);
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cin>>input;
        maze[i].push_back(input);
        if(i==0 || i==m-1 || j==0 || j==n-1){
          if(maze[i][j]=='.'){
            numpoint++;
            start.j=j;
            start.i=i;
          }
        }
      }
    }
    if(numpoint!=2){
      cout<<"invalid"<<endl;
      continue;
    }
    BFS(maze,m,n,start);
  }
  return 0;
}
