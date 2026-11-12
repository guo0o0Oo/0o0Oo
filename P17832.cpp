#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll c,m,n,d,q,cnt;
ll w[600010];
vector<pr> G[600010],onlydG[600010];
ll alldis[1010][1010],onedis[600010],done[600010];
priority_queue<pr,vector<pr>,greater<pr> > pq;
void dij(ll node){
    for(ll i=1;i<=cnt;i++)onedis[i]=inf;
    for(ll i=1;i<=cnt;i++)done[i]=0;
    while(!pq.empty())pq.pop();
    onedis[node]=0;
    pq.push({0,node});
    while(!pq.empty()){
        pr t=pq.top();pq.pop();
        ll u=t.second,dis=t.first;
        if(done[u])continue;
        done[u]=1;
        for(pr i:G[u]){
            ll v=i.second,ds=i.first;
            if(done[v])continue;
            if(onedis[v]>onedis[u]+ds){
                onedis[v]=onedis[u]+ds;
                pq.push({onedis[v],v});
            }
        }
    }
    for(ll i=1;i<=n;i++){
        alldis[node-m][i]=onedis[i+m];
    }
}
void init(){
    for(ll i=1;i<=n;i++)dij(m+i);
}
int main(){
    cin>>c>>n>>m>>d>>q;
    cnt=m;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll k,a,t,root=++cnt;
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>a>>t;
            G[root].push_back({t,a});
            G[a].push_back({t,root});
            onlydG[a].push_back({t,root-m});
        }
    }
    init();
    while(q--){
        ll x,y;cin>>x>>y;
        ll ans=w[x]+w[y],cnt=inf;
        for(pr i:onlydG[x]){
            for(pr j:onlydG[y]){
                cnt=min(cnt,i.first+j.first+alldis[i.second][j.second]);
            }
        }
        cout<<ans+cnt<<"\n";
    }
    return 0;
}