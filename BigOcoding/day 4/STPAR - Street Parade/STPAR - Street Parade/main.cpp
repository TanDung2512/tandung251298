//
//  main.cpp
//  STPAR - Street Parade
//
//  Created by nguyen tan dung on 11/18/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<stack>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    bool check;
    int temp;

    while(1){
        queue<int> first;
        stack<int>wait;
        queue<int>f;
        check=true;
        cin>>n;
        if(n==0){
            break;
        }
    for(int i=0;i<n;i++){
        cin>>temp;
        first.push(temp);
    }
    while(!first.empty()){

        temp=first.front();
        first.pop();
        if(!first.empty()){
            int second=first.front();
        //    cout<<temp<<" "<<second<<endl;
            if(temp>=second){
                if(!wait.empty()){
          //          cout<<temp<<" "<<wait.top()<<endl;

                    if(temp<wait.top()){
                        wait.push(temp);
                        
                    }
                    else{
                        while (!wait.empty() &&temp>=wait.top()){
                            int temp1=wait.top();
                            wait.pop();
                            f.push(temp1);
                        }
                        wait.push(temp);
                    }
                }
                else {
                    wait.push(temp);
                }
            }else if (temp<second){
                if(!wait.empty()){
         //           cout<<temp<<" "<<wait.top()<<endl;

                    if(temp<=wait.top()){
                        f.push(temp);
                    }
                    else{
                        while (!wait.empty() &&temp>=wait.top()){
                            int temp1=wait.top();
                            wait.pop();
                            f.push(temp1);
                        }
                        wait.push(temp);
                    }
                }
                else {
                    f.push(temp);
                }
            }
        }else {
            if(!wait.empty()){
      //          cout<<temp<<" "<<wait.top()<<endl;

                if(temp<wait.top()){
                    f.push(temp);
                }
                else{
                    while (!wait.empty() &&temp>=wait.top()){
                        int temp1=wait.top();
                        wait.pop();
                        f.push(temp1);
                    }
                    f.push(temp);
                }
            }
            else f.push(temp);
        }
    }
    
    while(!wait.empty()){
        int temp1=wait.top();
        wait.pop();
        f.push(temp1);
    }
    for(int i=0;i<n-1;i++){
        temp=f.front();
        f.pop();
     //  cout<<temp<<" "<<f.front()<<endl;
        if(temp>f.front()){
            check=false;
            break;
        }
    }
        while(!wait.empty()){
            f.pop();
        }
        
        if(check==true){
            cout<<"yes"<<endl;
        }else cout<<"no"<<endl;
    }
    return 0;
}
