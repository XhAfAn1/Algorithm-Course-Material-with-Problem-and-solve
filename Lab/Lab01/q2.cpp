#include<iostream>

using namespace std;


void Marge(int A[],int m, int l, int h)
{
    int n1=m-l+1;
    int n2=h-m;

    int a[n1];
    int b[n2];

    for(int i=0; i<n1; i++)
    {
        a[i]=A[l+i];
    }

    for(int i=0; i<n2; i++)
    {
        b[i]=A[(m+1)+i];
    }

    int i=0;
    int j=0;
    int s=l;

    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            A[s]=a[i];
            i++;
            s++;
        }
        else
        {
            A[s]=b[j];
            j++;
            s++;
        }

    }
    while(i<n1)
    {
        A[s]=a[i];
        i++;
        s++;
    }
    while(j<n2)
    {
        A[s]=b[j];
        j++;
        s++;
    }

}


void Marge_Sort(int A[],int l,int h)
{

    if(l<h)
    {
        int mid=(h+l)/2;
        Marge_Sort(A,l,mid);
        Marge_Sort(A,mid+1,h);
        Marge(A,mid,l,h);
    }

}
int main()
{
     int a;
    int arr[100];
    cout<<"Enter the array size: "<<endl;
    cin>>a;

    for(int i=0;i<a;i++)
    {
        cout<<"Enter the value of array:"<<endl;
        cin>>arr[i];
    }
    cout<<"Before sorting:" <<endl;
    cout<<"The array is:"<<endl;

    for(int i=0;i<a;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<" "<<endl;

    Marge_Sort(arr,0,a-1);
    cout<<"After sorting: "<<endl;
    cout<<"The array is:"<<endl;
    for(int i=0;i<a;i++)
    {
        cout<<arr[i]<<" ";
    }

}

