//
//  main.cpp
//  test
//
//  Created by nguyen tan dung on 12/9/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef int i;
#define pb push_back
#define p push
#define f first
#define s second
#define mp make_pair
#define c cout<<"check\n";
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
#define pq priority_queue<pii,vector<pii>,greater<pii> >
#define vvpii vector<vector<pii> >
#define  FOR(iter,a,b) for(ll iter =a;iter<b;++iter)
#define INF 1e9
struct value{
    int value;
    int position;
    bool operator<(const struct value&rhs)const {
      return value<rhs.value;
    }
};
int main(int argc, const char * argv[]) {

    int time=0;
    int testcase;
    cin>>testcase;
    struct value temp;
    for(int t=0;t<testcase;t++){
        int n,m;
        priority_queue <struct value ,vector<struct value >,less<struct value> > priority;
        queue<struct value > wait;
        cin>>n>>m;
        time=0;
        for(int i=0;i<n;i++){
            cin>>temp.value;
            temp.position=0;
            if(i==m){
                temp.position=1;
            }
            priority.push(temp);
            wait.push(temp);
        }
        while(1){
            if(priority.top().value == wait.front().value){
                time++;
                if(wait.front().position==1){
                    break;
                }
                priority.pop();
                wait.pop();

            }else{
                temp=wait.front();
                wait.pop();
                wait.push(temp);
            }
        }
        cout<<time<<endl;
    }
    return 0;
}
