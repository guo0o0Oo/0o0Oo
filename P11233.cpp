#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,lst[1000010],v[1000010],to[1000010],dp[1000010],a[1000010];
ll ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(ll i=1;i<=1000000;i++)lst[i]=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==a[i-1])ans+=a[i];
        }
        n=unique(a+1,a+n+1)-(a+1);
        for(ll i=1;i<=n;i++){
            to[i-1]=lst[a[i]];
            lst[a[i]]=i;
            v[i-1]=a[to[i-1]];
        }
        ll cnt=0;
        for(ll i=1;i<=n;i++){
            dp[i]=max(dp[i-1],dp[to[i-1]+1]+v[i-1]);
        }
        cout<<dp[n]+ans<<"\n";
    }
    return 0;
}