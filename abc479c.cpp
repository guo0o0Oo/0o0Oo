#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,w,a[30],b[30];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>w;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    ll ans=0;
    for(ll i=0;i<(1ll<<n);i++){
        ll nw=0,nans=0;
        for(ll j=0;j<n;j++){
            if(i&(1<<j))nw+=b[j+1],nans+=a[j+1];
        }
        if(nw>w)continue;
        ans=max(ans,nans);
    }
    cout<<ans<<"\n";
    return 0;
}