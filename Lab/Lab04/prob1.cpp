#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int maxProfit(int p[],int wt[],int n,int m){
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(wt[i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else
                dp[i][j]=max(dp[i-1][j],(dp[i-1][j-wt[i]]+p[i]));
        }

    }
     for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }



return dp[n][m];
}

int main(){
int n=4;

int p[n]={3,4,5,6};
int wt[n]={2,3,4,5};
int m=8;

cout<<maxProfit(p,wt,n,m);

}
