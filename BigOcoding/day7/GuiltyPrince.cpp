#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct point{
  int i,j;
};
void inputGraph(vector<vector<char > >&map,int W,struct point &startingPoint){
  char temp;
  for(int i=0;i<map.size();++i){
    for(int j=0;j<W;++j){
      cin>>temp;
      if(temp=='@'){
        startingPoint.i=i;
        startingPoint.j=j;
      }
      map[i].push_back(temp);
    }
  }
}

bool getTop(struct point&temp,struct point&temp2){
  if(temp.i-1>=0){
    temp2.i=temp.i-1;
    temp2.j=temp.j;
    return true;
  }else return false;
}
bool getBottom(struct point&temp,struct point&temp2,int n){
  if(temp.i+1<n){
    temp2.i=temp.i+1;
    temp2.j=temp.j;
    return true;
  }else return false;
}
bool getLeft(struct point&temp,struct point&temp2){
  if(temp.j-1>=0){
    temp2.j=temp.j-1;
    temp2.i=temp.i;
    return true;
  }else return false;
}
bool getRight(struct point&temp,struct point&temp2,int m){
  if(temp.j+1<m){
    temp2.j=temp.j+1;
    temp2.i=temp.i;
    return true;
  }else return false;
}
int DFS(vector<vector<char > >&map,struct point startingPoint,int H,int W){
  int sum=1;
  stack<struct point>wait;
  struct point temp,temp1;
  wait.push(startingPoint);
  while(!wait.empty()){
    temp=wait.top();
    wait.pop();
    if(getTop(temp,temp1)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='#';
        sum++;
      }
    }
    if(getRight(temp,temp1,W)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='#';
        sum++;
      }
    }
    if(getLeft(temp,temp1)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='#';
        sum++;
      }
    }
    if(getBottom(temp,temp1,H)){
      if(map[temp1.i][temp1.j]=='.'){
        wait.push(temp1);
        map[temp1.i][temp1.j]='#';
        sum++;
      }
    }
  }
  return sum;
}
int main(){
  int T;
  cin>>T;
  for(int t=0;t<T;++t){
    int H,W;
    struct point startingPoint;
    cin>>W>>H;

    vector<vector<char > >map(H);
    inputGraph(map,W,startingPoint);
    cout<<"Case "<<t+1<<": "<<DFS(map,startingPoint,H,W)<<endl;;
  }
  return 0;
}
