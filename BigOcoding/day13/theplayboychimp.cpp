#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
void binarylower(vector <ll > chimp, ll data){
  ll left=0;
  ll right = chimp.size()-1;
  ll mid;
  while(left<=right){
     mid =left+(right-left)/2;
    if(chimp[mid]<data && ((mid==chimp.size()-1)||( chimp[mid+1]>=data))){
      printf("%lld",chimp[mid]);
      return ;
    }
    else if (chimp[mid]<data){
        left=mid+1;
    }else {
      right=mid-1;

    }
  }
  printf("X");
}
void binaryupper(vector <ll > chimp, ll data){
  ll left=0;
  ll right = chimp.size()-1;
  ll mid ;
  while(left<=right){
    ll mid =left+(right-left)/2;

    if(  chimp[mid]>data && (mid==0||(chimp[mid-1]<=data))){
      printf("%lld",chimp[mid]);
      return ;
    }
    else if (chimp[mid]>data){
        right=mid-1;
    }else {
      left=mid+1;
    }
  }
  printf("X");

}
int main(){
  ll n;
  scanf("%lld",&n);
  vector < long long > chimp(n);
  for(ll i=0;i<n;i++){
    scanf("%lld",&chimp[i]);
  }
  ll m;
  scanf("%lld",&m);
  ll temp;
//  vector <ll> query (m);
  for(ll i=0;i<m;i++){
    scanf("%lld",&temp);
    binarylower(chimp,temp);

    printf(" ");
    binaryupper(chimp,temp);
    printf("\n");
  }

  return 0;
}
