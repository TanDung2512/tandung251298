#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct data{
  int value;
  bool check;
};
bool compare(const struct data&a,const struct data&b){
  return a.value<b.value;
}
bool binarysearch(vector<struct data >&graph,int x){

  long long left=0;
  long long mid;
  long long right=graph.size()-1;
  while(left<=right){
    mid=left+(right-left)/2;
    if(graph[mid].value==x && graph[mid].check==false){
      graph[mid].check=true;
      return true;
    }
    if(graph[mid].value>x){
      right=mid-1;
    }
    else{
      left=mid+1;
    }
  }
  return false;
}
int main(){
  int testcase;
  cin>>testcase;
  while(testcase--){
    int n;
    int price;
    scanf("%d%d",&n,&price);
    vector< struct data > people;
    struct data temp;
    temp.check =false;
    for(int i=0;i<n;i++){
      scanf("%d",&temp.value);

      people.push_back(temp);
    }
    sort(people.begin(),people.end(),compare);
    int sum=0;
    for(int i=0;i<n;i++){
      if(people[i].check==true){
        continue;
      }
      people[i].check=true;
      int temp2= price - people[i].value;
      if(temp2<people[0].value || temp2>people[n-1].value){
        continue;
      }
      if(binarysearch(people,temp2)){
        sum++;
        continue;
      }
      people[i].check=false;
    }
    cout<<sum<<endl;
  }
  return 0;
}
