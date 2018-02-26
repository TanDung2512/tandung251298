#include<iostream>
#include<set>
#include<iomanip>
using namespace std;
int main(){
  int test;
  scanf("%d",&test);
  string temp1;
  getline(cin,temp1);
  getline(cin, temp1);
  set<string>::iterator it;
  for(int a=0;a<test;a++){
    multiset<string>settree;
    set<string>set1tree;
    int count=0;
    while(getline(cin,temp1)){
      if(temp1.size()==0){
        break;
      }
      settree.insert(temp1);
      set1tree.insert(temp1);
      count++;
    }
    for(it=set1tree.begin();it!=set1tree.end();it++ ){
      cout<<fixed<<setprecision(4)<<*it<<" "<<(double)settree.count(*it)*100/count<<endl;
    }
    cout<<endl;
  }
  return 0;
}
