//
//  main.cpp
//  binary tree
//
//  Created by nguyen tan dung on 7/28/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;
struct node{
    double root;

};
struct node_node{
    node left;
    node right;
};
void initial_binary_tree(struct node root,float n){
    while(root.root!=0){
        if (n>root.root) {
            initial_binary_tree(,n);
        }
        if (n<root.root) {
            initial_binary_tree(root.left,n);
        }
    }
}
int main(int argc, const char * argv[]) {
    float array[20];
  
    for (int i=0; i<20; i++) {
        array[i]=rand()%100;
    }

    struct node node_tree[20];
    srand((unsigned)time(NULL));
    for (int i=0; i<20; i++) {
        node_tree[i].root=array[i];
        node_tree[i].left=NULL;
        node_tree[i].right=NULL;
        cout<<"node("<<i<<")=("<<node_tree[i].root<<","<<node_tree[i].left <<","<<node_tree[i].right<<")"<<endl;
    }
    for (int =0; i<20; i++) {
        <#statements#>
    }
    return 0;
}
