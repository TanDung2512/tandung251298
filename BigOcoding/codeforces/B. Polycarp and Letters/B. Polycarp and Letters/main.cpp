//
//  main.cpp
//  B. Polycarp and Letters
//
//  Created by nguyen tan dung on 11/12/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int size;
    string S;
    cin>>size>>S;
    int left=0,right=0,countdiff=0,max=0;
    int alphabet[26];
    if(S.size()==1){
        if((int)S[right]>=97 && (int)S[right]<=122)
            cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    while(right<S.size() ){
//        for(int i=0;i<26;i++){
//           cout<< alphabet[i]<<" ";
//        }
//        cout<<endl;
        for(int i=0;i<26;i++){
            alphabet[i]=0;
        }
        if((int)S[right]>=65 && (int)S[right]<=90){
            right++;
            left=right;
            continue;
        }

        while((int)S[right]>=97 && (int)S[right]<=122 && right<S.size()){
//         cout<<1<<endl;

            if(alphabet[(int)S[right]-97]==0){
                countdiff++;
                alphabet[(int)S[right]-97]++;
                right++;
            }
            else {
                alphabet[(int)S[right]-97]++;
                right++;
            }
//            for(int i=0;i<26;i++){
//                cout<< alphabet[i]<<" ";
//            }
//            cout<<countdiff<<endl;
            if((int)S[right]>=65 && (int)S[right]<=90){

                right++;
                left=right;
                break;
            }
            
        }
        if(max<countdiff){
            max=countdiff;
        }
       countdiff=0;
        
    }
    cout<<max<<endl;
    return 0;
}
