//
//  main.cpp
//  struct
//
//  Created by nguyen tan dung on 7/11/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
struct _coordinate{
    float x,y,z;
    
};

int main(int argc, const char * argv[]) {
    struct _coordinate point_A={1.5f ,2.5f,3.5f},point_B={4.5f,5.5f,6.5f},AB;
    AB.x=point_B.x-point_A.x;
    AB.y=point_B.y-point_A.y;
    AB.z=point_B.z-point_A.z;
    cout<<"("<<AB.x<<","<<AB.y<<","<<AB.z<<")\n";
    return 0;
}
