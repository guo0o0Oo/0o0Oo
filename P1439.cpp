#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[100010],b[100010],pos[100010],c[100010],low[100010];
ll sch(ll k){
    ll l=0,r=n;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(low[mid]<k)l=mid;
        else r=mid-1;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)cin>>b[i];
    for(ll i=1;i<=n;i++)pos[a[i]]=i;
    for(ll i=1;i<=n;i++)c[i]=pos[b[i]];
    memset(low,0x3f3f3f3f,sizeof(low));
    low[0]=0;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll k=sch(c[i]);
        ans=max(k+1,ans);
        low[k+1]=min(low[k+1],c[i]);
    }
    cout<<ans<<"\n";
    return 0;
}