#include <iostream>
using namespace std;

struct vest{
    int soldiers;
    int vestsoldiers;
};
int main(int argc, const char * argv[]) {
    long x,y;
    int m,n;
    cin>>n>>m>>x>>y;
    long *soldiersarray=new long [n];
    long *availablearray=new long [m];
    struct vest *output =new struct vest [m];
    for(int i=0;i<n;i++){
        cin>>soldiersarray[i];
    }
    int pointer=0;
    long numsoldier =0;
    long count=0;
    for(int i=0;i<m;i++){
        cin>>availablearray[i];
    }
    int i=0;
    while(i<m && pointer<n){
        if(soldiersarray[pointer]-x > availablearray[i]){
            //            cout<<" availablearray[i] "<<availablearray[i]<<i<<endl;
            i++;
        }
        else if(availablearray[i]>soldiersarray[pointer]+y){
            pointer++;
        }
        else{
                output[count].soldiers=pointer+1;
                output[count].vestsoldiers=i+1;
                count++;
                i++;
                pointer++;
                numsoldier++;
            }
    }
    
    
    
    cout<<numsoldier<<endl;
    for(int i=0;i<numsoldier;i++){
        cout<<output[i].soldiers<<" "<<output[i].vestsoldiers<<endl;
    }
    return 0;
}
