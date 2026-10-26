#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,k,s[2600],f[2600][10];
vector<ll> G[2600],visble[2600];
bool vis[2600];
void bfs(ll node){
    memset(vis,0,sizeof(vis));
    queue<pr> q;
    q.push({-1,node});
    vis[node]=1;
    while(!q.empty()){
        pr t=q.front();q.pop();
        ll v=t.first,now=t.second;
        if(v<k)
        for(ll i:G[now]){
            if(!vis[i]){
                q.push({v+1,i});
                vis[i]=1;
                visble[node].push_back(i);
            }
        }
    }
    if(node!=1)
    for(ll i:visble[1]){
        if(i!=node&&vis[i]){
            if(s[i]>=s[f[node][1]]){
                f[node][3]=f[node][2];
                f[node][2]=f[node][1];
                f[node][1]=i;
            }
            else if(s[i]>=s[f[node][2]]){
                f[node][3]=f[node][2];
                f[node][2]=i;
            }
            else if(s[i]>s[f[node][3]]){
                f[node][3]=i;
            }
        }
    }
}
void init(){
    for(ll node=1;node<=n;node++){
        bfs(node);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=2;i<=n;i++)cin>>s[i];
    for(ll i=1;i<=m;i++){
        ll s,t;cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    init();
    ll ans=-inf;
    for(ll b=2;b<=n;b++){
        for(ll c:visble[b]){
            if(c==1)continue;
            ll a=f[b][1];
            if(a==c)a=f[b][2];
            ll d=f[c][1];
            if(d==a||d==b)d=f[c][2];
            if(d==a||d==b)d=f[c][3];
            if(a==0||d==0)continue;
            ans=max(ans,s[a]+s[b]+s[c]+s[d]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}