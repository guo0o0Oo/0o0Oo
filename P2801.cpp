#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
ll a[N],b[N],st[N],ed[N],pos[N],add[N];
void copy(ll k){
	for(ll i=st[k];i<=ed[k];i++){
		b[i]=a[i];
	}
	sort(b+st[k],b+ed[k]+1);
}
void change(ll L,ll R,ll X){
	ll p=pos[L],q=pos[R];
	if(p==q){
		for(ll i=L;i<=R;i++){
			a[i]+=X;
		}
		copy(p);
	}
	else{
		for(ll i=p+1;i<=q-1;i++){
			add[i]+=X;
		}
		for(ll i=L;i<=ed[p];i++){
			a[i]+=X;
		}
		copy(p);
		for(ll i=st[q];i<=R;i++){
			a[i]+=X;
		}
		copy(q);
	}
}
ll find(ll L,ll R,ll X){
	ll l=L,r=R+1;
	while(l<r){
		ll mid=(l+r)>>1;
		if(b[mid]>=X)r=mid;
		else l=mid+1;
	}
	return R-l+1;
}
void ask(ll L,ll R,ll X){
	ll p=pos[L],q=pos[R];
	if(p==q){
		cout<<find(L,R,X-add[p])<<"\n";
	}
	else{
		ll ans=0;
		for(ll i=p+1;i<=q-1;i++){
			ans+=find(st[i],ed[i],X-add[i]);
		}
		for(ll i=L;i<=ed[p];i++)if(a[i]+add[p]>=X)ans++;
		for(ll i=st[q];i<=R;i++)if(a[i]+add[q]>=X)ans++;
		cout<<ans<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,q;cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	ll block=sqrt(n);
	ll t=n/block;
	if(n%block)t++;
	for(ll i=1;i<=t;i++){
		st[i]=(i-1)*block+1;
		ed[i]=i*block;
	}
	ed[t]=n;
	for(ll i=1;i<=n;i++){
		pos[i]=(i-1)/block+1;
	}
	for(ll i=1;i<=t;i++){
		sort(b+st[i],b+ed[i]+1);
	}
	char op;
	ll L,R,X;
	while(q--){
		cin>>op>>L>>R>>X;
		if(op=='M'){
			change(L,R,X);
		}
		else{
			ask(L,R,X);
		}
	}
	return 0;
}
