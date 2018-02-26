#include<iostream>
#include<vector>
#include<iomanip>
#define a cout<<"\ncheck\n";
using namespace std;
#define INF 1e14
int n;
struct data{
  bool Y;
  bool M;
  long long energy;
};
void floywarshar(vector < vector< struct data > > graph,int start,int end){
  for(int k=0;k<26;k++){
    for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
        if((graph[i][k].M==false && graph[i][k].Y==false) || (graph[k][j].M==false && graph[k][j].Y==false)){
          continue;
        }
        if((graph[i][j].M==false && graph[i][j].Y==false) && ((graph[i][k].Y==true && graph[k][j].Y==true) || (graph[i][k].M==true && graph[k][j].M==true ) ) ){
          if(graph[i][j].energy>graph[i][k].energy+graph[k][j].energy){
            graph[i][j].energy=graph[i][k].energy+graph[k][j].energy ;
            graph[i][j].Y=graph[i][k].Y && graph[k][j].Y;
            graph[i][j].M=graph[i][k].M && graph[k][j].M;
         }
         continue;
        }
        if((graph[i][j].Y==true && graph[i][k].Y==true && graph[k][j].Y==true) || (graph[i][j].M==true && graph[i][k].M==true && graph[k][j].M==true)){
           if(graph[i][j].energy>graph[i][k].energy+graph[k][j].energy){
              graph[i][j].energy=graph[i][k].energy+graph[k][j].energy;
            }
        }
      }
    }
  }

  long long min =1e14;
  for(int k=0;k<26;k++){
    if(graph[start][k].energy!=INF && graph[end][k].energy!=INF && graph[start][k].Y==true && graph[end][k].M==true){
      if(min>graph[start][k].energy + graph[end][k].energy){
        min=graph[start][k].energy + graph[end][k].energy;
      }
    }
  }
  if(min==INF){
    cout<<"You will never meet.";
    cout<<endl;
    return ;
  }
  cout<<min;
  for(int k=0;k<26;k++){
    if(min==graph[start][k].energy + graph[end][k].energy && graph[start][k].Y==true && graph[end][k].M==true){
      cout<<" "<<char(k+65);
    }
  }
  cout<<endl;
}
int main(){
  while(cin>>n){
    if(n==0){
      return 0;
    }
    vector < vector < struct data > > graph ( 26,vector < struct data > (26));
    struct data temp;
    temp.Y=false;
    temp.M=false;
    for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
        if(i==j){
          temp.energy=0;
          graph[i][j]=temp;
        }
        else {
          temp.energy=INF;
          graph[i][j]=temp;
        }
      }
    }
    char A,B,C,D;
    long long energy;
    for(int i=0;i<n;i++){
      cin >> A >> B >> C >> D >> energy;
      if(C==D){
        energy=0;
      }
      if(B=='B'){
        graph[C-65][D-65].energy=energy;
        graph[D-65][C-65].energy=energy;
        if(A=='Y'){
          graph[C-65][D-65].Y=true;
          graph[D-65][C-65].Y=true;
        }
        else {
          graph[C-65][D-65].M=true;
          graph[D-65][C-65].M=true;
        }
      }
      else{
        graph[C-65][D-65].energy=energy;
        if(A=='Y'){
          graph[C-65][D-65].Y=true;
        }
        else{
          graph[C-65][D-65].M=true;
        }
      }
    }
    char start,end;
    cin>>start>>end;
    graph[start-65][start-65].Y=true;
    graph[end-65][end-65].M=true;
    floywarshar(graph,start-65,end-65);

  }

  return 0;
}
