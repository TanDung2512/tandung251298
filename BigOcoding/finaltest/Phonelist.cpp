#include<iostream>
#include<vector>
#include<math.h>
#include<time.h>
using namespace std;
class node{
public:
  node*child[10];
  int countleft;
  node(){
    for(int i=0;i<10;i++){
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
  bool insert(string data){
    node*temp=root;
    for(int i=0;i<data.size();i++){
      int ch=data[i]-'0';
      if(temp->countleft!=0){
        return false;
      }
      if(temp->child[ch]==NULL){
        temp->child[ch]=new node();
      }
      temp=temp->child[ch];
    }
    if(temp->countleft!=0){
      return false;
    }
    temp->countleft++;
    for(int i=0;i<10;i++){
      if(temp->child[i]!=NULL){
        return false;
      }
    }
    return true;
  }
  void deletetree(node*tree){
    if(tree==NULL){
      return;
    }
    for(int i=0;i<10;i++){
      if(tree->child[i]!=NULL){
        deletetree(tree->child[i]);
        delete tree->child[i];
        tree->child[i]=NULL;
      }
    }

  }
};

int main(){
  int testcase;
  cin>>testcase;
  for(int test=1;test<testcase+1;test++){
    trie tree;
    int n;
   cin>>n;
//  n=10000;
    bool check=false;
    string temp;
    while(n--){
      cin>>temp;
      if(!tree.insert(temp) && check==false){
        cout<<"NO"<<endl;
        check=true;
      }
    }
    if(check==false){
      cout<<"YES"<<endl;
    }
    tree.deletetree(tree.root);
  //  cout<<"#size "<<sizeof(tree)<<endl;
  }
  return 0;
}
