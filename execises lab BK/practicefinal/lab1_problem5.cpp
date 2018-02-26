#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int bin2dec(int num){
  int size=0;
  int temp=num;
  if(num==0){
    return 0;
  }
  while(temp/10!=0){
    temp=temp/10;
    size++;
  }

  int pow1=1;
  int sum=1;

  for(int i=0;i<size;i++){
    pow1*=10;
    sum*=2;

  }
  return sum+bin2dec(num%pow1);

}
int main(){
  cout<<bin2dec(1010)<<endl;;
  return 0;
}
