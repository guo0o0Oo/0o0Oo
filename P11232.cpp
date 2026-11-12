#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll N=1e5+10;
ll n,m,L,V;
bool ifc[N];
vector<pr> over,out;
vector<ll> p;
void insert(ll d,ll v,ll a){
	ll s,t,sp;
	if(v<=V&&a<=0)return;
	if(v>V&&a>=0){over.push_back({d,L});return;}
	if(v<=V&&a>0){
		if(v*v+2*a*(L-d)<=V*V)return;
		t=L;
		ll l=d,r=L;
		while(l<r){
			ll mid=(l+r)>>1;
			if(v*v+2*a*(mid-d)<=V*V)l=mid+1;
			else r=mid;
		}
		s=l;
	}
	if(v>V&&a<0){
		s=d;
		ll l=d,r=L;
		while(l<r){
			ll mid=(l+r+1)>>1;
			if(v*v+2*a*(mid-d)<=V*V)r=mid-1;
			else l=mid;
		}
		t=l;
	}
	over.push_back({s,t});
}
int main(){
	ll T;cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		over.clear();
		out.clear();
		p.clear();
		memset(ifc,0,sizeof(ifc));
		for(ll i=1;i<=n;i++){
			ll d,v,a;cin>>d>>v>>a;
			insert(d,v,a);
		}
		for(ll i=1;i<=m;i++){
			ll pos;cin>>pos;
			p.push_back(pos);
		}
		sort(over.begin(),over.end());
		ll now=0,cnt=0;
		for(ll pos:p){
			pr t=over[now];
			ll tl=t.first,tr=t.second;
			while(tl<=pos){
				if(tr>=pos)cnt++,out.push_back({tr,tl});
				now++;
				if(now>=over.size())break;
				t=over[now];
				tl=t.first,tr=t.second;
			}
			if(now>=over.size())break;
		}
		cout<<cnt<<" ";
		sort(out.begin(),out.end());
		now=0,cnt=0;
		while(now+1<p.size()&&p[now+1]<=out[0].first)now++;
		for(pr t:out){
			ll tl=t.second,tr=t.first;
			if(tl>p[now])
			while(now+1<p.size()&&p[now+1]<=tr)now++;
			if(!ifc[now]&&tl<=p[now]){
				ifc[now]=1;
				cnt++;
			}
		}
		cout<<m-cnt<<"\n";
	}
}