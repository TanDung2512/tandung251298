#include<iostream>
using namespace std;
class point {
public:
  int x;
  int y;
public:
  point(){
    this->x=0;
    this->y=0;
    cout<<1<<endl;
  }
  point(int x,int y){
    this->x=x;
    this->y=y;
    cout<<2<<endl;
  }
};
class circle :public point{
public:
  circle(){
    cout<<x<<" "<<y<<endl;
    cout<<3<<endl;
    point(3,2);
  }
};
int main(){
  circle x;
  cout<<x.x<<" "<<x.y;
  return 0;
}
