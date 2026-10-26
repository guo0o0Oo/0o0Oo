#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,k,dp[510][510][5];
string s;
bool cmp(ll l,ll r){
    return (l=='('||l=='?')&&(r==')'||r=='?');
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k>>s;
    s=" "+s;
    for(ll i=1;i<=n;i++)dp[i][i-1][0]=1;
    for(ll len=1;len<=n;len++){
        for(ll i=1;i+len-1<=n;i++){
            ll l=i,r=i+len-1;
            if(len<=k){
                dp[l][r][0]=dp[l][r-1][0]*(s[i]=='*'||s[i]=='?');
            }
            if(len>=2){
                if(cmp(l,r))dp[l][r][1]=(dp[l+1][r-1][0]+dp[l+1][r-1][1]+dp[l+1][r-1][2]+dp[l+1][r-1][3]+dp[l+1][r-1][4]
            }
        }
    }
    return 0;
}