#include<iostream>
#include<map>
#include<iomanip>
#include<math.h>
#define ll long long
using namespace std;
struct point {
  ll x;
  ll y;

};
ll cal(struct point temp){
  return temp.x*temp.x+temp.y*temp.y;
}

int main(){
   map<ll,ll>map1;
  ll n,P;
  scanf("%I64d%I64d",&n,&P);
  struct point temp;
  ll tempP;
  double abc;
  while(n--){
    scanf("%I64d%I64d%I64d",&temp.x,&temp.y,&tempP);
    abc=cal(temp);
    if(map1.find(abc)!=map1.end()){
      map1[abc]+=tempP;
    }
    else map1[abc]=tempP;
  }
  for(map<ll,ll>::iterator it=map1.begin();it!=map1.end();it++){
    P+=(*it).second;
    if(P>=1000000){
      cout<<fixed<<setprecision(7)<<sqrt((*it).first)<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}
