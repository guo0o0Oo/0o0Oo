#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll t,m,dp[1010],v[110],w[110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t>>m;
    for(ll i=1;i<=m;i++)cin>>w[i]>>v[i];
    for(ll i=1;i<=m;i++)
        for(ll j=t;j>=0;j--)
            if(j>=w[i])dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    cout<<dp[t]<<"\n";
    return 0;
}