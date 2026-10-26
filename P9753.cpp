#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,pre[2000010],dp[2000010];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>s;
    s=" "+s;
    for(ll i=1;i<=n;i++){
        ll k=i-1;
        while(k>=1){
            if(s[k]==s[i]){
                dp[i]=dp[k-1]+1;
                pre[i]=k;
                break;
            }
            k=pre[k]-1;
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans+=dp[i];
    }
    cout<<ans<<"\n";
    return 0;
}