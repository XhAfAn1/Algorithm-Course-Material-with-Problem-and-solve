#include<iostream>
using namespace std;

int main(){
string s="fox The quick brown fox jumps over the lazy dog fox";
string p="fox";

for(int i=0;i<s.length();i++){
    int z=0;
    for(int j=0;j<p.length();j++){
        if(s[i+j]!=p[j]){
            break;
        }
        else
            z++;
    }
    if(z==p.length()){
        cout<<"pattern found in: "<<i<<endl;
    }
}
}
