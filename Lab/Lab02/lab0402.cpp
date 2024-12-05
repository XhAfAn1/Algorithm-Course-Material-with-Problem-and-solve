#include<iostream>
using namespace std;

int minCoinComb(int c[],int ta,int n){
int cnt=0;
int ra=ta;
for(int i=0;i<n;i++){
    while(ra>=c[i]){
       // cout<<(c[i]);
        ra=ra-c[i];
        cnt++;
    }
}
return cnt;
}

main(){
int c[]={9,6,5,1};
int sum=19;
cout<<minCoinComb(c,sum,4);
}
