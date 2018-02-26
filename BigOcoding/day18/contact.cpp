#include<iostream>
#include<math.h>
using namespace std;
class node{
public:
  node*child[26];
  int countleft;
  node(){
  for(int i=0;i<26;i++){
    child[i]=NULL;
  }
  countleft=0;
}
};
class trie{
public:
  node*root;
  trie(){
    root=new node();
  }
  void insert(string data){
    node*temp=root;
    for(int i=0;i<data.size();i++){
      int ch=data[i]-'a';
      if(temp->child[ch]==NULL){
        temp->child[ch]=new node();
      }
      temp=temp->child[ch];
      temp->countleft++;
    }
  }
  int search(string data){
    node*temp=root;
    for(int i=0;i<data.size();i++){
      int ch=data[i]-'a';
      if(temp->child[ch]==NULL){
        return 0;
      }
      temp=temp->child[ch];
    }
    return temp->countleft;
  }
};
int main(){
  int n;
  string cmd;
  string word;
  trie tree ;
  cin>>n;
  while(n--){
    cin>>cmd;
    cin>>word;
    if(cmd=="add"){
      tree.insert(word);
    }
    else if(cmd=="find"){
      cout<<tree.search(word)<<endl;
    }
  }
  return 0;
}
