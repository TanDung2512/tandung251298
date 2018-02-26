#include<iostream>
#include<vector>
using namespace std;
struct FastFood{
  string foodname;
  string foodID;
  float cost;
  float deliciousness;
};

void aa(struct FastFood (*array1){
  cout<<sizeof(*array1)<<endl;
  cout<<sizeof(array1)<<endl;
  int n=sizeof(array1)/(sizeof(array1[0]));
  cout<<n;
}

int main(){
  struct FastFood array[5];
  cout<<sizeof(*array)<<endl;
  cout<<sizeof(array)<<endl;
  aa(array);

  return 0;
}
