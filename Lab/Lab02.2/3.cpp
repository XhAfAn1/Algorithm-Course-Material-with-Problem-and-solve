#include<iostream>
#include <algorithm>
using namespace std;

void sortjobs( char job[],int dl[],int p[],int n)
{

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {

            if(p[i]<p[j])
            {
                swap(p[i],p[j]);
                swap(dl[i],dl[j]);
                swap(job[i],job[j]);
            }
        }
    }

}


int main()
{

    int n;


    cout<<"how many job: ";
    cin>>n;
      char job[n];
    int dl[n];
    int p[n];
    for(int i=0;i<n;i++){
        cout<<"Enter job name:";
        cin>>job[i];
        cout<<"Enter job deadline:";
        cin>>dl[i];
        cout<<"Enter job profit:";
        cin>>p[i];
        cout<<endl;
    }
    sortjobs(job,dl,p,n);
    int t;
    t=*max_element(dl,dl+n);

    char pjob[t];

    for(int i=0; i<t; i++)
    {
        pjob[i]='f';
    }

    int j=0;
    for(int i=0; i<t; i++)
    {
        int temp=dl[j]-1;

        if(pjob[temp]=='f')
        {
            pjob[temp]=job[j];
        }
        else
        {
            while(temp!=0)
            {
                int temp=temp-1;
                if(pjob[temp]=='f')
                {
                    pjob[temp]=job[j];
                }
            }
        }
        j++;
    }

    for(int i=0; i<t; i++)
    {
        if(pjob[i]!='f')
        {
            cout<<pjob[i]<<" ";
        }
    }

}
