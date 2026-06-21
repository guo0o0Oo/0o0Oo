#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll D=4e5;
const ll N=410;
ll n,a[N],b[N],dp[2][800010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i]>>b[i];
    ll old=0,now=1;
    for(ll i=-400000;i<=400000;i++)dp[now][i+D]=inf;
    dp[now][400000]=0;
    for(ll i=1;i<=n;i++){
        swap(old,now);
        for(ll j=-400000;j<=400000;j++)dp[now][i+D]=inf;
        for(ll j=-400000;j<=400000;j++){
            if(j-a[i]+D>=0&&j-a[i]+D<=800000)dp[now][j+D]=max(dp[old][j-a[i]+D]+b[i],dp[old][j+D]);
            else dp[now][j+D]=dp[old][j+D];
        }
    }
    ll ans=inf;
    for(ll i=0;i<=400000;i++){
        if(dp[now][i+D]>=0)ans=max(ans,i+dp[now][i+D]);
    }
    cout<<ans<<"\n";
    return 0;
}