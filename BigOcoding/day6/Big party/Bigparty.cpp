#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void inputdancingCouple(vector< vector< int> > &dancingCouple){
  int temp,temp1;
  for(int i=0;i<dancingCouple.size();i++){
    cin>>temp>>temp1;
    dancingCouple[temp].push_back(temp1);
    dancingCouple[temp1].push_back(temp);
  }
}
void output(vector< vector< int> > &dancingCouple){
  for(int i=0;i<dancingCouple.size();i++){
    cout<<"coutple "<<i<< " : ";
    for(int j=0;j<dancingCouple[i].size();j++){
      cout<< dancingCouple[i][j]<<"  ";
    }
    cout<<endl;
  }
}
int main(){
  int numPeople, numCoupleDance;
  cin >> numPeople>>numCoupleDance;
  vector<vector < int > > dancingCouple(numPeople);
  inputdancingCouple(dancingCouple);
  output(dancingCouple);

  return 0;
}
