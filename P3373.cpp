#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10; 
ll a[N];
ll tree[N<<2];
ll tag[N<<2][2];
ll n,q,m;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p){
	tree[p]=(tree[ls(p)]+tree[rs(p)])%m;
}
void build(ll p,ll pl,ll pr){
	if(pl==pr){tree[p]=a[pl];return;}
	ll mid=(pr+pl)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void push_down(ll p,ll pl,ll pr);
void addtag(ll p,ll pl,ll pr,ll d,int op){
	if(tag[p][!op])push_down(p,pl,pr);
    tag[p][op]+=d;
    if(op==0)tree[p]=(tree[p]+d*(pr-pl+1))%m;
    if(op==1)tree[p]=(tree[p]*d)%m;
}
void push_down(ll p,ll pl,ll pr){
    if(tag[p][1]){
        ll mid=(pr+pl)>>1;
		addtag(ls(p),pl,mid,tag[p][1],1);
		addtag(rs(p),mid+1,pr,tag[p][1],1);
		tag[p][1]=0;
    }
	if(tag[p][0]){
		ll mid=(pr+pl)>>1;
		addtag(ls(p),pl,mid,tag[p][0],0);
		addtag(rs(p),mid+1,pr,tag[p][0],0);
		tag[p][0]=0;
	}
}
void update(ll L,ll R,ll p,ll pl,ll pr,ll d,int op){
	if(L<=pl&&pr<=R){
		addtag(p,pl,pr,d,op);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(L<=mid)update(L,R,ls(p),pl,mid,d,op);
	if(mid<R)update(L,R,rs(p),mid+1,pr,d,op);
	push_up(p);
}
ll query(ll L,ll R,ll p,ll pl,ll pr){
	if(L<=pl&&pr<=R)return tree[p];
	push_down(p,pl,pr);
	ll res=0;
	ll mid=(pl+pr)>>1;
	if(L<=mid)res+=query(L,R,ls(p),pl,mid);
	if(mid<R)res+=query(L,R,rs(p),mid+1,pr);
	return res%m;
}
int main(){
	scanf("%lld %lld %lld",&n,&q,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	while(q--){
		ll op,L,R,d;scanf("%lld",&op);
		if(op==1){
			scanf("%lld %lld %lld",&L,&R,&d);
			update(L,R,1,1,n,d,1);
		}
        else if(op==2){
            scanf("%lld %lld %lld",&L,&R,&d);
			update(L,R,1,1,n,d,0);
        }
		else{
			scanf("%lld %lld",&L,&R);
			printf("%lld\n",query(L,R,1,1,n));
		}
	}
	return 0;
}