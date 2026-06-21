#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=350,M=40;
ll dp[M][M][M][M];
ll a[N];
ll c[5],n,m;
ll dfs(ll c1,ll c2,ll c3,ll c4,ll p){
	if(dp[c1][c2][c3][c4]!=-1)return dp[c1][c2][c3][c4];
	if(c1)dp[c1][c2][c3][c4]=max(dp[c1][c2][c3][c4],dfs(c1-1,c2,c3,c4,p-1)+a[p]);
	if(c2)dp[c1][c2][c3][c4]=max(dp[c1][c2][c3][c4],dfs(c1,c2-1,c3,c4,p-2)+a[p]);
	if(c3)dp[c1][c2][c3][c4]=max(dp[c1][c2][c3][c4],dfs(c1,c2,c3-1,c4,p-3)+a[p]);
	if(c4)dp[c1][c2][c3][c4]=max(dp[c1][c2][c3][c4],dfs(c1,c2,c3,c4-1,p-4)+a[p]);
	return dp[c1][c2][c3][c4];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int op;
	for(int i=1;i<=m;i++){
		cin>>op;
		c[op]++;
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0][0][0]=a[1];
	cout<<dfs(c[1],c[2],c[3],c[4],n);
	return 0;
}
