#include<iostream>
using namespace std;

void LIS(int s[],int n){
    int dp[n];
    int index[n];
    int maxi=0;
    int maxv=0;

    for(int i=0;i<n;i++){
    dp[i]=1;
    index[i]=-1;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(s[j]<s[i]){

                if(dp[i]<1+dp[j]){
                dp[i]=1+dp[j];
                index[i]=j;

                if(dp[i]>maxv){
                    maxi=i;
                    maxv=dp[i];
                }

                }

            }
        }
    }

    while(maxi>-1){
        cout<<s[maxi]<<" ";
        maxi=index[maxi];
    }

cout<<endl;
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<index[i]<<" ";
    }
    cout<<endl<<maxi;
}


int main(){
int n=6;
int s[n]={5,4,11,1,16,8};

LIS(s,n);

}
