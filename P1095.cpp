#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll m,s,t,dp[2][1100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>m>>s>>t;
	ll old=0,now=1,maxs=0;
	for(ll i=0;i<=1000;i++){
		dp[now][i]=inf;
		dp[old][i]=inf;
	}
	dp[now][m]=0;
	for(ll ii=1;ii<=t;ii++){
		swap(old,now);
		for(ll i=0;i<=1000;i++)dp[now][i]=inf;
		for(ll i=0;i<=1000;i++){
			if(dp[old][i]!=inf)dp[now][i]=max(dp[now][i],dp[old][i]+17);
			if(i+10<=1000&&dp[old][i+10]!=inf)dp[now][i]=max(dp[now][i],dp[old][i+10]+60);
			if(i>=4&&dp[old][i-4]!=inf)dp[now][i]=max(dp[now][i],dp[old][i-4]);
			maxs=max(maxs,dp[now][i]);
		}
		if(maxs>=s){
			cout<<"Yes\n"<<ii<<"\n";
			return 0;
		}
	}
	cout<<"No\n"<<maxs;
	return 0;
}