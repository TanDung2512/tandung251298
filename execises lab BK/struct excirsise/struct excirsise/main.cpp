//
//  main.cpp
//  struct excirsise
//
//  Created by nguyen tan dung on 7/8/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
#include <cmath>
#include<string>
#include<sstream>
using namespace std;

struct vector{
    float dimension[50];
    float length;
};
int main(int argc, const char * argv[]) {
    struct vector vector_1,vector_2;
    string str_1,str_2,w;
    int length_1,length_2;
    float dot_product=0;
    float alpha,length_projection;
    vector cross_product;
    
 
    getline(cin,str_1);
    getline(cin,str_2);
    stringstream ss(str_1);
        
    for (length_1=0; ss>>w;length_1++);
    ss.clear();
    ss.str(str_1);
        
    for(int k=0;k<length_1;k++){
                  cout<<vector_1.dimension[i];
 
    }


        }
    ss.clear();
    ss.str(str_2);
    for (length_2=0; ss>>w;length_2++);
    ss.clear();
    ss.str(str_2);
        
    for(int i=0;i<length_2;i++){
        ss>>vector_2.dimension[i];
        }
    for(int i=0;i<length_2;i++){
            cout<<vector_2.dimension[i]<<" ";
        }
    }while(length_1 != length_2);
    vector_1.length=0;
    vector_2.length=0;
    for (int i=0; i<length_2; i++) {
        vector_1.length+=vector_1.dimension[i]*vector_1.dimension[i];
        vector_2.length+=vector_2.dimension[i]*vector_2.dimension[i];
    }
        
    cout<<"\nThe length of the first vector= "<<sqrt(vector_1.length)<<"\n";
    cout<<"The length of the second vector= "<<sqrt(vector_2.length)<<"\n";
        
    for (int i=0; i<length_2; i++) {
        dot_product+=vector_1.dimension[i]*vector_2.dimension[i];
    }
        
        cout<<"dot product of 2 vector = "<<dot_product<<endl;
        
    if(length_2==3){
        cross_product.dimension[0]=vector_1.dimension[1]*vector_2.dimension[2]-vector_1.dimension[2]*vector_2.dimension[1];
        cross_product.dimension[1]=-(vector_1.dimension[0]*vector_2.dimension[2]-vector_1.dimension[2]*vector_2.dimension[0]);
        cross_product.dimension[2]=vector_1.dimension[0]*vector_2.dimension[1]-vector_1.dimension[1]*vector_2.dimension[0];
        cout<<"cross product of 2 vector= "<<cross_product.dimension[0]<<"i "<<cross_product.dimension[1]<<"j "<<cross_product.dimension[2]<<"k"<<endl;
    }
    dot_product=abs(dot_product);
    alpha=dot_product/(vector_1.length*vector_2.length);
    cout<<"the angle between a and b= "<< alpha<<endl;
    length_projection=dot_product/vector_1.length;
    return 0;
}
