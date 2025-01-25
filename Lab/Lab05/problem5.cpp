#include<iostream>
using namespace std;

void LPS(string s){
int n=s.length();
int maxL=0;
int start=0;
int dp[n][n];
for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }

for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){


            if(s[i]==s[j]){
                if(dp[i+1][j-1]==1 || j-i==1){
                    dp[i][j]=1;

                    if(j-i+1>maxL){
                        maxL=j-i+1;
                        start=i;
                    }
                }
            }

        }
    }



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }

    cout<<maxL<<" "<<start<<endl;

    for(int i=0;i<maxL;i++){
        cout<<s[start+i];
    }

}



int main(){

string s="AAAABBAA";;

LPS(s);
}

