#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,a[100010],b[100010],c[100010],sum[100010],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll now=0;
    while(m--){
        ll p;cin>>p;
        if(now==0){now=p;continue;}
        ll l=min(now,p),r=max(now,p);
        sum[l]++;sum[r]--;
        now=p;
    }
    for(ll i=1;i<n;i++)cin>>a[i]>>b[i]>>c[i];
    for(ll i=1;i<=n;i++)sum[i]+=sum[i-1];
    for(ll i=1;i<=n;i++)ans+=min(sum[i]*a[i],sum[i]*b[i]+c[i]);
    cout<<ans<<"\n";
    return 0;
}