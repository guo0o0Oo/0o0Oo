#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
bool vis[100010];
vector<ll> G[100010];
void dfs(ll node){
    vis[node]=1;
    for(auto i:G[node]){
        if(!vis[i])dfs(i);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll ans=0;
    for(ll i=1;i<=m;i++){
        ll p,q;cin>>p>>q;
        G[p].push_back(q);
        G[q].push_back(p);
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i])dfs(i),ans++;
    }
    cout<<ans<<"\n";
    return 0;
}