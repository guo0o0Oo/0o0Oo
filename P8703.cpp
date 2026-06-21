#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string t,s;
ll dp[1010][1010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t>>s;
    for(ll i=0;i<=t.size();i++)
    for(ll j=0;j<=s.size();j++)
        dp[i][j]=sup;
    ll lt=t.size(),ls=s.size();
    for(ll i=0;i<=lt;i++)dp[i][0]=0;
    t="0"+t;
    s="0"+s;
    for(ll i=1;i<=lt;i++){
        for(ll j=1;j<=min(i,ls);j++){
            if(t[i]==s[j]){
                dp[i][j]=dp[i-1][j-1];
            }
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout<<dp[lt][ls]<<"\n";
    return 0;
}