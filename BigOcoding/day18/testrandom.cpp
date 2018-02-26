#include<iostream>
#include<time.h>
using namespace std;
int main(){
  srand(time(NULL));
  cout<<5000<<endl;

  for(int i=0;i<5000;i++){
    cout<<rand()%9999999999<<endl;
  }
  return 0;
}
