#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct IDs{
  long int ID,Z,changeZ,newID;
  bool operator< (const IDs & b)const{
    if(changeZ==b.changeZ){
      return ID<b.ID;
    }
    return changeZ<b.changeZ;
  }
};
int main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  long int N, P, L, C, S;
  cin>>N;
  struct IDs IDtemp;
    priority_queue< struct IDs> wait;
  for(long int t=0;t<N;++t){
    cin>>IDtemp.ID>>IDtemp.Z>>P>>L>>C>>S;
    IDtemp.newID=(L*5)+ (C*10) +(S*20)+(P*50);
    IDtemp.changeZ=IDtemp.newID-IDtemp.Z;
    wait.push(IDtemp);
  }
  for(int i=0;i<5;++i){
    IDtemp=wait.top();
    wait.pop();
    cout<<IDtemp.ID<<" "<<IDtemp.newID<<endl;
  }
  return 0;
}
