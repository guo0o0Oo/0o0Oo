#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+10;
ll n,c[maxn],v[maxn],f[maxn],ic[maxn]={1},minn=INT_MAX;
pair<int,int> p[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=1;i<=n;i++){
		if(p[c[i]].first){
			p[c[i]].second=i;
		}
		else{
			p[c[i]].first=i;
		}
	}
	for(int ii=1;ii<=n;ii++)
	for(int i=ii;i<=n;){
		int k,ans=0;
		k=p[c[i]].second;
		for(int j=i;j<=k;j++){
			ans+=v[j];
			k=max(k,p[c[j]].second);
		}
		cout<<ans<<" "<<f[k-i+1]<<"\n";
		minn=min(minn,ans*f[k-i+1]);
		i=k+1;
	}
	cout<<minn<<"\n";
}
