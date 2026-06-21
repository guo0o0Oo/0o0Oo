#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
ll lo[110],sh[110],dp[1010][110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>m>>n;
    for(ll i=1;i<=m;i++){
        cin>>sh[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>lo[i];
    }
    dp[0][1]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            for(ll k=1;k<=m;k++){
                dp[i][j]+=dp[i-1][k]*lo[k]*sh[j]+dp[i-1][k]*sh[k]*lo[j]+dp[i-1][k]*sh[k]*sh[j];
                dp[i][j]%=MOD;
            }
        }
    }
    ll ans=0;
    for(ll i=1;i<=m;i++){
        ans+=dp[n][i];
        ans%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}