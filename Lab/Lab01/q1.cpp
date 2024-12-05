#include<iostream>

using namespace std;


int binary_search(int A[],int p,int q,int x)
{
    int mid=(p+q)/2;

    if(A[mid]==x)
    {
        return mid;
    }
    else
    {
        if(x>A[mid])
        {
            return binary_search(A,mid+1,q,x);
        }
        else
        {
            return binary_search(A,q,mid-1,x);
        }
    }

}


int main()
{
    int A[]= {1,2,3,4,5,6,7,8};

    cout<<"The position is: "<< binary_search(A,0,7,6);
}
