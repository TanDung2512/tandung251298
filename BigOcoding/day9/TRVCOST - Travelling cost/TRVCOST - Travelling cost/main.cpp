//
//  main.cpp
//  TRVCOST - Travelling cost
//
//  Created by nguyen tan dung on 12/6/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>
#define Max 2000

const long long int INF=1e9;
using namespace std;
void disktra(vector<vector<pair<long int,long int>>> graph,vector<long int>&distain,vector<long int>& path,long int source){
    priority_queue<pair<long int,long int>,vector<pair<long int,long int>>,greater<pair<long int,long int>>> wait;
    pair<long int,long int> temp,temp1;
    temp.first=0;
    temp.second=source;
    wait.push(temp);
    distain[source]=0;
    while(!wait.empty()){
        
        temp=wait.top();
        wait.pop();
        for(long int i=0;i<graph[temp.second].size();i++){
            pair<long int ,long int > neighbor=graph[temp.second][i];
            if(neighbor.second+temp.first < distain[neighbor.first]){
                distain[neighbor.first]=neighbor.second+temp.first;
                path[neighbor.first]=temp.second;
                temp1.first=distain[neighbor.first];
                temp1.second=neighbor.first;
                wait.push(temp1);
            }
        }
    }
}
int main( int argc, const char * argv[]) {
    vector<vector<pair<long int,long int>>> graph(Max);
    vector<long int>path(Max,-1);
    vector< long int>distain(Max,INF);
    long int n;
    cin>>n;
    long int a,b,w;
    pair<long int,long int> temp;
    for(long int i=0;i<n;i++){
        cin>>a>>b>>w;
        temp.first=b;
        temp.second=w;
        graph[a].push_back(temp);
        temp.first=a;
        graph[b].push_back(temp);
    }
    long int source;
    cin>>source;
    disktra(graph,distain,path,source);
    cin>>n;
    long int temp1;
    for(long int i=0;i<n;i++){
        cin>>temp1;
        if(temp1==source){
            cout<<0<<endl;
            continue;
        }
        if(path[temp1]!=-1){
        cout<<distain[temp1]<<endl;
        }
        else cout<<"NO PATH"<<endl;
    }
    return 0;
}
