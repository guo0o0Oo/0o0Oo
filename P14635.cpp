#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
ll candy1[N],candy2=LONG_LONG_MAX;
ll noc(ll k){
	return k/candy2*2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		candy1[i]=a;
		candy2=min(candy2,a+b);
	}
	sort(candy1+1,candy1+1+n);
	candy1[0]=0;
	for(int i=1;i<=n;i++){
		candy1[i]+=candy1[i-1];
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		if(candy1[i]>m)break;
		ans=max(ans,i+noc(m-candy1[i]));
	}
	cout<<ans<<endl;
	return 0;
}
