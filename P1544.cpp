#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,t,a[110][110],dp[110][110][110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>t;
    t=min(t,n);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<=n+1;i++)
        for(ll j=0;j<=i+1;j++)
            for(ll k=0;k<=t;k++)
                dp[i][j][k]=-0x3f3f3f3f3f3f3f3f;
    dp[0][0][0]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++){
            for(ll k=0;k<=t;k++){
                dp[i][j][k]=max(dp[i-1][j][k]+a[i][j],dp[i][j][k]);
                dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][j],dp[i][j][k]);
                if(k>0)dp[i][j][k]=max(dp[i-1][j][k-1]+3*a[i][j],dp[i][j][k]);
                if(k>0)dp[i][j][k]=max(dp[i-1][j-1][k-1]+3*a[i][j],dp[i][j][k]);
            }
        }
    }
    ll ans=-0x3f3f3f3f3f3f3f3f;
    for(ll i=1;i<=n;i++){\
        for(ll j=0;j<=t;j++)
        ans=max(dp[n][i][j],ans);
    }
    cout<<ans<<"\n";
    return 0;
}