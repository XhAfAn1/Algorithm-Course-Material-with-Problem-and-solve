#include<iostream>
#include<algorithm>
using namespace std;

class Obj
{
public:
    int profit;
    int weight;
    float ratio;
    Obj()
    {
    }
    Obj(int p,int w)
    {
        profit=p;
        weight=w;
        ratio=static_cast<float>(p)/w;
    }
};
bool sortObj(Obj a,Obj b){
    return a.ratio>b.ratio;
}


int maxProfit(Obj a[],int w,int n){
int sum=0;
int m=w;
for(int i=0;i<n;i++){
    if(a[i].weight<=m){
        m=m-a[i].weight;
        sum=sum+a[i].profit;
    }
    else{
        sum=sum+(m*a[i].ratio);
        break;
    }
}
return sum;
}

int main()
{
    int n;
    cout<<"how many obj";
    cin>>n;
    Obj *arr=new Obj[n];

    for(int i=0; i<n; i++)
    {
        int a,b;
        cout<<"Enter profit and weight: ";
        cin>>a>>b;
        arr[i]=Obj(a,b);

    }
    int w;
    cout<<"Enter the sack value: ";
    cin>>w;
    sort(arr,arr+n,sortObj);
    cout<<maxProfit(arr,w,n);
   // for(int i=0; i<n; i++){cout<<"profit: "<<arr[i].profit<<"Weight: "<<arr[i].weight<<"ratio: "<<arr[i].ratio<<endl;}

}

