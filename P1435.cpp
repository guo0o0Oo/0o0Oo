#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string s;
ll dp[1010][1010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    ll ls=s.size();
    s="0"+s;
    for(ll i=1;i<=ls;i++)
    for(ll j=1;j<=ls;j++)
        dp[i][j]=sup;
    for(ll i=0;i<=ls;i++)dp[i][0]=0,dp[i][1]=0;
    for(ll j=2;j<=ls;j++){
        for(ll i=1;i<=ls-j+1;i++){
            if(s[i]==s[i+j-1])dp[i][j]=min(dp[i][j],dp[i+1][j-2]);
            dp[i][j]=min(dp[i][j],dp[i+1][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
    }
    cout<<dp[1][ls]<<"\n";
    return 0;
}