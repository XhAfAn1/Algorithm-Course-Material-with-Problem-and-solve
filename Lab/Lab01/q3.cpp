#include<iostream>

using namespace std;

int partitn(int A[],int l,int h)
{

    int p = A[h];
    int i = l ;
    int j=l;
    while(j<h)
    {

        if (A[j] <= p)
        {

            swap(A[i], A[j]);
            i++;
            j++;
        }
        else
            j++;
    }

    swap(A[i], A[j]);

    return (i);

}
void qsort(int A[],int l,int h)
{

    if (l < h)
    {

        int p = partitn(A, l, h);

        qsort(A, l, p - 1);
        qsort(A, p + 1, h);
    }
}


int main()
{
      int a;
    int arr[100];
     cout<<"Enter the array size: "<<endl;
    cin>>a;

    for(int i=0; i<a; i++)
    {
        cout<<"Enter the value of array:"<<endl;
        cin>>arr[i];
    }
    cout<<"Before sorting:" <<endl;
    cout<<"The array is:"<<endl;

    for(int i=0; i<a; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<" "<<endl;
    qsort(arr,0,a-1);
    cout<<"The sorted array is: "<<endl;
    for(int i=0; i<a; i++)
    {
        cout<<arr[i]<<" ";
    }

}


