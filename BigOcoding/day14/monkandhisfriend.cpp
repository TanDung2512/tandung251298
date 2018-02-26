
#include<iostream>
#include<set>
using namespace std;
int main(){
    int testcase;
    long long int temp;
    scanf("%d",&testcase);
    while(testcase--){
        set<long long int >binaryset;
        int n;
        int m;
        scanf("%d",&n);
        scanf("%d",&m);
        for(int i=0;i<n;i++){
            scanf("%lld",&temp);
            binaryset.insert(temp);
        }

        for(int i=0;i<m;i++){

            scanf("%lld",&temp);
            if(binaryset.find(temp)==binaryset.end()){
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }

    return 0;
}
