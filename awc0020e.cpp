#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10; 
ll a[N],b[N];
ll tree[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p){
	tree[p]=min(tree[ls(p)],tree[rs(p)]);
}
void build(ll p,ll pl,ll pr){
	if(pl==pr){tree[p]=a[pl];return;}
	ll mid=(pr+pl)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(ll P,ll p,ll pl,ll pr,ll d){
	if(pl==pr&&P==pl){
		tree[p]=d;
		return;
	}
	ll mid=(pl+pr)>>1;
	if(P<=mid)update(P,ls(p),pl,mid,d);
	if(mid<P)update(P,rs(p),mid+1,pr,d);
	push_up(p);
}
ll query(ll L,ll R,ll p,ll pl,ll pr){
	if(L<=pl&&pr<=R)return tree[p];
	ll res=1e9+10;
	ll mid=(pl+pr)>>1;
	if(L<=mid)res=min(query(L,R,ls(p),pl,mid),res);
	if(mid<R)res=min(query(L,R,rs(p),mid+1,pr),res);
	return res;
}
int main(){
	ll n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&a[i]);
	
    build(1,1,n);
	for(int i=1;i<=n;i++){

    }
	return 0;
}