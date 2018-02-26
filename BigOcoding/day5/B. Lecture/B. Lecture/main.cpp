//
//  main.cpp
//  B. Lecture
//
//  Created by nguyen tan dung on 11/24/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
struct typedata{
    string a1,a2;
    
};

int main(int argc, const char * argv[]) {
    int m,n;
    cin>>n>>m;
    string string1;
    struct typedata *array=new struct typedata[m];
    for(int i=0;i<m;i++){
        cin>>string1;
        array[i].a1=string1;
        cin>>string1;
        array[i].a2=string1;
     }
    for(int i=0;i<n;i++){
        cin>>string1;
        for(int j=0;j<m;j++){
            if(string1.compare(array[j].a1)==0){
           //     cout<<array[j].a1.size()<<" "<<array[j].a2.size()<<endl;
                if(array[j].a1.size()>array[j].a2.size()){
                    cout<<array[j].a2<<" ";
                }else cout<<array[j].a1<<" ";
                break;
            }
        }
    }
    return 0;
}
