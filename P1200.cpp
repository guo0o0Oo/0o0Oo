#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s1,s2;
    ll a1=1,a2=1;
    cin>>s1>>s2;
    for(ll i=0;i<s1.size();i++)a1*=(s1[i]-'A'+1),a1%=47;
    for(ll i=0;i<s2.size();i++)a2*=(s2[i]-'A'+1),a2%=47;
    if(a1==a2)cout<<"GO";
    else cout<<"STAY";
    return 0;
}