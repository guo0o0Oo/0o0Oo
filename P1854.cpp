#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,dp[110][110],a[110][110];
string ans[110][110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            dp[i][j]=inf;
        }
    }
    for(ll i=0;i<=m;i++){
        dp[0][i]=0;
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(dp[i-1][j-1]+a[i][j]>dp[i][j-1]){
                dp[i][j]=dp[i-1][j-1]+a[i][j];
                ans[i][j]=ans[i-1][j-1]+" "+to_string(j);
            }
            else{
                dp[i][j]=dp[i][j-1];
                ans[i][j]=ans[i][j-1];
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    cout<<ans[n][m]<<"\n";
    return 0;
}