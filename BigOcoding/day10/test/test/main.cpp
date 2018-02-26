//
//  main.cpp
//  test
//
//  Created by nguyen tan dung on 12/9/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<queue>
using namespace std;
struct value{
    int value;
    int position;
};
int main(int argc, const char * argv[]) {
    priority_queue<struct value >priority;
    queue<struct value> wait;
    int time=0;
    int testcase;
    cin>>testcase;
    struct value temp;
    for(int t=0;t<testcase;t++){
        int n,m;
        cin>>n>>m;
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
            if(priority.top().value==wait.front().value){
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
