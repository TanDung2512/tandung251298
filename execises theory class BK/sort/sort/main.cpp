//
//  main.cpp
//  sort
//
//  Created by nguyen tan dung on 8/23/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//
#include <iostream>
#include <time.h>
#define MAX 100;
using namespace std;
void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void quicksortarray(int *array,int left,int right){
    int l=left;
    int r=right;
    int mid=array[(l+r)/2];
    while(l<=r){
        while(array[l]<mid& l<=r)
            l++;
        while(array[r]>mid & l<=r)
            r--;
        if(l<=r){
            if(l<r)
                swap(array[l],array[r]);
            l++;
            r--;
        }
    }
    cout<<mid<<" "<<l<<" " <<r<<endl;
    for (int i=0;i<20;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    if(l<right){
        quicksortarray(array,l,right);
    }
    if(r>left){
        quicksortarray(array,left,r);
    }
}
void bublesort(int *array,int n){
    for (int i=0; i<n-1; i++) {
        for (int j=n-1; j>i; j--){
            if(array[j]<array[j-1]){
                swap(array[j],array[j-1]);
            }
        }
    }
}
void insertsort(int *array,int n ){
    int tmp;
    int j;
    for (int i=1; i<n; i++) {
        tmp=array[i];
        j=i-1;
        while (j>=0 & tmp<array[j]) {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=tmp;
        for (int i=0;i<20;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

}
void satisfyheap(int *array,int i,int n){
    int   l=2*i;
    int   r=2*i+1;
    int max;
    if (array[l]>array[i] & l<=n) {
        max=l;
    }
    else max=i;
    if(array[r]>array[max] & r<=n){
        max =r;
    }

    if(max!=i){
        swap(array[max],array[i]);
        satisfyheap(array, max, n);
    }
}
void buildheap(int *array,int n ){
    int heapsize=n-1;
    for (int i=n/2; i>=0; i--) {
        satisfyheap(array, i,heapsize);
    }
}
void binarysort(int *array,int n ){
    buildheap(array, n);
    int heapsize;
    heapsize=n-1;
    for (int i=heapsize; i>=0; i--) {
        swap(array[0],array[heapsize]);
        heapsize--;
        satisfyheap(array, 0, heapsize);
    }
    for (int i=0; i<n; i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void mergesort(int *array,int left,int right){
    int mid;
    mid=(left+right)/2;
    while(mid>0){
    mergesort(array,left,mid);
    mergesort(array, mid+1, right);
    }
    int m=mid;
    while(array[left]<array[m+1] & left<=mid & right < mid )
}
int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    int array[20];
    for (int i=0; i<20; i++) {
        array[i]=rand()%200;
    }
    for (int i=0;i<20;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    insertsort(array, 20);
    for (int i=0;i<20;i++){
        cout<<array[i]<<" ";
    }
    
    return 0;
}
