#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,ans,all;
bool G[110][110],vis[110],data[110];
void dfs(ll node){
    if(vis[node])return;
    vis[node]=1;
    for(ll i=1;i<=n;i++){
        if(G[node][i]&&!vis[i])dfs(i);
    }
}
ll cnt(){
    ll res=0;
    memset(vis,0,sizeof(vis));
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            res++;
            dfs(i);
        }
    }
    return res;
}
void check(ll node){
    memset(data,0,sizeof(data));
    for(ll i=1;i<=n;i++){
        data[i]=G[node][i];
        G[node][i]=0;
        G[i][node]=0;
    }
    ll res=cnt();
    if(res>all+1)ans++;
    for(ll i=1;i<=n;i++){
        G[node][i]=data[i];
        G[i][node]=data[i];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        G[x][y]=1;
        G[y][x]=1;
    }
    all=cnt();
    for(ll i=1;i<=n;i++){
        check(i);
    }
    cout<<ans<<"\n";
    return 0;
}