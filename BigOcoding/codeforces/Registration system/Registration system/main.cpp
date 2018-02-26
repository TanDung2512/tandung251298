//
//  main.cpp
//  Registration system
//
//  Created by nguyen tan dung on 11/9/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct doctor{
    int day              ;
    int period;
};
int main(int argc, const char * argv[]) {
    vector<doctor> list1;
    int n;
    cin>>n;
    int count=0;
    doctor pre;
    doctor temp;
    cin>>temp.day;
    cin>>temp.period;
    pre.day=temp.day;
    pre.period=temp.period;
    float sum;
    int max=pre.day;
    for(int i=0;i<n-1;i++){
        cin>>temp.day>>temp.period;
        sum=abs((max-temp.day))/temp.period;
        if(max<(temp.day+count*temp.period)){
            max=temp.day+count*temp.period;
        }
        else{
            
            count=sum+1;
            max=temp.day+count*temp.period;
        }
        cout<<"count "<<count<<endl;
//            pre.day=temp.day;
//            pre.period=temp.period;
    

            
   
    
        }
    cout<<max<<endl;
    return 0;
    
    
//    string s;
//    cin>>s;
//    int
//    for(int i=0;i<s.size();i++){
//        
//    }
}
