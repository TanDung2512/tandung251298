#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
  map<string,int > map1;
  int n;
  stringstream ss;
  scanf("%d",&n);
  string temp1;

  getline(cin,temp1);
  string a,b;
  while(n--){
    getline(cin,temp1);
    if(!map1[temp1]){
      map1[temp1]=1;
      continue;
    }
    map1[temp1]++;
  }

  map<string,int>::iterator max1;
  int max=-1;
  cout<<endl;
  for (map<string,int>::iterator it=map1.begin() ; it!=map1.end() ; ++it)
  {
    if( max <  (*it).second){
      max= (*it).second;
      max1=it;
    }
  }
 cout<<(*max1).first<<endl;

  return 0;
}
