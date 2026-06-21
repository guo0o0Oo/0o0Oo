#include<bits/stdc++.h>
using namespace std;
int n,k,v[16],dp[225];
int res[16],ans=-1;
int find_max(int dep){
	dp[0]=0;
	for(int i=1;i<=225;i++)dp[i]=INT_MAX;
	for(int i=1;i<=225;i++){
		for(int j=1;j<=dep;j++){
			if(i>=v[j])dp[i]=min(dp[i],dp[i-v[j]]+1);
		}
		if(dp[i]>n){
			return i-1;
		}
	}
}
void dfs(int dep,int maxk){
	if(dep==k+1){
		if(maxk>ans){
			ans=maxk;
			for(int i=1;i<=k;i++){
				res[i]=v[i];
			}
		}
		return;
	}
	for(int i=v[dep-1]+1;i<=maxk+1;i++){
		v[dep]=i;
		dfs(dep+1,find_max(dep));
	}
}
int main(){
	cin>>n>>k;
	v[1]=1;
	dfs(2,n);
	for(int i=1;i<=k;i++){
		cout<<res[i]<<" ";
	}
	cout<<"\n";
	cout<<"MAX="<<ans<<"\n";
	return 0;
}

