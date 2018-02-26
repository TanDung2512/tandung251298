#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class node{
public:
  node*child[4];
  int sum;
  node(){
    for(int i=0;i<4;i++){
      child[i]=NULL;
    }
    sum=0;
  }
};
int index(char temp){
  if(temp=='A'){
    return 0;
  }
  else if ( temp=='C'){
    return 1;
  }
  else if (temp=='G'){
    return 2;
  }
  else {
    return 3;
  }
}
class trie{
public:
  node*root;
  trie(){
    root=new node();
  }
  int insert(string data){
    int max1=-1;
    node*temp=root;
    for(int i=0;i<data.size();i++){
      int ch = index(data[i]);
      if(temp->child[ch]==NULL){
        temp->child[ch]=new node();
      }
      temp=temp->child[ch];
      temp->sum+=i+1;
      if(max1<temp->sum){
        max1=temp->sum;
      }
    }
    return max1;
  }

};
int main(){
  int testcase;
  cin>>testcase;
  for(int i=1;i<testcase+1;i++){
    int n;
    trie tree;
    int max1=-1;
    cin>>n;
    string temp;
    cout<<"Case "<<i<<": ";
    while(n--){
      cin>>temp;
      max1=max(tree.insert(temp),max1);
    }
    cout<<max1<<endl;
  }
  return 0;
}
