#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binarysearch(vector <int > marble,int x){
  int mid;
  int left=0;
  int right=marble.size()-1;
  while(left<=right){
    mid=left+(right-left )/2;
    if(( mid==left || x>marble[mid-1])&& marble[mid]==x ){
      return mid ;
    }
    if(marble[mid]>=x){
      right=mid-1;
    }
    else {
      left=mid+1;
    }
  }
  return -1;
}

int main(){
  int count=1;
  int n,m;
  while(cin>>n,cin>>m){
    if(n==0 && m==0){
      return 0;
    }
    vector <int > marble ;
    int temp;
    for(int i=1;i<=n;i++){
      scanf("%d",&temp);
      marble.push_back(temp);
    }
    std::sort(marble.begin(),marble.end());
    // for(int i=0;i<n;i++){
    //   cout<<marble[i]<<" ";
    // }
    // cout<<endl;
    int temp1,temp2;
    cout<<"CASE# "<<count<<":"<<endl;
    for(int i=1;i<=m;i++){
      scanf("%d",&temp1);
      temp2=binarysearch(marble,temp1);
      if(temp2==-1){
        cout<<temp1<<" not found"<<endl;
      }
      else {
        cout<<temp1<<" found at "<<temp2+1<<endl;
      }
    }
    count++;
  }
  return 0;
}
