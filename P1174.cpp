#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=210;
ll v[N][N],give[N][N],next[N][N],dp[N][N][2],sy[N][N],sn[N][N];
ll n,m,k;
ll dfs(ll x,ll k,ll c){
	if(dp[x][k][c]!=-1)return dp[x][k][c];
	if(x==1){
		dp[x][k][c]=-1e18;
		if(c){
			for(int i=0;i<=min(n,k);i++)dp[x][k][c]=max(dp[x][k][c],sn[x][i]);
			return dp[x][k][c];
		}
		else{
			for(int i=0;i<=min(n,k);i++)dp[x][k][c]=max(dp[x][k][c],sy[x][i]);
			return dp[x][k][c];
		}
	}
	ll res=0;
	for(int i=0;i<=min(n,k);i++){
		ll newres=-1e18;
		if(c){
			if(k-i!=0)newres=dfs(x-1,k-i,1)+sy[x][i];
			if(i!=0)newres=max(newres,dfs(x-1,k-i,0)+sn[x][i]);
		}
		else{
			newres=dfs(x-1,k-i,0)+sy[x][i];
		}
		res=max(res,newres);
	}
	dp[x][k][c]=res;
	return res;
}
int main(){
	cin>>n>>m>>k;
	char giv;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>v[i][j]>>giv;
			if(giv=='Y'){
				give[i][j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=n;j>=1;j--){
			if(give[j][i]){
				sy[i][cnt]+=v[j][i];
			}
			else{
				cnt++;
				sy[i][cnt]=sy[i][cnt-1]+v[j][i];
				sn[i][cnt]=sy[i][cnt-1]+v[j][i];
			}
		}
		if(give[1][i]&&cnt<n)sn[i][cnt+1]=sy[i][cnt];
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(m,k,1);
	return 0;
}
