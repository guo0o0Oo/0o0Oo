#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,a[500010],t[500010],dp[500010],tree[500010*4],tag[500010*4],last[500010];
bool teqzero=1,ifh[500010];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void pushup(ll p){
    tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void build(ll p,ll pl,ll pr){
    tag[p]=0;
    if(pl==pr){tree[p]=0;return;}
    ll mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p);
}
void addtag(ll p,ll pl,ll pr,ll d){
    tree[p]+=d;
    tag[p]+=d;
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
    if(L>R)return;
    if(L<=pl&&pr<=R){
        addtag(p,pl,pr,d);
        return;
    }
    pushdown(p,pl,pr);
    ll mid=(pl+pr)>>1;
    if(L<=mid)update(ls(p),pl,mid,L,R,d);
    if(mid<R)update(rs(p),mid+1,pr,L,R,d);
    pushup(p);
}
ll query(ll p,ll pl,ll pr,ll L,ll R){
    if(L>R)return -inf;
    if(L<=pl&&pr<=R)return tree[p];
    if(pr<L||R<pl)return -inf;
    pushdown(p,pl,pr);
    ll mid=(pl+pr)>>1,res=-inf;
    if(L<=mid)res=max(res,query(ls(p),pl,mid,L,R));
    if(mid<R)res=max(res,query(rs(p),mid+1,pr,L,R));
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=m;i++){
        cin>>t[i];
        if(t[i]<0)teqzero=0;
    }
    if(teqzero){
        ll ans=0;
        for(ll i=1;i<=n;i++){
            if(!ifh[a[i]]){
                ifh[a[i]]=1;
                continue;
            }
            ans+=t[a[i]];
        }
        cout<<ans<<"\n";
        return 0;
    }
    build(1,1,n);
    for(ll i=1;i<=n;i++)dp[i]=-inf;
    for(ll i=1;i<=n;i++){
        if(last[a[i]]!=0)update(1,1,n,last[a[i]]+1,i,t[a[i]]);
        last[a[i]]=i;
        dp[i]=max(dp[i],query(1,1,n,1,i));
        update(1,1,n,i+1,i+1,dp[i]);
    }
    cout<<dp[n]<<"\n";
    return 0;
}