#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
using namespace std;
typedef int i;
#define pb push_back
#define p push
#define f first
#define s second
#define mp make_pair
#define c cout<<"check\n";
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
#define pq priority_queue<pii,vector<pii>,greater<pii> >
#define vvpii vector<vector<pii> >
#define vvi vector<vector<i> >
#define vi vector<i>
#define  FOR(iter,a,b) for(ll iter =a;iter<b;++iter)
#define INF 1e9;
int main(){

  ll testcase;
  ll num;
  ll temp;
  ll median;
  cin>>testcase;
  FOR(i,0,testcase){
    priority_queue<ll, vector<ll> , greater<ll> > minHeap;
    priority_queue<ll> maxHeap;
    cin>>num;
    median=num;
    if(median==0){
      continue;
    }
    while(1){
      cin>>num;
      if(num==0){
        break;
      }
      if(median==-2){
        median=num;
        continue;
      }
      if(num==-1){
        cout<<median<<endl;
        if(minHeap.size()==maxHeap.size()){
          if(minHeap.size()==0){
            median=-2;
            continue;
          }
          median=maxHeap.top();
          maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()){
          median=minHeap.top();
          minHeap.pop();
        }
        else{
          median=maxHeap.top();
          maxHeap.pop();
        }
        continue;
      }
      if (num>median){
        // cout<<"median= "<<median<<endl;
        // cout<<minHeap.size()<<"   "<<maxHeap.size()<<endl;
        if(minHeap.size()>maxHeap.size()){
          maxHeap.p(median);
          minHeap.p(num);
          median=minHeap.top();
          minHeap.pop();
        }else if(minHeap.size()<maxHeap.size()){
          minHeap.p(num);
        }
        else{
          maxHeap.p(median);
          minHeap.p(num);
          median=minHeap.top();
          minHeap.pop();
        }
      }else{
        // cout<<"median= "<<median<<endl;
        // cout<<minHeap.size()<<"   "<<maxHeap.size()<<endl;
        if(minHeap.size()<=maxHeap.size()){
          minHeap.p(median);
          median=num;
        }else{
          maxHeap.p(num);
        }
      }
    }
  }
  return 0;
}
