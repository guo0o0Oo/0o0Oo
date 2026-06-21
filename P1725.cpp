#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[200010],dp[200010];
priority_queue< pair<ll,ll> > pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,l,r;
    cin>>n>>l>>r;
    dp[0]=0;
    for(ll i=1;i<=n;i++)dp[i]=-0x3f3f3f3f;
    for(ll i=0;i<=n;i++)cin>>a[i];
    for(ll i=l;i<=n;i++){
        while(!pq.empty()&&pq.top().second<i-r)pq.pop();
        pq.push({dp[i-l],i-l});
        if(pq.top().first!=-0x3f3f3f3f)dp[i]=a[i]+pq.top().first;
    }
    ll ans=-0x3f3f3f3f;
    for(ll i=n-r+1;i<=n;i++)ans=max(ans,dp[i]);
    cout<<ans<<"\n";
    return 0;
}