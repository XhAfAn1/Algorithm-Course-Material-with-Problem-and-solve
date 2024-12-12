
#include<iostream>
#include <algorithm>
using namespace std;

void minLoss( int l[],float r[],int n)
{
    float temp[n];
    for(int i=0;i<n;i++){
        temp[i]=r[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {

            if(r[i]<r[j])
            {
                swap(r[i],r[j]);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {

            if(r[i]==temp[j])
            {
                l[i]=j+1;
            }
        }
    }


}


int main()
{

    int n;
    cout<<"Enter the number of job: ";
    cin>>n;
    int l[n];
    int t[n];

    for(int i=0;i<n;i++){
        cout<<"Enter loss: ";
        cin>>l[i];
        cout<<"Enter day required: ";
        cin>>t[i];
    }

    float r[n];

    for(int i=0;i<n;i++){
        r[i]=(float)(l[i])/t[i];
    }

    minLoss(l,r,n);

    for(int i=0;i<n;i++){
        cout<<l[i]<<" ";
    }

}
