#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,pair<ll,ll> >;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll fa[100010],sum[100010],ans[100010],n,Q;
pr q[100010],edge[100010];
ll fd(ll x){
    if(x!=fa[x])fa[x]=fd(fa[x]);
    return fa[x];
}
void mg(ll x,ll y){
    ll fx=fd(x),fy=fd(y);
    fa[fx]=fy;
    sum[fy]=sum[fy]+sum[fx];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>Q;
    for(ll i=1;i<=n;i++)fa[i]=i;
    for(ll i=1;i<=n;i++)sum[i]=1;
    for(ll i=1;i<n;i++){
        ll u,v,r;cin>>u>>v>>r;
        edge[i]={r,{u,v}};
    }
    for(ll i=1;i<=Q;i++){
        ll k,v;cin>>k>>v;
        q[i]={k,{v,i}};
    }
    sort(edge+1,edge+n);
    sort(q+1,q+Q+1);
    ll now=n-1,mx,i=Q;
    while(i>=1){
        mx=q[i].first;
        while(now>=1&&edge[now].first>=mx){
            ll u=edge[now].second.first,v=edge[now].second.second;
            mg(u,v);
            now--;
        }
        while(i>=1&&q[i].first==mx){
            ans[q[i].second.second]=sum[fd(q[i].second.first)]-1;
            i--;
        }
    }
    for(ll i=1;i<=Q;i++)cout<<ans[i]<<"\n";
    return 0;
}