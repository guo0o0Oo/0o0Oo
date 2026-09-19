#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct Opr{
    ll u1,v1,u2,v2,w;
};
ll n,m,s,sf[50010],grandfa[50010][20],exnode[50010][20][2],dep[50010],lg2[2000010],cnt;//exnode:0->in,1->out
ll dis[2000010];
bool vis[50010],done[2000010];
vector<pr> edge[2000010];
queue<Opr> q;
priority_queue<pr,vector<pr>,greater<pr> > pq;
ll find(ll x){
    if(sf[x]!=x)sf[x]=find(sf[x]);
    return sf[x];
}
void merge(ll x,ll y){
    ll fx=find(x),fy=find(y);
    if(fx!=fy)sf[fx]=fy;
}
void input(){
    cin>>n>>m>>s;
    for(ll i=1;i<=n;i++)sf[i]=i;
    for(ll i=1;i<=m;i++){
        ll op;cin>>op;
        if(op==1){
            ll u1,v1,u2,v2,w;cin>>u1>>v1>>u2>>v2>>w;
            if(find(u1)==find(v1)&&find(u2)==find(v2)){
                q.push({u1,v1,u2,v2,w});
            }
        }
        else{
            ll u,v,w;cin>>u>>v>>w;
            if(find(u)!=find(v)){
                edge[u].push_back(make_pair(w,v));
                edge[v].push_back(make_pair(w,u));
                merge(u,v);
            }
        }
    }
}
void dfs(ll node,ll fa,ll depth){
    vis[node]=1;
    grandfa[node][0]=fa;
    dep[node]=depth;
    for(auto i:edge[node]){
        if(i.second!=fa){
            dfs(i.second,node,depth+1);
        }
    }
}
void init(){
    cnt=n+1;
    for(ll i=2;i<=2000000;i++)lg2[i]=lg2[i/2]+1;
    for(ll i=1;i<=2000000;i++)dis[i]=inf;
    for(ll i=1;i<=n;i++){
        if(!vis[i])dfs(i,i,1);
    }
    for(ll i=1;i<=n;i++){
        exnode[i][0][0]=cnt++;
        exnode[i][0][1]=cnt++;
        edge[exnode[i][0][0]].push_back(make_pair(0ll,i));
        edge[i].push_back(make_pair(0ll,exnode[i][0][1]));
    }
    for(ll i=1;i<=17;i++){
        for(ll j=1;j<=n;j++){
            grandfa[j][i]=grandfa[grandfa[j][i-1]][i-1];
            exnode[j][i][0]=++cnt;
            exnode[j][i][1]=++cnt;
            edge[exnode[j][i][0]].push_back(make_pair(0ll,exnode[j][i-1][0]));
            edge[exnode[j][i][0]].push_back(make_pair(0ll,exnode[grandfa[j][i-1]][i-1][0]));
            edge[exnode[j][i-1][1]].push_back(make_pair(0ll,exnode[j][i][1]));
            edge[exnode[grandfa[j][i-1]][i-1][1]].push_back(make_pair(0ll,exnode[j][i][1]));
        }
    }
}
ll lca(ll u,ll v){
    if(u==v)return u;
    if(dep[u]<dep[v])swap(u,v);
    for(ll i=17;i>=0;i--)if(dep[grandfa[u][i]]>=dep[v])u=grandfa[u][i];
    if(u==v)return u;
    for(ll i=17;i>=0;i--){
        if(grandfa[u][i]!=grandfa[v][i]){
            u=grandfa[u][i];
            v=grandfa[v][i];
        }
    }
    return grandfa[u][0];
}
void build(){
    while(!q.empty()){
        Opr ask=q.front();
        q.pop();
        ll u1=ask.u1,v1=ask.v1,u2=ask.u2,v2=ask.v2,w=ask.w;
        ll lca1=lca(u1,v1),lca2=lca(u2,v2);
        ll outnode[5],innode[5];
        ll outlen1=dep[u1]-dep[lca1]+1,outlen2=dep[v1]-dep[lca1]+1;
        ll inlen1=dep[u2]-dep[lca2]+1,inlen2=dep[v2]-dep[lca2]+1;
        ll gap;
        outnode[1]=exnode[u1][lg2[outlen1]][1];
        gap=outlen1-(1<<lg2[outlen1]);
        for(ll i=17;i>=0;i--){
            if(gap>=(1<<i))u1=grandfa[u1][i],gap-=(1<<i);
        }
        outnode[2]=exnode[u1][lg2[outlen1]][1];
        
        outnode[3]=exnode[v1][lg2[outlen2]][1];
        gap=outlen2-(1<<lg2[outlen2]);
        for(ll i=17;i>=0;i--){
            if(gap>=(1<<i))v1=grandfa[v1][i],gap-=(1<<i);
        }
        outnode[4]=exnode[v1][lg2[outlen2]][1];

        innode[1]=exnode[u2][lg2[inlen1]][0];
        gap=inlen1-(1<<lg2[inlen1]);
        for(ll i=17;i>=0;i--){
            if(gap>=(1<<i))u2=grandfa[u2][i],gap-=(1<<i);
        }
        innode[2]=exnode[u2][lg2[inlen1]][0];

        innode[3]=exnode[v2][lg2[inlen2]][0];
        gap=inlen2-(1<<lg2[inlen2]);
        for(ll i=17;i>=0;i--){
            if(gap>=(1<<i))v2=grandfa[v2][i],gap-=(1<<i);
        }
        innode[4]=exnode[v2][lg2[inlen2]][0];
        for(ll i=1;i<=4;i++){
            for(ll j=1;j<=4;j++){
                edge[outnode[i]].push_back(make_pair(w,innode[j]));
            }
        }
    }
}
void dijk(){
    pq.push(make_pair(0,s));
    dis[s]=0;
    while(!pq.empty()){
        while(!pq.empty()&&done[pq.top().second])pq.pop();
        if(pq.empty())break;
        ll now=pq.top().second;pq.pop();
        done[now]=1;
        for(auto i:edge[now]){
            if(done[i.second])continue;
            if(dis[i.second]>dis[now]+i.first){
                dis[i.second]=dis[now]+i.first;
                pq.push(make_pair(dis[i.second],i.second));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    init();
    build();
    dijk();
    for(ll i=1;i<=n;i++){
        if(dis[i]==inf)cout<<-1<<" ";
        else cout<<dis[i]<<" ";
    }
    return 0;
}