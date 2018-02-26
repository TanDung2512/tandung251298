#include <iostream>

using namespace std;


void change1(int *x){
    
    *x = 100;
    
}
void change2(int *x){
    
    *x = 100;
}

int main(){
    
    int *a = new int(9);
    
    cout << "before: " << "a = " << *a << endl;
    
    change1(a);
    
    change2(a);
    
    cout << "after: " << "a = " << *a << endl;
    delete a;
    return 0;
    
}
