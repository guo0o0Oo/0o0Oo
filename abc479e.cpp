#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,sze[200010],add,tag[200010],x[200010],num[200010];
vector<ll> G[200010],nnum[200010];
void dp(ll node,ll fa){
    sze[node]=1;
    for(ll i=0;i<G[node].size();i++){
        if(G[node][i]==fa)continue;
        num[G[node][i]]=nnum[node][i];
        dp(G[node][i],node);
        sze[node]+=sze[G[node][i]];
    }
}
void dfs(ll node,ll fa){
    if(sze[node]>n/2){
        tag[node]+=num[node];
    }
    else{
        tag[node]-=num[node];
        add+=num[node];
    }
    for(ll i:G[node]){
        if(i==fa)continue;
        dfs(i,node);
    }
}
void solve(){
    for(ll i:G[1]){
        dfs(i,1);
    }
}
void sum(ll node,ll fa){
    x[node]=tag[node]+add;
    for(ll i:G[node]){
        if(i==fa)continue;
        tag[i]+=tag[node];
        sum(i,node);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n-1;i++){
        ll a,b;cin>>a>>b;
        G[a].push_back(b);
        nnum[a].push_back(i);
        G[b].push_back(a);
        nnum[b].push_back(i);
    }
    dp(1,0);
    solve();
    sum(1,0);
    for(ll i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}