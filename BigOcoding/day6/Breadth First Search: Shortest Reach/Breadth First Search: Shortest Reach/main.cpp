//
//  main.cpp
//  Breadth First Search: Shortest Reach
//
//  Created by nguyen tan dung on 11/25/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
int static *path;
static bool *visited ;
static queue<int>waitNode;
void BFS(int startingPoint,vector<vector<int> > graph){
    waitNode.push(startingPoint);
    int node;
    while(!waitNode.empty()){
        node=waitNode.front();
        waitNode.pop();
        for(int i=1;i<graph[node].size();i++){
            if(!visited[graph[node][i]]){
                waitNode.push(graph[node][i]);
                visited[graph[node][i]]=true;
                path[graph[node][i]]=node;
            }
        }
    }
}

int findPath(int u,int v,int *path){
    int temp;
    if(u==v){
        return 0;
    }else {
        if(path[v]==-1){
            return -1;
        }
        else {
            temp= findPath(u,path[v],path);
            if(temp==-1){
                return -1;
            }else {
                return temp+1;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int q,n,m;
    cin>>q;
    for(int j=0;j<q;j++){
    cin>>n>>m;
    vector<vector<int> >graph (MAX);
    visited=new bool [n+1];
    path =new int [n+1];


    for(int i=1;i<=n;i++){
        visited[i]=false;
        path[i]=-1;
    }
    int nodeU,nodeV;
    int startingNode;
        for(int i=0;i<n;i++){
            graph[i].push_back(0);
        }
    for(int i=1;i<=m;i++){
        cin>>nodeU>>nodeV;

        graph[nodeU].push_back(nodeV);
        graph[nodeV].push_back(nodeU);
    }

    cin>>startingNode;
    BFS(startingNode,graph);
        string result;
    for(int i=1;i<=n;i++){
        if(i!=startingNode){
        int sum=findPath(startingNode,i, path);
    //        cout<<endl;
     //       cout<<startingNode<<" "<<i<<" "<<sum<<endl;
        if(sum==-1){
            result.append("-1 ");
        }

        else { sum=sum*6;result.append(to_string(sum));
            result.append(" ");
            }
        }

    }
        if(result[result.size()-1]==' '){
            result.erase(result.size()-1);
        }
        cout<<result<<endl;
    }
    return 0;
}
