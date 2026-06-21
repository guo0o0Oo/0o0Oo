#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
ll n,num[50][50],dp[50][100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s>>n;
    for(ll i=1;i<=s.size();i++){
        for(ll j=i;j<=s.size();j++){
            num[i][j]=num[i][j-1]*10+(s[j-1]-'0');
        }
    }
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[0][0]=-1;
    for(ll i=1;i<=s.size();i++) {
        for(ll j=0;j<=n;j++) {
            for(ll k=1;k<=i;k++) {
                if(j-num[i-k+1][i]<=n&&j-num[i-k+1][i]>=0&&j>=num[i-k+1][i]) {
                    dp[i][j]=min(dp[i][j],dp[i-k][j-num[i-k+1][i]]+1);
                }
            }
        }
    }
    if(dp[s.size()][n]>=0x3f3f3f3f3f3f)cout<<-1<<"\n";
    else cout<<dp[s.size()][n]<<"\n";
    return 0;
}