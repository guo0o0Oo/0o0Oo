#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    char ch;
    ll k=0;
    while(cin>>ch){
        if(ch=='(')k++;
        if(ch==')')k--;
        if(k<0)break;
        if(ch=='@')break;
    }
    if(k==0)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}