#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=2e5+50010;
ll n,q,a[N],cnt[N],op[N];
ll tree[N<<2][2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p){
	tree[p][0]=tree[ls(p)][0]+tree[rs(p)][0];
    tree[p][1]=min(tree[ls(p)][1],tree[rs(p)][1]);
}
void build(ll p,ll pl,ll pr){
	if(pl==pr){tree[p][0]=cnt[pl];tree[p][1]=cnt[pl];return;}
	ll mid=(pr+pl)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
ll query1(ll L,ll R,ll p,ll pl,ll pr){
	if(L<=pl&&pr<=R)return tree[p][0];
	ll res=0;
	ll mid=(pl+pr)>>1;
	if(L<=mid)res+=query1(L,R,ls(p),pl,mid);
	if(mid<R)res+=query1(L,R,rs(p),mid+1,pr);
	return res;
}
ll query2(ll L,ll R,ll p,ll pl,ll pr){
	if(L<=pl&&pr<=R)return tree[p][1];
	ll res=sup;
	ll mid=(pl+pr)>>1;
	if(L<=mid)res=min(res,query2(L,R,ls(p),pl,mid));
	if(mid<R)res=min(res,query2(L,R,rs(p),mid+1,pr));
	return res;
}
ll gap(ll k){
    ll neg=1,p=a[k-1],q=a[k];
    if(a[k-1]<a[k])swap(p,q),neg=-1;
    ll res=0;
    if(neg==1)
        while(p>q)q*=2,res++;
    else{
        while(p>q)q*=2,res++;
        if(p<q)res=max(ll(0),res-1);
    }
    return res*neg;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=2;i<=n;i++)cnt[i]=max(ll(0),gap(i)+cnt[i-1]);
    //for(ll i=1;i<=n;i++)cerr<<cnt[i]<<" ";
    build(1,1,n);
    ll l,r;
    for(ll i=1;i<=q;i++){
        cin>>l>>r;
        ll cut=query2(l,r,1,1,n);
        ll ans=query1(l,r,1,1,n)-(r-l+1)*cut;
        ll k=l,res=cnt[l]-cut;
        while(res>0&&k<=r)res=min(cnt[k]-cut,res),ans-=res,k++;
        cout<<ans<<"\n";
    }
    return 0;
}