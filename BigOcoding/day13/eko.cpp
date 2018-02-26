#include<iostream>
#include<vector>
#include<algorithm>
#define ll unsigned long long
using namespace std;
ll binarysearch(vector < ll > trees,ll data,ll price){
  ll left=0;
  ll right=trees.size()-1;
  ll mid;
  ll sum=0;
  while(left<=right){
    mid=left+(right-left)*0.5;
    if(trees[mid]>=data && (mid==0|| trees[mid-1]<data)){
      sum=0;
      //cout<<"mid"<<mid<<endl;
      for(ll i=mid;i<trees.size();i++ ){
        sum+=trees[i]-data;
      }
      return sum;
    }
    else if(trees[mid]>data){
      right=mid-1;
    }
    else left=mid+1;
  }
  return sum;
}
int main(){
  ll n;
  scanf("%lld",&n);
  ll m;
  scanf("%lld",&m);
  vector < ll > trees(n);
  for(ll i=0;i<n;i++){
    scanf("%lld",&trees[i]);
  }
  sort(trees.begin(),trees.end());
  ll left=0;
  ll right=trees[trees.size()-1];
  ll mid;
  ll solut;
  ll min=18446744073709551615;
  while(left<=right){
    mid=left+(right-left)*0.5;
  //  cout<<"mid "<<mid<<endl;
    solut=binarysearch(trees,mid,m);
  //  cout<<"solut "<<solut<<endl;
    if(m==solut){
     cout<<mid<<endl;
     return 0;
    }
    if(solut>m){
      if(mid<min){
        min=mid;
      }
      left=mid+1;
    }
    else {
      right=mid-1;
    }
  //  cout<<left<<" "<<right<<endl;
  }
  cout<<min<<endl;

  return 0;
}
