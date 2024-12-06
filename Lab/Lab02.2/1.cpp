#include<iostream>
using namespace std;


int main(){   int n;
    cout << "Enter no of job: ";
    cin >> n;

    int s[n],f[n];

    for(int i=0;i<n;i++){
            cout << "Enter Start, end: ";
        cin >> s[i];
        cin>>f[i];
    }
    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(f[i]<f[j]){
                temp = f[i];
                f[i] = f[j];
                f[j] = temp;

                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    int c=1;
    int i=0;
    int j=0;
    while(j<n){
        if(s[i]<s[j]){
            c++;
            j=i;
            i++;
        }
        else
            i++;
    }
    cout<<c;

}
