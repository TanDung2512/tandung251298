//
//  main.cpp
//  assignment KTLT 1
//
//  Created by nguyen tan dung on 7/13/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//
#include <fstream>
#include <iostream>
#include<iomanip>
#include<string>
#include <sstream>
#include <math.h>
using namespace std;
struct points {
    float x,t;
};
struct gradient_vector{
    long double a,b;
}gradient;
typedef struct gradient_vector gradient_vector ;
typedef struct points points;
//declare variable
points point[20000];

int num_iterations,start_a,start_b,num_folds;
float learning_rate;
int number_points=0;
float a,b,a0,b0;              //declare a,b
double average_prediction_error=0;
double histogram_error=0;
double variance=0;
float v_max,v_min;                  //declare upper bound and lower bound

//function take value from txt
void taken();
void fgradient_vector(int N,points TRN[],gradient_vector &gradient);
void parameter(int N,points TRN[]);
void average_prediction(int D,points TST[]);
void histogram_variance(int D,points TST[],float error[]);
void lower_upper_bound ();
void newly_found(int D,float sub_interval[],float array_10element[],float error[]);


int main(){
    taken() ;
    int D,N;
    N=number_points-number_points/num_folds;                        //N
    D=number_points/num_folds;                                      //D
    
    float sub_interval[11];                                                 //declare array subinterval
    float  array_10element [10];                                //declare array of 10 elements to represent the histogram
    
    
    
    int j_1=0,check,check_1,j=0;
    // TST
    for (int i=0; i<num_folds; i++) {
        if(i<num_folds-1){
            points TST[D],TRN[number_points-D];
            // cout<<sizeof(TST)/sizeof(TST[0])<<" "<<sizeof(TRN)/sizeof(TRN[10]);
            
            for (int k=0; k<D; k++) {
                TST[k].x=point[j_1].x;                             // for each loops TST has a value from collection
                TST[k].t=point[j_1].t;
                j_1++;
            }
            
            check=i*(D);
            check_1=0;
            for (int k=0; k<(number_points-D); k++) {
                if(check_1==check){
                    check_1+=D;
                }
                TRN[k].x=point[check_1].x;                             //for each loops TRN has a value from points[2000]. if check_1 == check so chec_1 + D
                TRN[k].t=point[check_1].t;
                check_1++;
            }
            float error[D];
            parameter(N,TRN);                             //    call parameter
            average_prediction(D,TST);                      //call average_prediction function
            histogram_variance(D,TST,error);                      //call function to calculate histogram and variance
            lower_upper_bound ();
            newly_found(D,sub_interval,array_10element,error);
            
        }
        if (i==num_folds-1) {                                                                   //when  i=num_folds-1
            points TST[number_points-D*(num_folds-1)],TRN[number_points-(number_points-D*(num_folds-1))];
            // cout<<sizeof(TST)/sizeof(TST[0])<<" "<<sizeof(TRN)/sizeof(TRN[10]);
            int q=0;
            for ( j=D*(num_folds-1);j<number_points;j++){
                TST[q].x=point[j].x;
                TST[q].t=point[j].t;
                q++;
            }
            for (int j=0; j<D*(num_folds-1); j++) {
                TRN[j].x=point[j].x;
                TRN[j].t=point[j].t;
            }
            D=number_points-D*(num_folds-1);
            N=number_points-D;
            float error[D];
            parameter(N,TRN);                             //    call parameter
            average_prediction(D,TST);                      //call average_prediction function
            histogram_variance(D,TST,error);                      //call function to calculate histogram and variance
            lower_upper_bound ();
            newly_found(D,sub_interval,array_10element,error);        }
    }
    return 0;
}



//function take value from txt
void taken(){
    string str,str_1;
    for (int i=0; i<3; i++) {       // 3 firstline int txt
        getline(cin,str);
    }
    //get number traning and validation parameter
    getline(cin,str);
    stringstream ss(str);
    ss>>str_1>>num_iterations;
    ss.clear();
    
    getline(cin,str);
    ss.str(str);
    ss>>str_1>>learning_rate;
    ss.clear();
    
    getline(cin,str);
    ss.str(str);
    ss>>str_1>>start_a;
    ss.clear();
    
    getline(cin,str);
    ss.str(str);
    ss>>str_1>>start_b;
    ss.clear();
    
    getline(cin,str);
    ss.str(str);
    cout<<str<<endl;
    ss>>str_1>>num_folds;
    ss.clear();
    
    
    
    getline(cin,str);         // take over 3 line ----------
    getline(cin,str);
    getline(cin,str);
    
    // take points from txt and assign array
    while (getline(cin,str)) {
        ss.str(str);
        ss>>point[number_points].x>>point[number_points].t;
        ss.clear();
        number_points++;
    }
}


