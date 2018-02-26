#include<iostream>
#include<vector>
using namespace std;
void mulMatrix(vector<vector<double > >  A,vector<vector<double> > B){
  vector<vector<double > > result = vector<vector<double> > (A.size(),vector<double> (B[0].size(),0));
  for(int i=0;i<A.size();i++){
    for(int j=0;j<B[0].size();j++){
      for(int k=0;k<A[0].size();k++){
        result[i][j]+=A[i][k]*B[k][j];
      }
    }
  }
   for(int i=0;i<A.size();i++){
      for(int j=0;j<B[0].size();j++){
        cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(){
  vector<vector<double> > A(3,vector<double> (2,1));
  vector<vector<double> > B(2,vector<double> (3,1));

  mulMatrix(A,B);
  return 0;
}
