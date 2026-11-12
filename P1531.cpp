#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=2e5+10;
ll a[N],n,q,tree[N<<2],tag[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void pushup(ll p){
    tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void build(ll p,ll pl,ll pr){
    tag[p]=-1;
    if(pl==pr){tree[p]=a[pl];return;}
    ll mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p);
}
void addtag(ll p,ll pl,ll pr,ll d){
    tag[p]=max(tag[p],d);
    tree[p]=max(tree[p],d);
}
void pushdown(ll p,ll pl,ll pr){
    if(tag[p]!=-1){
        ll mid=(pl+pr)>>1;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=-1;
    }
}
void update(ll p,ll pl,ll pr,ll L,ll R,ll d){
    if(L<=pl&&pr<=R){
        addtag(p,pl,pr,d);
        return;
    }
    pushdown(p,pl,pr);
    ll mid=(pl+pr)>>1;
    if(L<=mid)update(ls(p),pl,mid,L,R,d);
    if(R>mid)update(rs(p),mid+1,pr,L,R,d);
    pushup(p);
}
ll query(ll p,ll pl,ll pr,ll L,ll R){
    if(L<=pl&&pr<=R)return tree[p];
    if(pr<L||R<pl)return -1;
    pushdown(p,pl,pr);
    ll mid=(pl+pr)>>1;
    ll res=-1;
    if(L<=mid)res=max(res,query(ls(p),pl,mid,L,R));
    if(R>mid)res=max(res,query(rs(p),mid+1,pr,L,R));
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(q--){
        char ch;ll x,y;
        cin>>ch;
        cin>>x>>y;
        if(ch=='Q'){
            if(x>y)swap(x,y);
            cout<<query(1,1,n,x,y)<<"\n";
        }
        else{
            update(1,1,n,x,x,y);
        }
    }
    return 0;
}