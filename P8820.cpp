#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,q,k,v[200010],dp[200010],s,t;
vector<ll> G[200010];
void solve(ll a,ll b,ll c,ll node){
    dp[node]=dp[c]+v[node];
    if(k>=2&&b!=0)dp[node]=min(dp[node],dp[b]+v[node]);
    if(k>=3&&a!=0)dp[node]=min(dp[node],dp[a]+v[node]);
    for(ll u:G[node]){
        if(u==c)continue;
        solve(b,c,node,u);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q>>k;
    for(ll i=1;i<=n;i++)cin>>v[i];
    for(ll i=1;i<n;i++){
        ll a,b;cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    while(q--){
        ll s,t;
        cin>>s>>t;
        solve(0,0,0,s);
        cout<<dp[t]<<"\n";
    }
    return 0;
}