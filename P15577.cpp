#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,m,k,l,ifs[N],ifd[N],cnt[N],vis[N],ifc[N],ifsolve[N],dfn[N];
vector<ll> edge[N];
queue<ll> q;
void init(){
    while(!q.empty())q.pop();
    for(ll i=1;i<=n;i++){
        ifs[i]=0;
        ifd[i]=0;
        ifc[i]=0;
        cnt[i]=0;
        vis[i]=0;
        dfn[i]=sup;
        ifsolve[i]=0;
        edge[i].clear();
    }
}
void bfs(){
    cnt[1]=ifs[1];
    vis[1]=1;
    dfn[1]=1;
    q.push(1);
    while(!q.empty()){
        ll node=q.front();
        for(ll i:edge[node]){
            if(dfn[i]>dfn[node])cnt[i]=max(cnt[i],cnt[node]+ifs[i]);
            if(vis[i])continue;
            dfn[i]=dfn[node]+1;
            q.push(i);
            vis[i]=1;
        }
        q.pop();
    }
}
void solve(ll node){
    if(ifsolve[node])return;
    ifc[node]=1;
    for(ll i:edge[node]){
        if(cnt[i]==cnt[node]-ifs[node]&&dfn[i]<dfn[node])solve(i);
    }
    ifsolve[node]=1;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n>>m>>k>>l;
        init();
        ll a,b;
        for(ll i=1;i<=k;i++){cin>>a;ifs[a]=1;}
        for(ll i=1;i<=l;i++){cin>>a;ifd[a]=1;}
        for(ll i=1;i<=m;i++){cin>>a;cin>>b;edge[a].push_back(b);edge[b].push_back(a);}
        bfs();
        for(ll i=1;i<=n;i++){
            if(ifd[i]&&cnt[i]==k){
                solve(i);
            }
        }
        for(ll i=2;i<=n;i++)cout<<ifc[i];
        cout<<"\n";
    }
    return 0;
}