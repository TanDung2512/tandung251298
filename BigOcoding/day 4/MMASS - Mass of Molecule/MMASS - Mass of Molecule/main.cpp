//
//  main.cpp
//  MMASS - Mass of Molecule
//
//  Created by nguyen tan dung on 11/19/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<stack>
using namespace std;
int massmole(char x){
    if(x=='H'){
        return 1;
    }
    if(x=='C'){
        return 12;
    }
    return 16;
}
int main(int argc, const char * argv[]) {
    string s;
    string temp1;
    cin>>temp1;

        s.append("("+temp1+")");
    
    
 //   cout<<s<<endl;
    stack<int>mole;
    int sum=0;
    int sum1=0;
    int i=0;
    int temp,temp2;
    for(int i=0;i<s.size();i++){
        
        if(s[i]==')'){
            sum1=0;
            while(mole.top()!=-10)
            {
                
                if(mole.top()>=-9 && mole.top()<=-2)
                {
                //    cout<<1<<endl;
                    temp=-mole.top();
                    mole.pop();
                    temp2=mole.top();
                    sum1+=(temp)*temp2;
                }
                else {
                    sum1+=mole.top();
                }
                mole.pop();
            }
            mole.pop();
  
            if(i+1<s.size() && s[i+1]>=50 && s[i+1]<=57){
             
                sum1*=(s[i+1]-48);
                i++;
            }
             mole.push(sum1);
       //     cout<<sum1<<endl;
        }
        else {
            if(s[i]=='('){
                mole.push(-10);
            }
            else if(s[i]>=50 && s[i]<=57){
                int temp13=-(s[i]-48);
          //      cout<<"temp12 " <<temp13<<endl;
                mole.push(temp13);
            }
            else {
                mole.push(massmole(s[i]));
            }
        }
      //  cout<<"mole top"<<mole.top()<<endl;
    }
    cout<<mole.top()<<endl;
    return 0;
}
