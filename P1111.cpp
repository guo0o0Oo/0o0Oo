#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
using pr=pair<ll,pair<ll,ll> >;
ll n,m,res;
ll fa[1010];
pr edg[100010];
void init(){
    for(ll i=1;i<=n;i++)fa[i]=i;
}
ll fd(ll x){
    if(x==fa[x])return x;
    fa[x]=fd(fa[x]);
    return fa[x];
}
void mg(ll x,ll y){
    ll fx=fd(x),fy=fd(y);
    if(fx==fy)return;
    fa[fx]=fy;
    res--;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    init();
    res=n;
    for(ll i=1;i<=m;i++){
        cin>>edg[i].second.first>>edg[i].second.second>>edg[i].first;
    }
    sort(edg+1,edg+m+1);
    for(ll i=1;i<=m;i++){
        ll u=edg[i].second.first,v=edg[i].second.second;
        mg(u,v);
        if(res==1){
            cout<<edg[i].first<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}