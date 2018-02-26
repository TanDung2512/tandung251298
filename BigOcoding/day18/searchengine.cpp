#include<iostream>
#include<vector>
#include<iomanip>
#define  max 26
using namespace std;
struct node{
  struct node*child[max];
  int countleft;
  int maxlength;
};
struct node*newNode(){
  node*Node=new node;
  Node->countleft=0;
  Node->maxlength=0;
  for(int i=0;i<max;i++){
    Node->child[i]=NULL;
  }
  return Node;
}
#define node struct node
class trie {
public:
  node*root;
  trie () {
    this->root=newNode();
  }
    void addWord(string s,int max1){
      int ch;
      node *temp=root;
      for(int i=0;i<s.size();i++){
        ch=s[i]-'a';
        if(temp->child[ch]==NULL){
          temp->child[ch]=newNode();
        }
        temp=temp->child[ch];
        if(temp->maxlength<max1){
          temp->maxlength=max1;
        }
      }
      temp->countleft++;
    }
};
int main(){
  int m,n;
  cin>>m>>n;
  string s;
  int q;

  trie a2;
  while(m--){
    cin>>s>>q;
    a2.addWord(s,q);
  }
//  cout << "done";
  while(n--){
    cin>>s;
    bool check=false;
    int ch;
    node*temp;
    temp=a2.root;
    for(int i=0;i<s.size();i++){
      //cout << s[i];
      ch=s[i]-'a';
      if(temp->child[ch]==NULL){
        cout<<-1<<endl;
        check=true;
        break;
      }
      temp=temp->child[ch];
    }
    if(check==false){
      cout<<temp->maxlength<<endl;
    }
  }
  return 0;
}
