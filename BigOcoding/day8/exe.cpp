#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    int choose;
    long int num;
    priority_queue<long int,vector<long int>, greater<long int> > wait;
    priority_queue<long int,vector<long int>, greater<long int> > wait1;
    for(int i=0;i<N;i++){
      cin>>choose;
      if(choose==1){
        cin>>num;
        wait.push(num);
      }
      if(choose==2){
        cin>>num;
        wait1.push(num);
      }
      if(choose==3){
        if(!wait1.empty()){
        while(wait1.top()==wait.top()){
          wait.pop();
          wait1.pop();
        }
      }
        cout<<wait.top()<<endl;
      }
    }
    return 0;
}
