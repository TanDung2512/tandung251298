//
//  main.cpp
//  excirsis 7
//
//  Created by nguyen tan dung on 7/11/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
void swap(int &n,int &m){
    int temp;
    temp=n;
    n=m;
    m=temp;
}
int main(int argc, const char * argv[]) {
    int n,a,b,l_1,l_2,p_1,q_1,p_2,q_2;
    cin>>n;
    int nam[n],nu[n],xep[2*n ];
    for (int i=0; i<n; i++) {
        nam[i]=2*i;
    }
    for (int i=0; i<n; i++) {
        nu[i]=2*i+1;
    }
    a=n-2;
    while (a>=0) {
        for (int i=0; i<n; i++) {
            xep[2*i]=nam[i];
        }
            b=n-2;
        for (int i=0; i<n; i++) {
            nu[i]=2*i+1;
        }
        a=n-2;
        while (b>=0) {

            for (int j=0; j<n; j++) {
                xep[2*j+1]=nu[j];
                }
            for (int j=0; j<2*n; j++) {
                cout<<xep[j];
            }
            cout<<endl;
            b=n-2;
            while (b>=0 && nu[b]>nu[b+1]) {
                b--;
            }
            if (b>=0) {
                l_2=n-1;
                while (nu[l_2]<nu[b]) {
                    l_2--;
                }
                swap(nu[l_2],nu[b]);
                p_2=b+1;
                q_2=n-1;
                while (p_2<q_2) {
                    swap(nu[p_2], nu[q_2]);
                    p_2++;
                    q_2--;
                }
            
            }
            }
        
        a=n-2;
        while (a>=0 && nam[a]>nam[a+1]) {
            a--;
        }
        if (a>=0) {
            l_1=n-1;
            while (nam[l_1]<nam[a]) {
                l_1--;
            }
            swap(nam[l_1],nam[a]);
            p_1=a+1;
            q_1=n-1;
            while (p_1<q_1) {
                swap(nam[p_1], nam[q_1]);
                p_1++;
                q_1--;
            }
        }
    }

        return 0;

}
