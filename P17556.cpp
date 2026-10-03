#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
ll n,dp[10010][3];//0->相等,1->更小,2->更大
string k,a[2010];
ll cmp(ll i){
    for(ll j=0;j<a[i].size();j++){
        if(a[i][j]<k[j])return 1;
        if(a[i][j]>k[j])return 2;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i];
    dp[0][0]=1;
    for(ll i=0;i<=k.size();i++){
        ll len=i+1;
        for(ll j=1;j<=n;j++){
            if(a[j].size()<=len){
                ll op=cmp(j),now=len-a[j].size();
                if(op==0){
                    dp[len][0]+=dp[now][0];
                    dp[len][1]+=dp[now][1];
                    dp[len][2]+=dp[now][2];
                }
                else if(op==1){
                    dp[len][1]+=dp[now][0]+dp[now][1]+dp[now][2];
                }
                else if(op==2){
                    dp[len][2]+=dp[now][0]+dp[now][1]+dp[now][2];
                }
                dp[len][0]%=MOD;
                dp[len][1]%=MOD;
                dp[len][2]%=MOD;
            }
        }
    }
    ll ans=0;
    for(ll i=1;i<k.size();i++){
        ans+=dp[i][0]+dp[i][1]+dp[i][2];
        ans%=MOD;
    }
    ans=(ans+dp[k.size()][1])%MOD;
    cout<<ans;
    return 0;
}