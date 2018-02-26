#include<iostream>
#include<queue>
#include<time.h>
#include <chrono>
using namespace std;

template<class nodeTEMPLATE>
class Node{
  public:    nodeTEMPLATE data;
              Node<nodeTEMPLATE>*NODELEFT;
              Node<nodeTEMPLATE>*NODERIGHT;
              int height;
  public:
      Node(){
        this->data=NULL;
        this->NODELEFT=NULL;
        this->NODERIGHT=NULL;
        height=1;
      }
      Node(nodeTEMPLATE data){
        this->data=data;
        this->NODELEFT=NULL;
        this->NODERIGHT=NULL;
        height=1;
      }
      nodeTEMPLATE getData(){
        return this->data;
      }
      void setData(nodeTEMPLATE data){
        this->data=data;
      }
      void setLNode(Node*link){
        this->NODELEFT=link;
      }
      void setRNode(Node*link){
        this->NODERIGHT=link;
      }
      Node<nodeTEMPLATE>*getLNode(){
        return this->NODELEFT;
      }
      Node<nodeTEMPLATE>*getRNode(){
        return this->NODERIGHT;
      }

};
template<class BinaryTEMPLATE>
class AVLTree{
public:
  Node<BinaryTEMPLATE>*root;
  AVLTree();
  void Insert(BinaryTEMPLATE data);
  Node<BinaryTEMPLATE>*insertAVL(Node<BinaryTEMPLATE>*root,BinaryTEMPLATE data);
  void deleteAVLNode(BinaryTEMPLATE data);
  Node<BinaryTEMPLATE>*deleteNode(Node<BinaryTEMPLATE>*root,BinaryTEMPLATE data);
  void searchNode(Node<BinaryTEMPLATE>*root,BinaryTEMPLATE data,Node<BinaryTEMPLATE>*findData);
  Node<BinaryTEMPLATE>* balance(Node<BinaryTEMPLATE>*root,int data);
  Node<BinaryTEMPLATE>* lofl(Node<BinaryTEMPLATE>*root);
  Node<BinaryTEMPLATE>*rofr(Node<BinaryTEMPLATE>*root);
  int Height(Node<BinaryTEMPLATE> *node);
  int diff(Node<BinaryTEMPLATE> *node);
  void Inorder(Node<BinaryTEMPLATE> *root);
  void Preorder(Node<BinaryTEMPLATE> *root1);
  void Postorder(Node<BinaryTEMPLATE> *root);
  ~AVLTree();
};

template<class BinaryTEMPLATE>
AVLTree<BinaryTEMPLATE>::AVLTree(){
    this->root=NULL;
}

// template<class BinaryTEMPLATE>
// void AVLTree<BinaryTEMPLATE>::InsertNode(BinaryTEMPLATE data){
//   if(this->root==NULL){
//     this->root=new Node<BinaryTEMPLATE> (data);
//     return;
//   }
//   Node<BinaryTEMPLATE> *temp=this->root;
//   Node<BinaryTEMPLATE> *before=this->root;
//   while(temp!=NULL){
//     before=temp;
//     if(temp->getData()>data){
//       temp=temp->getLNode();
//     }
//     else{
//       temp=temp->getRNode();
//     }
//   }
//   Node<BinaryTEMPLATE> *NNode=new Node<BinaryTEMPLATE>(data);
//   if(before->getData()>data){
//     before->setLNode(NNode);
//   }
//   else{
//     before->setRNode(NNode);
//   }
// }
template<class BinaryTEMPLATE>
void AVLTree<BinaryTEMPLATE>::Insert(BinaryTEMPLATE data){
  this->root=this->insertAVL(this->root,data);
}

template<class BinaryTEMPLATE>
Node<BinaryTEMPLATE>* AVLTree<BinaryTEMPLATE>::insertAVL(Node<BinaryTEMPLATE>*root,BinaryTEMPLATE data){
  if(root==NULL){
    return new Node<BinaryTEMPLATE>(data);
  }
  else if(root->data==data){
    return root;
  }
  else if(root->data>data){
    root->NODELEFT=insertAVL(root->NODELEFT,data);
  }
  else {
    root->NODERIGHT=insertAVL(root->NODERIGHT,data);
  }
  root->height=1 + max(Height(root->NODELEFT),Height(root->NODERIGHT));
  root=balance(root,data);
  return root;
}

template<class BinaryTEMPLATE>
void AVLTree<BinaryTEMPLATE>::deleteAVLNode(BinaryTEMPLATE data){
    this->root=deleteNode(this->root,data);
    int left =Height(this->root->getLNode());
    int right=Height(this->root->getRNode());
    if(left-right>1){
      this->root=lofl(this->root);
    }
    else if (right-left>1){
      this->root=rofr(this->root);
    }
}

