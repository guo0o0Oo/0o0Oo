#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,s[200010],t[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>s[i];
    for(ll i=1;i<=n;i++)cin>>t[i];
    ll ans=0,suml=0;
    for(ll i=1;i<=n;i++){
        ans+=abs(s[i]-t[i]);
    }
    for(ll i=1;i<=n;i++){
        if(s[i])
    }
    return 0;
}