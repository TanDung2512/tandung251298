#include<iostream>
#include "AVLTree.h"
#include"Heap.h"
#include<time.h>
#include <chrono>
using namespace std;
int main(){
  AVLTree<int>a;
  Heaptree<int>heaptest=Heaptree<int>(false);
  int size;
  srand(time(NULL));
  int temp;
  cout<<"1.insert node \n";
  cout<<"2.insert random node\n";
  cout<<"3.exit\n";
  int choice;
  cin>>choice;
  switch(choice){
    case 1:
    cout<<"input size: ";
    cin>>size;
    for(int i=0;i<size;i++){
      cin>>temp;
      a.insert(temp);
    }
    a.inorder(a.getRoot());
    break;
    case 2:

      cout<<"input size: ";
      cin>>size;
      clock_t tStart = clock();
      for(int i=0;i<size;i++){
        temp=rand()%10000000;
        a.insert(temp);
      }
      printf("Time taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
      a.inorder(a.getRoot());
    break;
  }
  // cin>>choice;
  // cout<<"\n1.insert node \n";
  // cout<<"2.insert random node\n";
  // cout<<"3.exit\n";
  // switch(choice){
  //   case 1:
  //   cout<<"input size: ";
  //   cin>>size;
  //   for(int i=0;i<size;i++){
  //     cin>>temp;
  //     heaptest.insert(temp);
  //   }
  //   heaptest.display();
  //   break;
  //   case 2:
  //
  //     cout<<"input size: ";
  //     cin>>size;
  //     clock_t tStart = clock();
  //     for(int i=0;i<size;i++){
  //       temp=rand()%10000000;
  //       heaptest.insert(temp);
  //     }
  //     heaptest.display();
  //   break;
  // }


  return 0;
}
