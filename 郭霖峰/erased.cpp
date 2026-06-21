#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[210],dp[210],cnt[210];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("erased.in","r",stdin);
    freopen("erased.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    a[0]=inf;
    for(ll i=1;i<=n;i++)dp[i]=inf;
    cnt[0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<i;j++){
            if(a[i]>=a[j]){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(dp[i]==dp[j]+1){
                    cnt[i]+=cnt[j];
                }
            }
        }
    }
    ll ans=inf,allcnt=inf;
    for(ll i=1;i<=n;i++){
        if(ans<dp[i]){
            ans=dp[i];
            allcnt=cnt[i];
        }
        else if(ans==dp[i]){
            allcnt+=cnt[i];
        }
    }
    cout<<ans<<" "<<allcnt%1000<<"\n";
    return 0;
}