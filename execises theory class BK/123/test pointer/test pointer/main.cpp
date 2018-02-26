//
//  main.cpp
//  test pointer
//
//  Created by nguyen tan dung on 9/22/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int *pointer =new int ();
    *pointer=2;
    int *pointer1=new int();
    pointer1=pointer;
    cout<<"address= "<<pointer<<"value of pointer= "<<*pointer<<endl;
    cout<<"address= "<<pointer1<<"value of pointer= "<<*pointer1<<endl;
    delete pointer;
    
    cout<<"address= "<<pointer<<"value of pointer= "<<*pointer<<endl;
    cout<<"address= "<<pointer1<<"value of pointer= "<<*pointer1<<endl;
    return 0;
}
