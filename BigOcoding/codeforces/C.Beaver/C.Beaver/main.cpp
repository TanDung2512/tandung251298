//
//  main.cpp
//  C.Beaver
//
//  Created by nguyen tan dung on 11/13/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    string S;
    string *boringS;
    int sizeBoringS;
    bool check=false;
    int left=0,right=0;
    int sum=1;
    int k;
    int max=0;
    int leftmax=0;
    cin>>S>>sizeBoringS;
    boringS=new string[sizeBoringS];
    for(int i=0;i<sizeBoringS;i++){
        cin>> boringS[i];
    }
    
    for(int i=0;i<S.size();i++){
       cout<<"sum " <<sum<<endl;
        if(S[i]=='_'){
            sum++;
            right++;
            continue;
        }
cout<< " leftmax "<<leftmax<<" left" <<left<<" right " <<S[right]<<endl;
        for(int m=0;m<sizeBoringS;m++){
            if(boringS[m].size()<=sum && S[right]==boringS[m][boringS[m].size()-1]){
cout<<" stringboring "<<boringS[m]<<" "<<endl;
                k=right;
                int j=0;
//                if(boringS[m].size()==1){
//                    check=true;
//                    left=k+1;
//                    sum--;
//                    if(max<=sum ){
//                        max=sum;
//                        leftmax=right-max;
//                    }
//                    sum=right-left+1;
//                
//                }
//                else {
                while(S[k]==boringS[m][boringS[m].size()-1-j] && k>=left)
                {
                    if(j==boringS[m].size()-1 && S[k]==boringS[m][0] && k>=left){
                        check=true;
                        left=k+1;
                        sum--;
                        if(max<=sum ){
                            max=sum;
                            leftmax=right-max;
                        }
                        sum=right-left+1;
                    }
                    k--;
                    j++;
                }
                if(j==boringS[m].size()-1 && S[k]==boringS[m][0] ){
                    break;
                }
            };
        }
        right++;
        sum++;
    }

    if(check==false){
        cout<<sum-1<<" "<<leftmax<<endl;
        return 0;
    }
    else
        if(max==0){
            cout<<0<<" "<<0<<endl;
            return 0;
        }
        if(S.size()==1){
            cout<<0<<" "<<0<<endl;
        }
        else cout<<max<<" "<<leftmax<<endl;
// }
    return 0;
}
