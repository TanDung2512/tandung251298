#include<iostream>
#include<vector>
using namespace std;
int main(){
  string *a[5];
  cout<<sizeof(a)<< " "<<sizeof(*a)<<endl;
  return 0;
}
