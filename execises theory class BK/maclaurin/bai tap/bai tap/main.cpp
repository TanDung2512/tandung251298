//
//  main.cpp
//  bai tap
//
//  Created by nguyen tan dung on 7/1/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {

    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    int s;
    if ( x2<x3 || x4<x1|| y3>y2 || y1 >y4){
        s=0 ;}
    else{ s=(x2-x3)*(y2-y3);
          s=abs(s);
          cout<<s;}
    
    return 0;
}
