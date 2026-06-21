#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll l,s,t,m,a[110],dp[110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>l>>s>>t>>m;
    for(ll i=1;i<=m;i++)cin>>a[i];
    for(ll i=1;i<=m;i++)dp[i]=sup;
    dp[0]=0;
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<i;j++){
            if(a[i]-a[j]>=s&&a[i]-a[j]<=t){
                dp[i]=min(dp[j]+1,dp[i]);
            }
        }
    }
    for(ll i=0;i<=m;i++)cerr<<dp[i]<<" ";
    ll ans=sup;
    for(ll i=0;i<=m;i++){
        if(l-a[i]<=t){
            ans=min(dp[i],ans);
        }
    }
    cout<<ans<<"\n";
    return 0;
}