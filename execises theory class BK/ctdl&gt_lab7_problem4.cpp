#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
long long hash1(long long k){
  long long temp=k;
  long long count=0;
  long long size=1;
  while(temp/10!=0){
    temp/=10;
    size++;
  }
  temp=k;
  long long sum=0;
  while(temp%((long long)pow(10,size))!=0){
    long long temp1;
    size--;
    sum+=(long long)(7*pow((temp/(long long)(pow(10,size))),count));
    sum%=7719;
    temp%=(long long)pow(10,size);
    count++;
  }
  return sum;
}
long long hash2(long long k){
  long long temp=k;
  long long count=0;
  long long size=1;
  while(temp/10!=0){
    temp/=10;
    size++;
  }
  temp=k;
  long long sum=0;
  while(temp%((long long)pow(10,size))!=0){
    long long temp1;
    size--;

    sum+=(7*pow((temp/(long long)(pow(10,size))),(temp/(long long)(pow(10,size)))));
    sum%=7719;
  //  cout<<temp1<<endl;

    temp%=(long long)pow(10,size);
    count++;
  }
  return sum;
}
long long hash3(long long k){
  long long temp=k;
  long long size=1;
  while(temp/10!=0){
    temp/=10;
    size++;
  }
  temp=k;
  if(size>=3){
    temp%=1000;
    long long a=temp/100;
    temp%=100;
    long long b=temp/10;
    temp%=10;
    long long c=temp;
    return c*100+b*10+a;
  }
  else {
    if(size==2){
      long long a=temp/10;
      temp%=10;
      long long b=temp;
      return b*100+a*10;
    }
    else{
      return temp*100;
    }
  }

}
long long hash4(long long k){
  long long size=1;
  long long temp=k;
  while(temp/10!=0){
    temp/=10;
    size++;
  }
  temp=k;
  long long a=0;
  int count=0;
  while(size>0 && count<=3){
    count++;
    a+=k%1000;
    a%=1000;
    k/=1000;
    size-=3;
  }
  return a;
}
int main(){
  cout<<"#"<<hash1(999999999999999)<<endl;
  cout<<hash2(999999999999999)<<endl;
  cout<<hash3(12)<<endl;
  cout<<"@@"<<hash3(310)<<endl;
  cout<<hash3(325146)<<endl;
  cout<<hash4(325)<<endl;
  cout<<hash4(123456789)<<endl;
  return 0;
}