void fgradient_vector(int N,points TRN[],gradient_vector &gradient){
    long double length;
    gradient.a=0;
    gradient.b=0;
    for (int i=0; i<N; i++) {
        gradient.a+= (a0*TRN[i].x+b0-TRN[i].t)*TRN[i].x;              //calculate gradient vector
        gradient.b+= (a0*TRN[i].x+b0-TRN[i].t);
    }
    length=sqrt(gradient.a*gradient.a+gradient.b*gradient.b);
    gradient.a=gradient.a/length;                                   //normalize vector gradient
    gradient.b=gradient.b/length;
}

// function parameter find a,b
void parameter(int N,points TRN[]){
    a0=start_a;
    b0=start_b;
    for (int k=1; k<=num_iterations; k++) {
        fgradient_vector(N,TRN,gradient) ;
        a=a0 - learning_rate*gradient.a;                                            //parameter (a b )
        b=b0 - learning_rate*gradient.b;
        a0=a;
        b0=b;
    }
    cout<<fixed<<right<<setprecision(5)<<setw(10)<<a<<fixed<<right<<setprecision(5)<<setw(10)<<b;
}
void average_prediction(int D,points TST[]){
    average_prediction_error=0;
    for (int k=0; k<D; k++) {
        average_prediction_error+=((a*TST[k].x+b-TST[k].t)*(a*TST[k].x+b-TST[k].t));
    }
    average_prediction_error=(average_prediction_error/D);                              //error prediction
    average_prediction_error=sqrt(average_prediction_error);
    cout<<fixed<<right<<setw(10)<<setprecision(5)<<average_prediction_error;
}


void histogram_variance(int D,points TST[],float error[]){
    histogram_error=0;
    variance=0;
    for (int k=0; k<D ; k++) {
        error[k]=a*TST[k].x+b-TST[k].t;                                     //assign array ei
        histogram_error+=(error[k]);
    }
    histogram_error/=D;
    //      cout<<histogram_error<<" ";
    for (int k=0; k<D ; k++) {                                                                      //histogram error and variance
        variance+=((a*TST[k].x+b-TST[k].t)-histogram_error)*((a*TST[k].x+b-TST[k].t)-histogram_error);
    }
    variance/=D;
    variance=sqrt(variance);
    //     cout<<variance<<" ";
    
}

void lower_upper_bound (){
    v_min=histogram_error-3*variance;
    v_max=histogram_error+3*variance;
    //       cout<<v_max<<" "<<v_min<<" ";
}


void newly_found(int D,float sub_interval[],float array_10element[],float error[]){
    float delta ;
    int count=0;
    int sum=0;
    delta=(v_max-v_min)/10;
    sub_interval[0]=v_min;
    for (int i=1; i<11; i++) {
        sub_interval[i]=sub_interval[i-1]+delta;
    }
    //    for (int i=0; i<11; i++) {
    //        cout<<sub_interval[i]<<" ";
    //    }
    for (int i=0; i<10; i++) {
        if(i<9){
            for (int k=0; k<D; k++) {
                if(error[k]>=sub_interval[i] && error[k]<sub_interval[i+1]){
                    count+=1;}
            }
            array_10element[i]=count;
            sum+=count;
            count=0;
        }
        else if(i==9){
            for (int k=0; k<D; k++) {
                if(error[k]>=sub_interval[i] && error[k]<=sub_interval[i+1]){
                    count+=1;}
            }
            array_10element[i]=count;
            sum+=count;
            count=0;
        }
    }
    for (int i=0; i<10; i++) {
        array_10element[i]/=sum;
    }
    for (int i=0; i<10; i++) {
        cout<<fixed<<setw(10)<<setprecision(5)<<right<<array_10element[i];
    }
    cout<<endl;
    
}


