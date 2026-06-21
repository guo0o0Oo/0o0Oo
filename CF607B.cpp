#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[510],dp[510][510];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            dp[i][j]=sup;
    for(ll i=1;i<=n;i++)dp[i][i]=1;
    for(ll len=2;len<=n;len++){
        for(ll i=1;i<=n-len+1;i++){
            ll j=i+len-1;
            if(a[i]==a[j]){
                if(len==2)dp[i][j]=1;
                else dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            }
            for(ll k=i;k<j;k++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    cout<<dp[1][n]<<"\n";
    return 0;
}