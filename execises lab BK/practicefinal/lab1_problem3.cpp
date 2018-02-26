#include<iostream>
#include<vector>
using namespace std;
string append1(string a,string b){
  string temp;
  temp.append(a);
  temp.append(b);
  return temp;
}

string recursive(int n){
  if(n==0){
    return "0";
  }
  if(n==1){
    return "01";
  }
  else {
    string a= recursive(n-1);
    string b=recursive(n-2);
    return a.append(b);
  }
}
int main(){
  int n;
  cin>>n;
  vector<string> array1(n+1);
  string s1="0";
  string s2="01";
  string temp1 = recursive(n);
  cout<<temp1<<endl;
  // if(n>2){
  //   array1[0]=s1;
  //   array1[1]=s2;
  //   for(int i=2;i<=n;i++){
  //     array1[i]=append1(array1[i-1],array1[i-2]);
  //   }
  // }
  // for(int i=0;i<n+1;i++){
  //   cout<<array1[i]<<" ";
  // }
  // cout<<endl;
  return 0;
}
