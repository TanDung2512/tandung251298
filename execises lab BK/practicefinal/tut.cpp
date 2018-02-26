#include<iostream>
#include<vector>
using namespace std;
int main(){
  int a=2,b=3,c=4;
  int *arr[3]={&a,&b,&c};
  cout<<*arr[arr[2][0]-*arr[1]];
  return 0;
}
