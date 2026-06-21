#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
using ll=long long;
struct obj{
	ll v,w,num;
	bool operator < (const obj& a)const{
		return w<a.w;
	}
	bool operator > (const obj& a)const{
		return w>a.w;
	}
};
priority_queue<obj> pr;
priority_queue<obj,vector<obj>,greater<obj>> low;
ll n,m,ans=0,totw[N],totv[N];
bool ifc[N];
int main(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>totv[i]>>totw[i];
		pr.push({totv[i],totw[i],i});
	}
	ll l=pr.top().w;
	while(!pr.empty()&&pr.top().w==l){
		low.push(pr.top());
		ans+=pr.top().v;
		ifc[pr.top().num]=1;
		pr.pop();
	}
	ll op,x,y;
	for(ll i=1;i<=m;i++){
		cin>>op>>x>>y;
		if(op==1){
			pr.push({x,y,n+i});
			totv[n+i]=x;
			totw[n+i]=y;
		}
		else{
			totw[x]=y;
			if(ifc[x]){
				low.push({totv[x],totw[x],x});
				while(totw[low.top().num]!=low.top().w){
					auto it=low.top();
					low.push({totv[it.num],totw[it.num],it.num});
					low.pop();
				}
				l=low.top().w;
			}
			else{
				pr.push({totv[x],totw[x],x});
			}
		}
		while(!pr.empty()&&pr.top().w>=l){
			ll t=pr.top().num;
			if(ifc[t]||totw[t]!=pr.top().w){
				pr.pop();
				continue;
			}
			low.push(pr.top());
			ans+=totv[t];
			ifc[t]=1;
			pr.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
