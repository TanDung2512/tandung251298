#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  pair<int ,int > temp;
  set < < pair<int,int > > > mymultiset;
  vector<pair<int,int > > array1;
  vector<vector < int > >answer(3);
  for(int i=0;i<n;i++){
    cin>>temp.first;
    temp.second=i+1;
    mymultiset.insert(temp.first);
    array1.push_back(temp);
  }
  sort(array1.begin(),array1.end());
  multiset< pair<int,int > >::iterator it;
  int sum=0;


  for(it=mymultiset.begin();it!=mymultiset.end();it++){
    int countarray=1;
    if(mymultiset.count((*it))>2){
      cout<<"YES1"<<endl;
      for(int i=0;i<array1.size();i++){
        answer[0].push_back(array1[i].second);
        answer[1].push_back(array1[i].second);
        answer[2].push_back(array1[i].second);
      }
      for(int i=0;i<array1.size();i++){
        if( (*it) == array1[i].first ){
          swap(answer[1][i],answer[1][i+1]);
          swap(answer[2][i+1],answer[2][i+2]);
          break;
        }
      }
      for(int i=0;i<3;i++){
        for(int j=0;j<answer[i].size();j++){
          cout<<answer[i][j]<<" ";
        }
        cout<<endl;
      }
      return 0 ;
    }
    else if(mymultiset.count((*it))==2){
      cout<<1<<endl;
      sum++;
      if(sum==2){
        cout<<"YES"<<endl;
        for(int i=0;i<array1.size();i++){
          answer[0].push_back(array1[i].second);
          answer[1].push_back(array1[i].second);
          answer[2].push_back(array1[i].second);
        }
        for(int i=0;i<array1.size();i++){
          if(mymultiset.count((*it)) == 2 && sum!=0){
            swap(answer[countarray][i],answer[countarray][i+1]);
            i++;
            countarray++;
            sum--;
          }
        }
        for(int i=0;i<3;i++){
          for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
          }
          cout<<endl;
        }
        return 0;
     }
    }
  }
  cout<<"NO"<<endl;


  return  0;
}
