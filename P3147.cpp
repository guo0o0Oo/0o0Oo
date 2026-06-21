#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[300000],dp[2][300000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    ll ans=1,old=0,now=1;
    for(ll i=1;i<=59;i++){
        swap(old,now);
        memset(dp[now],0,sizeof(dp[now]));
        for(ll j=1;j<=n;j++){
            if(a[j]==i)dp[now][j]=j+1;
            if(!dp[now][j]){
                dp[now][j]=dp[old][dp[old][j]];
            }
            if(dp[now][j])ans=i;
        }
    }
    cout<<ans<<"\n";
    return 0;
}