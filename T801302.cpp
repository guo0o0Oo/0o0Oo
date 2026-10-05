#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,a[1000010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        char ch;cin>>ch;
        a[i]=ch-'0';
    }
    for(ll i=1;i<=m;i++){
        ll x;cin>>x;
        a[x]=1;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)ans+=a[i];
    cout<<ans<<"\n";
    return 0;
}