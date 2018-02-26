//
//  main.cpp
//  ONP - Transform the Expression
//
//  Created by nguyen tan dung on 11/19/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<stack>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {

    int n;
    string s;
    cin>>n;

    for(int j=0;j<n;j++){
        cin>>s;
        stack<char>expression;
        queue<char>solution;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                while(expression.top()!='('){
                    solution.push(expression.top());
                    expression.pop();
                }
                expression.pop();
            }
            else if(s[i]=='(' || s[i] =='*' || s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='^'){
                expression.push(s[i]);
            }
            else if(s[i]>=97 && s[i]<=122){
                solution.push(s[i]);
            }
        }
        while(!solution.empty()){
            cout<<solution.front();
            solution.pop();
        }
        cout<<endl;
    }
    
    return 0;
}
