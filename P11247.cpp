#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+10;
ll m,n,k,sum[maxn]={},cnt[maxn]={},a[maxn],b[maxn];
int ih[maxn]={};
priority_queue<pair<ll,ll> > pq;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ih[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		if(!ih[i]){
			cout<<-1<<"\n";
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		pq.push({a[i],b[i]});
	}
	for(int i=1;i<=n;i++){
		if(sum[pq.top().first]<k){
			sum[pq.top().first]+=b[i];
			cnt[pq.top().first]++;
		}
		pq.pop();
	}
	ll all=0;
	for(int i=1;i<=m;i++){
		all+=cnt[i];
	}
	for(int i=1;i<=m;i++){
		if(sum[i]<k){
			cout<<-1<<"\n";
			return 0;
		}
		if(cnt[i]*2>all){
			cout<<-1<<"\n";
			return 0;
		}
	}
	cout<<all<<"\n";
	return 0;
}
