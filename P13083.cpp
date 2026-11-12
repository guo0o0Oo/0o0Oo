#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
vector<pll> lim[N];
ll n,q,tree[N<<2],tag[N<<2],pos[N<<2],ans[N];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void pushup(ll p){
    tree[p]=min(tree[ls(p)],tree[rs(p)]);
    if(tree[ls(p)]<=tree[rs(p)])pos[p]=pos[ls(p)];
    else pos[p]=pos[rs(p)];
}
void build(ll p,ll pl,ll pr){
    tag[p]=0;
    if(pl==pr){tree[p]=0;pos[p]=pl;return;}
    ll mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p);
}
void addtag(ll p,ll pl,ll pr,ll d){
    tag[p]+=d;
    tree[p]+=d;
}
void pushdown(ll p,ll pl,ll pr){
    if(tag[p]){
        ll mid=(pl+pr)>>1;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
}
void update(ll p,ll pl,ll pr,ll L,ll R,ll d){
    if(L<=pl&&pr<=R){addtag(p,pl,pr,d);return;}
    if(R<pl||pr<L)return;
    pushdown(p,pl,pr);
    ll mid=(pl+pr)>>1;
    update(ls(p),pl,mid,L,R,d);
    update(rs(p),mid+1,pr,L,R,d);
    pushup(p);
}
pll query(ll p,ll pl,ll pr,ll L,ll R){
    if(L<=pl&&pr<=R)return {tree[p],pos[p]};
    if(R<pl||pr<L)return {inf,inf};
    pushdown(p,pl,pr);
    pll res;
    ll mid=(pl+pr)>>1;
    res=min(query(ls(p),pl,mid,L,R),query(rs(p),mid+1,pr,L,R));
    return res;
}
inline void pt(){
    for(ll i=1;i<=n;i++)cout<<-1<<" ";
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    build(1,1,n);
    for(ll i=1;i<=q;i++){
        ll l,r,a;
        cin>>l>>r>>a;
        l++;r++;a++;
        lim[a].push_back({l,r});
        update(1,1,n,l,r,1);
    }
    for(ll i=1;i<=n;i++){
        ll l=1,r=n;
        for(pll j:lim[i]){
            l=max(l,j.first);
            r=min(r,j.second);
            update(1,1,n,j.first,j.second,-1);
        }
        if(r<l){pt();return 0;}
        pll res=query(1,1,n,l,r);
        if(res.first!=0){pt();return 0;}
        ans[res.second]=i;
        update(1,1,n,res.second,res.second,inf);
    }
    for(ll i=1;i<=n;i++)cout<<ans[i]-1<<" ";
    return 0;
}