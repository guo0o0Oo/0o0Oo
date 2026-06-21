#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,dp[310][310],v[310];
vector<ll> son[310];
void dfs(ll nd){
    dp[nd][1]=v[nd];
    for(auto i:son[nd])dfs(i);
    for(auto i:son[nd])
        for(ll j=m;j>=2;j--)
            for(ll k=1;k<j;k++)
                dp[nd][j]=max(dp[nd][j],dp[nd][j-k]+dp[i][k]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    m++;
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x>>v[i];
        son[x].push_back(i);
    }
    dfs(0);
    cout<<dp[0][m]<<"\n";
    return 0;
}