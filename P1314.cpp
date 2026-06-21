#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,s,w[200010],v[200010],l[200010],r[200010],cnt[200010],sum[200010],ans=sup;
bool check(ll p){
    for(ll i=1;i<=n;i++)cnt[i]=(w[i]>=p)+cnt[i-1];
    for(ll i=1;i<=n;i++)sum[i]=(w[i]>=p?v[i]:0)+sum[i-1];
    ll res=0;
    for(ll i=1;i<=m;i++)res+=(cnt[r[i]]-cnt[l[i]-1])*(sum[r[i]]-sum[l[i]-1]);
    ans=min(abs(res-s),ans);
    return res>=s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(ll i=1;i<=n;i++)cin>>w[i]>>v[i];
    for(ll i=1;i<=m;i++)cin>>l[i]>>r[i];
    ll l1=0,r1=1000010;
    while(l1<r1){
        ll mid=(l1+r1+1)>>1;
        if(check(mid))l1=mid;
        else r1=mid-1;
    }
    if(l1!=0)check(l1-1);
    cout<<ans<<"\n";
    return 0;
}