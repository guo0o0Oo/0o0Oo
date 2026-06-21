#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
const int ADD=20000;
ll h[1010],dp[1010][40100];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>h[i];
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans++;
        for(ll j=1;j<i;j++){
            dp[i][h[i]-h[j]+ADD]+=dp[j][h[i]-h[j]+ADD]+1;
            dp[i][h[i]-h[j]+ADD]%=MOD;
            ans+=dp[j][h[i]-h[j]+ADD]+1;
            ans%=MOD;
        }
        ans%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}