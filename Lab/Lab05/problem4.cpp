#include <iostream>
using namespace std;

void comSubString(string a,string b)
{
int max=0;
int maxi;
int maxj;
    int dp[a.length()+1][b.length()+1];

    for(int i=0;i<=a.length();i++)
    {
        for(int j=0;j<=b.length();j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;

            }
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;

                if(max<dp[i][j])
                {
                max=dp[i][j];
                maxi=i;
                maxj=j;
                }
            }
            else
            {
                dp[i][j]=0;
            }

        }
    }
     for(int i=0; i<=a.length(); i++)
    {
        for(int j=0; j<=b.length(); j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    int x=max;
  cout<<x;
  cout<<endl;

char arr[x];
int y=0;
while(maxi>0)
{
    arr[y]=a[maxi-1];
    y++;
    maxi--;
}
for(int i=x-1;i>=0;i--)
{
    cout<<arr[i];
}





}










int main()
{
    string m;
    cin>>m;
    string n;
    cin>>n;

       comSubString(m,n);
}
