#include<iostream>
#include <cmath>
using namespace std;
string cut(string m,int s,int e){
string r="";
for(int i=s;i<e;i++){
    r=r+m[i];
}
return r;
}

int hashn(string h){
int r=0;
for(int i=0;i<h.length();i++){
    r=r+((h[i]-26)*pow(26,i));
}
return (r%13);
}
int main(){
string s="fox the quick brown fox jumps over the lazy dog fox";
string p="fox";

int hp=hashn(p);
for(int i=0;i<s.length();i++){
    string temp=cut(s,i,i+p.length());
    if(hashn(temp)==hp && temp==p){
        cout<<"found at: "<<i<<endl;
    }
}

cout<<cut(s,3,7);
}

