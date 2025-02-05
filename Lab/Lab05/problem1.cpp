#include <iostream>
using namespace std;

int maxCoin(int arr[],int a,int s)
{
    int dp[a+1][s+1];

    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(i==0 || j==0)
            {
                dp[0][j]=0;
                dp[i][0]=1;
            }
            else if(j<arr[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
            }
        }
    }


    return dp[a][s];
}




int main()
{
    int n=3;
    int coin[n]={1,3,5};
    int sum=8;


if(maxCoin(coin,n,sum)==0)
{
    cout<<"NO";
}
else
{
    cout<<"YES";
}

}
