#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
void inputGraph(vector<list<int> >&array){
  int e;
  cin>>e;
  int a,b;
  for(int i=e-1;i>=0;--i){
    cin>>a>>b;
    array[a].push_back(b);
  }
}
void outputGraph(vector<list<int> >&array){
  for(int i=0;i<array.size();i++){
    cout<<"edge "<<i<<" :";
    for( std::list<int>::iterator j=array[i].begin();j!=array[i].end();++j){
      cout<<*j<< "  ";
    }
    cout<<endl;
  }
}
int BFS(vector<list<int> >&array){
  stack<int> wait;
  bool *check=new bool [array.size()];
  for(int i=array.size()-1;i>=0;--i){
    check[i]=false;
  }
  int sum=0;
  int temp;
  list<int>::iterator iter;
  for(int i=0;i!=array.size();++i){
    if(check[i]==false){
      wait.push(i);
      check[i]=true;
      while(!wait.empty()){
        temp=wait.top();
        wait.pop();
        for(iter = array[temp].begin();iter!=array[temp].end();iter++){
          if(check[*iter]==false){
            check[*iter]=true;
            wait.push(*iter);
          }
        }
      }
      sum++;
    }
  }
  return sum;
}
int main(){
  int t;
  int N;
  cin>>t;
  for(int a=t-1;a>=0;--a){
    cin>>N;
    vector<list<int > > array(N);
    inputGraph(array);

    cout<<BFS(array)<<endl;
  }
  return 0;
}
