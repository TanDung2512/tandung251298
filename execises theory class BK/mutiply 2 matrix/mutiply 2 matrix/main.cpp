//
//  main.cpp
//  mutiply 2 matrix
//
//  Created by nguyen tan dung on 9/3/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;
    void mutiplymatrix(float **a,float **b,float **c ,int n1,int n2,int m1){
        float sum=0;
        for(int i=0;i<n1;i++){
            for(int j=0;j<m1;j++){
                sum=0;
                for(int k=0;k<n2;k++){
                    sum+=b[i][k]*c[k][j];
                }
            a[i][j]=sum;
            }
        }
    }
void mastress(float **a,float **b,float **c,int start_row,int end_row,int start_colum,int end_colum,int n){
    cout<<endl;
    cout<<b[start_row][start_colum]<<" "<<b[start_row][end_colum-1]<<" "<<b[end_row-1][start_colum]<<" "<<b[end_row-1][end_colum-1]<<endl;
    cout<<c[start_row][start_colum]<<" "<<c[start_row][end_colum-1]<<" "<<c[end_row-1][start_colum]<<" "<<c[end_row-1][end_colum-1]<<endl;
    if(n==2){
        cout<<"123"<<endl;
        int M1=(b[start_row][start_colum]+b[end_row -1][end_colum-1])*(c[start_row][start_colum]+c[end_row -1][end_colum-1]);
        int M2=(b[end_row-1][start_colum]+b[end_row-1][end_colum-1])*c[start_row][start_colum];
        int M3=b[start_row][start_colum]*(c[start_row][end_colum-1s]-c[end_colum-1][end_row-1]);
        int M4=b[end_row-1][end_colum-1]*(c[end_row-1][start_colum]-c[start_colum][start_row]);
        int M5=(b[start_row][start_colum]+b[start_row][end_colum-1])*c[end_row-1][end_colum-1];
        int M6=(b[end_row-1][start_colum]-b[start_row][start_row])*(c[start_row][start_colum]+c[start_row][end_colum-1]);
        int M7=(b[start_row][end_colum-1]-b[end_row-1][end_colum-1])*(c[end_row-1][start_colum]+c[end_row-1][end_colum-1]);
        a[start_row][start_colum]=M1+M4-M5 +M7;
        a[start_row][end_colum-1]=M3+M5;
        a[end_row-1][start_colum]=M2+M4;
        a[end_row-1][end_colum-1]=M1-M2+M3+M6;
    }
    else{
        mastress(a, b, c, start_row, n/2, start_colum,n/2, n/2);
        mastress(a, b, c,n/2,end_row, start_colum, n/2, n/2);
        mastress(a, b, c, start_row,n/2, n/2,end_colum, n/2);
        mastress(a, b, c,n/2,end_row, n/2, end_colum, n/2);
    }
}
void cinmatrix (float **a,int n,int m){
    int b;
    for (int i=0; i<n; i++) {
        a[i]=new float(m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b=rand()%100;
            a[i][j]=b;
        }
    }
}
                       
void coutmatrix(float **a,int n,int m){
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    float **a,**b,**sum,**sum1;
    int n1,n2,m1;
    cin>>n1>>n2;
    cin>>m1;
    a=new float*[n1];
    b=new float*[n2];
    sum=new float *[n1];
    sum1=new float *[n1];
    for(int i=0;i<n2;i++){
        sum[i]=new float(m1);
        sum1[i]=new float(m1);
    }
    srand((unsigned int)time(NULL));
    cinmatrix(a,n1,n2);
    cinmatrix(b,n2,m1);
    coutmatrix(a, n1, n2);
    cout<<endl;
    coutmatrix(b, n2, m1);
    mutiplymatrix(sum1, a, b, n1, n2, m1);
    mastress(sum, a, b, 0, n1, 0, n1,n1);
    coutmatrix(sum1, n1, m1);
    cout<<endl;
    coutmatrix(sum, n1, m1);
    return 0;
}
