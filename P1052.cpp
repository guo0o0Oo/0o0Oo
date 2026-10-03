#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll L,s,t,m,p[110],dp[20010],ifr[20010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(ll i=0;i<=20000;i++)dp[i]=inf;
    cin>>L;
    cin>>s>>t>>m;
    for(ll i=1;i<=m;i++)cin>>p[i];
    sort(p+1,p+m+1);
    if(s==t){
        ll ans=0;
        for(ll i=1;i<=m;i++)if(p[i]%s==0)ans++;
        cout<<ans<<"\n";
        return 0;
    }
    ll last=0;
    for(ll i=1;i<=m;i++){
        if(p[i]-p[i-1]>=s*t){
            last+=s*t;
            ifr[last]=1;
        }
        else{
            last+=p[i]-p[i-1];
            ifr[last]=1;
        }
    }
    dp[0]=0;
    for(ll i=1;i<=last+10;i++){
        for(ll j=s;j<=t;j++){
            if(i-j>=0)
                dp[i]=min(dp[i],dp[i-j]+ifr[i]);
        }
    }
    ll ans=inf;
    for(ll i=last;i<=last+10;i++){
        ans=min(dp[i],ans);
    }
    cout<<ans<<"\n";
    return 0;
}