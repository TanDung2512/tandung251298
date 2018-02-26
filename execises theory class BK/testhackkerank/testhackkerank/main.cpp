//
//  main.cpp
//  testhackkerank
//
//  Created by nguyen tan dung on 11/7/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
long waitingTime(vector <int> tickets, int p) {
    queue<int> queue1;
    for(int i=0;i<tickets.size();i++){
        queue1.push(tickets[i]);
    }
    long time=0;
    int i;
    while(!queue1.empty()){
        while(p>=0){
            
            i=queue1.front();
            if(p==0 & queue1.front()==1){
                return time++;
            }
            if(i<=1){
                queue1.pop();
            }
            else {
                queue1.pop();
                queue1.push(i-1);
            }
            time++;
        }
        p=queue1.size()-1;
    }
    return time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    long res;
    int tickets_size = 0;
    cin >> tickets_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    vector<int> tickets;
    for(int i = 0; i < tickets_size; i++) {
        int tickets_item;
        cin >> tickets_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tickets.push_back(tickets_item);
    }
    
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    res = waitingTime(tickets, p);
    fout << res;
    
    fout.close();
    return 0;
}
