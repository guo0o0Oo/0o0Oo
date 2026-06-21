#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct mouse{
    ll t,x,y;
}ms[10010];
bool ifget(mouse a,mouse b){
    return abs(a.x-b.x)+abs(a.y-b.y)<=abs(a.t-b.t);
}
ll dp[10010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll a,b,c;
    for(ll i=1;i<=m;i++){
        cin>>ms[i].t>>ms[i].x>>ms[i].y;
    }
    for(ll i=m;i>=1;i--){
        ll cnt=0;
        for(ll j=i+1;j<=m;j++){
            if(ifget(ms[i],ms[j]))
            cnt=max(cnt,dp[j]);
        }
        dp[i]=cnt+1;
    }
    ll ans=0;
    for(ll i=1;i<=m;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}