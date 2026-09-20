#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using par=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=2e5+10;
ll n,m,a[N];
par mxtree[N<<2],mntree[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
par unite(par x,par y){
    ll resa=a[x.first]>a[y.first]?x.first:y.first,resb=a[x.second]<a[y.second]?x.second:y.second;
    return {resa,resb};
}
void push_up(ll p){
	mxtree[p]=max(mxtree[ls(p)],mxtree[rs(p)]);
    mntree[p]=min(mntree[ls(p)],mntree[rs(p)]);
}
void build(ll p,ll pl,ll pr){
	if(pl==pr){mntree[p]={a[pl],pl};mxtree[p]={a[pl],pl};return;}
	ll mid=(pr+pl)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(ll P,ll p,ll pl,ll pr,ll d){
    if(pl==pr){
        a[pl]=d;
        mntree[p]={a[pl],pl};
        mxtree[p]={a[pl],pl};
        return;
    }
	ll mid=(pl+pr)>>1;
	if(P<=mid)update(P,ls(p),pl,mid,d);
	if(mid<P)update(P,rs(p),mid+1,pr,d);
	push_up(p);
}
par query(ll L,ll R,ll p,ll pl,ll pr){
	if(L<=pl&&pr<=R)return {mxtree[p].second,mntree[p].second};
	par res={0,n+1};
	ll mid=(pl+pr)>>1;
	if(L<=mid){
        par re=query(L,R,ls(p),pl,mid);
        res=unite(res,re);
    }
	if(mid<R){
        par re=query(L,R,rs(p),mid+1,pr);
        res=unite(res,re);
    }
	return res;
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    a[n+1]=inf;
	build(1,1,n);
	while(m--){
		ll L,R;
		scanf("%lld %lld",&L,&R);
        par res=query(L,R,1,1,n);
        ll mx=a[res.first],mn=a[res.second];
        update(res.first,1,1,n,mn);
        update(res.second,1,1,n,mx);
	}
    for(ll i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}
