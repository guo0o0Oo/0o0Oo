#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll dp[6010][2],n,r[6010],is_root[6010];
vector<ll> son[6010];
void dfs(ll node){
    dp[node][1]+=r[node];
    for(auto i:son[node]){
        dfs(i);
        dp[node][0]+=max(dp[i][0],dp[i][1]);
        dp[node][1]+=dp[i][0];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>r[i];
    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        is_root[x]=1;
        son[y].push_back(x);
    }
    ll root;
    for(ll i=1;i<=n;i++)if(!is_root[i]){root=i;break;}
    dfs(root);
    cout<<max(dp[root][0],dp[root][1]);
    return 0;
}