#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#define epsilon 0.00001
#define PI 1.0
using namespace std;
double p,q,r,s,t,u;
double calculate(double mid){
  return p*exp(-mid) + q*sin(mid*PI)+r*cos(mid*PI)+s*tan(mid*PI)+t*mid*mid+u;
}
int main(){
  while(cin>>p){
    cin>>q>>r>>s>>t>>u;
  double a,b;
  a=0;
  b=1;
  double mid ;
  double a1,a2,a3;
  a1=calculate(a);
  a2=calculate(b);
  if (a1==0){
    cout<<fixed<<setprecision(4)<<a<<endl;
    continue;
  }
  if(a2==0){
    cout<<fixed<<setprecision(4)<<b<<endl;
    continue;
  }
  double pre=10000;
  while(1){
    mid=(a+b)*0.5;
    a3= calculate(mid);
    if(fabs(a3-pre)<=epsilon){
      cout<<fixed<<setprecision(4)<<mid<<endl;
      break;
    }
    if((a3>0 && a1>0 && a2>0) || (a3<0 && a1<0 && a2<0)){
      cout<<"No solution"<<endl;
      break;
    }
    else if((a3>0 && a1>0) || (a3<0 && a1<0)){
      a=mid;
      pre=a3;
      a1=a3;
    }
    else if((a3>0 && a2>0)|| (a3<0 && a2<0)){
      b=mid;
      pre=a3;
      a2=a3;
    }
  }
}
  return 0;
}
