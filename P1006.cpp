#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=100;
ll graph[N][N],dp[N][N][N<<1],n,m;
int main(){
	memset(dp,0,sizeof(dp));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>graph[i][j];
		}
	}
	for(int k=1;k<=n+m-3;k++)
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue; 
			dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]);
			dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]);
			dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]);
			dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]);
			dp[i][j][k]+=graph[i][k+2-i]+graph[j][k+2-j];
		}
	}
	cout<<dp[n-1][n][n+m-3]<<endl;
}
