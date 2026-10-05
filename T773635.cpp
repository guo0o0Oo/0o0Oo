#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,dp2[1010],dp1[1010];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>s;
    s=" "+s;
    ll ans=0;
    for(ll x=1;x<=n;x++){
        memset(dp2,0,sizeof(dp2));
        memset(dp1,0,sizeof(dp1));
        for(ll i=1;i<=n;i++)
            if(s[i]=='X'&&i-2*x>=1&&s[i-2*x]=='X')
                dp2[i]=dp2[i-2*x]+1;
        for(ll i=n;i>=1;i--)
            if(s[i]=='X'&&i+x<=n&&s[i+x]=='X')
                dp1[i]=dp1[i+x]+1;
        for(ll i=1;i<=n;i++)
            if(dp1[i])
                ans=max(ans,dp1[i]+dp2[i]+1);
    }
    cout<<ans<<"\n";
    return 0;
}