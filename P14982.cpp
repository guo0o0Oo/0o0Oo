#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
const ll MOD=1e9+7;
ll n,d,p[N],o[N],p2[N],dp[N],ans,k,last=1,sum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>d;
    p2[0]=1;
    for(ll i=1;i<=n;i++)p2[i]=(p2[i-1]<<1)%MOD;
    for(ll i=1;i<=n;i++)cin>>p[i]>>o[i];
    for(ll i=1;i<=n;i++){
        while(p[i]-p[last]>d){
            sum=(sum-dp[last]*p2[k]%MOD+MOD)%MOD;
            k-=!o[last];
            last++;
        }
        if(o[i]){
            dp[i]=ans+1;
            ans+=dp[i];
            sum+=dp[i];
        }
        else{
            ans+=sum;
            sum*=2;
            sum%=MOD;
            k++;
        }
        dp[i]%=MOD;
        ans%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}