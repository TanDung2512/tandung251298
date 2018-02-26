//
//  main.cpp
//  object-oriented
//
//  Created by nguyen tan dung on 7/29/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//
#include <iostream>
#include <iomanip>
using namespace std;
class A{
private:
    int m_value;
public:
    A() : m_value(123){
        cout << "In A(), value = " << m_value << endl;
    }
    A(const A& ob) : m_value(ob.m_value){
    cout << "In A(const A& ob), value = " << m_value << endl;
    }
    A(int value) : m_value(value){
            cout << "In A(int value), value = " << m_value << endl;
    }
    ~A(){
        cout << "In ~A(), value = " << m_value << endl;
    }
};
int main(){
    A ob1;
    A *ptr1 = new A(246);
    {
        A ob2(456);
        A ob3(ob1);
    }
    delete ptr1;
    A ob4(789);
    A ob5=357;
    return 0;
}

