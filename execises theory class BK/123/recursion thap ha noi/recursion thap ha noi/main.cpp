//
//  main.cpp
//  recursion thap ha noi
//
//  Created by nguyen tan dung on 9/14/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
void recursion(char start,char destination,char auxilities, int move ){
    if(move==1){
        cout<<"move "<<start<<" to "<<destination <<endl;
    }
    else{
        recursion(start, auxilities, destination, move-1);
        recursion(start,destination,auxilities,1);
        recursion(auxilities, destination, start, move-1);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    recursion('A','C','B', n);
    return 0;
}
