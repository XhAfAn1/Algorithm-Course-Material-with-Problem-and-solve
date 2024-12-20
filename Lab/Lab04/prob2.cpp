#include<iostream>
using namespace std;
int sumofs(int n,int m,int value[]){
     int dp[n+1][m+1];
     for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[0][j]=0;
                dp[i][0]=1;
            }
            else if(value[i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else
                dp[i][j]=dp[i-1][j] || dp[i-1][j-value[i]];
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
int n=5;
int value[]={1,3,5,7,9};
int sum=12;

int t=sumofs(n,sum,value);
if(t==1){
    cout<<"Yes";
}
else
    cout<<"No";

}
