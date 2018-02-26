#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n1;
    int n2;
    int n3;
    int min[3];
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    stack<int> stack1,stack2,stack3;
    
    for(int h1_i = 0;h1_i < n1;h1_i++){
        cin >> h1[h1_i];
        stack1.push(h1[h1_i]);
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
        cin >> h2[h2_i];
        stack2.push(h2[h2_i]);
        
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
        cin >> h3[h3_i];
        stack3.push(h3[h3_i]);
    }
    int min1;
    while(n1!=n2 & n2!=n3 & n1!=n3){
        min[0]=stack1.top();
        min[1]=stack2.top();
        min[2]=stack3.top();
        min1=min[0];
        for(int i=1;i<3;i++){
            if(min1>min[i]){
                min1=min[i];
            }
        }
        if(min1==min[0]){
            n2-=stack2.top();
            n3-=stack3.top();
            stack2.pop();
            stack3.pop();
        }
        else if (min1==min[1]){
            n1-=stack1.top();
            n3-=stack3.top();
            stack1.pop();
            stack3.pop();
            
        }
        else if (min1==min[2]){
            n2-=stack2.top();
            n1-=stack1.top();
            stack1.pop();
            stack2.pop();
        }
    }
    cout<<n1<<endl;
    return 0;
}
