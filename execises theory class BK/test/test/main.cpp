//
//  main.cpp
//  test
//
//  Created by nguyen tan dung on 10/2/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(int argc, const char * argv[]) {
    string input="4x^2";
    stringstream ss;
    ss<<input[0];
    float x;
    ss>>x;
    cout<<x;
    return 0;
}
