#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>s;
    ll ans=0,mx=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='R')mx++;
        else mx=0;
        ans=max(mx,ans);
    }
    cout<<ans<<"\n";
    return 0;
}