//
//  main.cpp
//  struct_1
//
//  Created by nguyen tan dung on 7/14/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include<string.h>
#define MAX 10
using namespace std;
struct Point3D{
    float x,y,z;
};
typedef struct Point3D Point3D;
int main(int argc, const char * argv[]) {
    Point3D array[MAX]={
        (1.5f,2.5f,3.5f),
        (4.5f,5.5f,6.5f)
    };
    cout<<"size of array= "<<sizeof(array)<<endl;
    array[5].x=10.5f;
    array[5].y=11.5f;
    array[5].z=15.5f;
    cout<<"The item at 5 = "<<"("<<array[5].x<<","<<array[5].y<<","<<array[5].z<<")"<<endl;
    return 0;
}
