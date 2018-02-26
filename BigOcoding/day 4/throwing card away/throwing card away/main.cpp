//
//  main.cpp
//  throwing card away
//
//  Created by nguyen tan dung on 11/18/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<queue>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(1){
        cin>>n;
        if(n==0){
            break;
        }
        queue<int> deck;
        queue <int>deck1;
        for(int i=1;i<=n;i++){
            deck.push(i);
        }
        while(deck.size()!=1){
            int temp=deck.front();
            deck.pop();
            deck1.push(temp);
            temp=deck.front();
            deck.pop();
            deck.push(temp);
        }
        cout<<"Discarded cards:";
        while(!deck1.empty()){
            if(deck1.size()==1){
                cout<<" "<<deck1.front();
                break;
            }
            cout<<" "<<deck1.front()<<",";
            deck1.pop();
        }
        cout<<endl;
        
        cout<<"Remaining card: "<<deck.front()<<endl;
    }
    return 0;
}