template<class BinaryTEMPLATE>
Node<BinaryTEMPLATE>*AVLTree<BinaryTEMPLATE>::deleteNode(Node<BinaryTEMPLATE>*root,BinaryTEMPLATE data){
  if(root==NULL){
    cout<<"the Node is not exist"<<endl;
    return root;
  }
  if(root->getData()==data){
    if(root->getLNode()==NULL && root->getRNode()==NULL){
      return NULL;
    }
    else if(root->getLNode()==NULL && root->getRNode()!=NULL){
      return root->getRNode();
    }
    else if (root->getRNode()==NULL && root->getLNode()!=NULL){
      return root->getLNode();
    }
    else {
      Node<BinaryTEMPLATE>*temp=root;
      Node<BinaryTEMPLATE>*father=root->getRNode();
      BinaryTEMPLATE tempdata;
      while(father->getLNode()!=NULL){
        temp=father;
        father=father->getLNode();
      }
      if(father->getRNode()!=NULL){
        root->setData(father->getData());
        father->setData(father->getRNode()->getData());
        father->setRNode(NULL);
        root=balance(root,data);
      }
      else{
        root->setData(father->getData());
        if(temp==root){
          temp->setRNode(NULL);
        }
        else temp->setLNode(NULL);
        root=balance(root,data);
      }
    }
  }
  else if(root->getData()>data){
    root->setLNode(deleteNode(root->getLNode(),data));
  }
  else if(root->getData()<data){
    root->setRNode(deleteNode(root->getRNode(),data));
  }
  return root;
  }

template<class BinaryTEMPLATE>
void AVLTree<BinaryTEMPLATE>::searchNode(Node<BinaryTEMPLATE>*root,BinaryTEMPLATE data,Node<BinaryTEMPLATE>*findData){
    if(root==NULL){
      cout<<"cannot find node"<<endl;
      findData=NULL;
      return;
    }
    else if(root->getData()==data){
      findData=root;
      return;
    }
    else if(root->getData()>data){
      searchNode(root->getLNode(),data,findData);
    }
    else {
      searchNode(root->getRNode(),data,findData);
    }
  }

template<class BinaryTEMPLATE>
Node<BinaryTEMPLATE>* AVLTree<BinaryTEMPLATE>::balance(Node<BinaryTEMPLATE>*root,int data){
    int height=diff(root);
    if(height==1|| height ==-1 || height ==0){
      return root;
    }
    if(height>1){
      if(diff(root->NODELEFT)>0)
        root=lofl(root);
      else {
        root->NODELEFT=rofr(root->NODELEFT);
        return lofl(root);
      }
    }
    else {
      if(diff(root->NODERIGHT)<0)
        root=rofr(root);
      else {
          root->NODERIGHT=lofl(root->NODERIGHT);
          return rofr(root);
        }
    }
    return root;
  }

template<class BinaryTEMPLATE>
Node<BinaryTEMPLATE>* AVLTree<BinaryTEMPLATE>::lofl(Node<BinaryTEMPLATE>*root){
    Node<BinaryTEMPLATE>*temp=root;
    root=root->NODELEFT;
    Node<BinaryTEMPLATE>*Rtemp=root->NODERIGHT;
    root->NODERIGHT=temp;
    temp->NODELEFT=Rtemp;
    root->height=Height(root);
    temp->height=Height(temp);
    return root;
  }

template<class BinaryTEMPLATE>
Node<BinaryTEMPLATE>* AVLTree<BinaryTEMPLATE>::rofr(Node<BinaryTEMPLATE>*root){
    Node<BinaryTEMPLATE>*temp=root;
    root=root->NODERIGHT;
    Node<BinaryTEMPLATE>*Ltemp=root->NODELEFT;
    root->NODELEFT=temp;
    temp->NODERIGHT=Ltemp;
    root->height=Height(root);
    temp->height=Height(temp);
    return root;
  }

template<class BinaryTEMPLATE>
int AVLTree<BinaryTEMPLATE>::Height(Node<BinaryTEMPLATE> *node){
    return (node==NULL)?(0):(1+max(Height(node->NODELEFT),Height(node->NODERIGHT)));
}

template<class BinaryTEMPLATE>
int AVLTree<BinaryTEMPLATE>::diff(Node<BinaryTEMPLATE> *node){
  if(node==NULL){
    return 0;
  }
  if(node->NODELEFT!=NULL && node->NODERIGHT!=NULL)
  {
    return node->NODELEFT->height-node->NODERIGHT->height;}
  if(node->NODELEFT!=NULL && node->NODERIGHT==NULL){
    return node->NODELEFT->height;
  }
  if(node->NODERIGHT!=NULL&& node->NODELEFT==NULL){
    return -node->NODERIGHT->height;
  }
  return 0;
}

template<class BinaryTEMPLATE>
void AVLTree<BinaryTEMPLATE>::Postorder(Node<BinaryTEMPLATE> *root)
  {
    if(root==NULL){
      return;
    }
    Postorder(root->getLNode());
    Postorder(root->getRNode());
    cout<<root->getData()<<" ";
  }

template<class BinaryTEMPLATE>
void AVLTree<BinaryTEMPLATE>::Preorder(Node<BinaryTEMPLATE> *root1)
  {
    if(root1==NULL){
      return;
    }
    cout<<root1->getData()<<" ";
    Preorder(root1->getLNode());
    Preorder(root1->getRNode());
}

template<class BinaryTEMPLATE>
void AVLTree<BinaryTEMPLATE>::Inorder(Node<BinaryTEMPLATE> *root){
  if(root==NULL){
    return;
  }
  Inorder(root->getLNode());
  cout<<root->getData()<<" ";
  Inorder(root->getRNode());
}

template<class BinaryTEMPLATE>
AVLTree<BinaryTEMPLATE>::~AVLTree(){
  while(this->root!=NULL){
    this->deleteAVLNode(this->root->data);
  }
}
int main(){
  AVLTree<long long>root1;
  clock_t tStart = clock();
  long long size;
  cin>>size;
  int temp;
  for(long long i=0;i<size;i++){
    cin>>temp;
    root1.Insert(temp);
    root1.Preorder(root1.root);
    cout<<endl;
  }

  printf("Time taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}
