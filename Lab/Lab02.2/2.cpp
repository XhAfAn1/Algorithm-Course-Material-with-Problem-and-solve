#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter no of train: ";
    cin >> n;
float arr[n], dep[n];

    cout << "Enter Arrival & Dep: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cin>>dep[i];
    }
    sort(arr,arr+n);
    sort(dep,dep+n);

    int c=0;
    int i=0;
    int j=0;

    while(j<n){
         if(arr[i]>dep[j]){
            c++;
            i++;
        }
        else if(arr[i]<dep[j])
        {
            j++;
            c--;
        }
        else
        {
            i++;
            j++;
        }
    }

cout<<c;

}
