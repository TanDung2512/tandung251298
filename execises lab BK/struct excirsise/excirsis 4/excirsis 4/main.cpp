//
//  main.cpp
//  excirsis 4
//
//  Created by nguyen tan dung on 7/9/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<cmath>
#define MAX_VERT 20
using namespace std;
struct coordinate{
    int x;
    int y;
};
int main(int argc, const char * argv[]) {
    int n;
    float parameter=0;
    srand((unsigned int)time(NULL));
    cout<<"please input n"<<endl;
    cin>>n;
    coordinate vertices[n];

    for (int i=0; i<n; i++) {
        vertices[i].x=rand()%201-100;
        vertices[i].y=rand()%201-100;
        cout<<"vertices "<<i+1<<"("<<vertices[i].x<<","<<vertices[i].y<<")"<<endl;
    }
    cout<<"\n\n\n";
    parameter=sqrt((vertices[0].x-vertices[n-1].x)*(vertices[0].x-vertices[n-1].x)+(vertices[0].y-vertices[n-1].y)*(vertices[0].y-vertices[n-1].y));
    for (int i=0; i<n/2; i++) {
        parameter+=sqrt((vertices[2*i].x-vertices[2*i+1].x)*(vertices[2*i].x-vertices[2*i+1].x)+(vertices[2*i].y-vertices[2*i+1].y)*(vertices[2*i].y-vertices[2*i+1].y));
    }
    cout<<"parameter of poly= "<<parameter<<endl;
    return 0;
}
