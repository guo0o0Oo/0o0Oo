#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
deque<pr> g,l;
int maxn[1000010],minn[1000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,k,a;cin>>n>>k;
	for(int i=1;i<k;i++){
		cin>>a;
		while(!g.empty()&&a>g.back().first)g.pop_back();
		while(!l.empty()&&a<l.back().first)l.pop_back();
		while(!g.empty()&&i-g.front().second>=k)g.pop_front();
		while(!l.empty()&&i-l.front().second>=k)l.pop_front();
		g.push_back({a,i});
		l.push_back({a,i});
	}
	for(int i=k;i<=n;i++){
		cin>>a;
		while(!g.empty()&&a>g.back().first)g.pop_back();
		while(!l.empty()&&a<l.back().first)l.pop_back();
		while(!g.empty()&&i-g.front().second>=k)g.pop_front();
		while(!l.empty()&&i-l.front().second>=k)l.pop_front();
		g.push_back({a,i});
		l.push_back({a,i});
		maxn[i]=g.front().first;
		minn[i]=l.front().first;
	}
	for(int i=k;i<=n;i++){
		cout<<maxn[i]<<" ";
	}
	cout<<"\n";
	for(int i=k;i<=n;i++){
		cout<<minn[i]<<" ";
	}
}
