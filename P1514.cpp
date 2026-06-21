#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,a[N][N],ifc[N],g[N][N],from[N][N],cnt[N],t=0;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int cover[N],ans=INT_MAX;
void dfs(int k,int x,int y){
	if(x==n)g[k][y]=1;
	if(x==1&&y!=k)ifc[y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[nx][ny]<a[x][y])
			dfs(k,nx,ny);
	}
}
void solve(int tot){
	t++;
	if(t>1e8)return;
	if(tot>ans)return;
//	for(int i=1;i<=m;i++){
//		cout<<cover[i]<<" ";
//	}
//	cout<<"\n";
	int k=1;
    while(k<=m&&cover[k])k++;
    if(k>m){
    	ans=min(ans,tot);
    	return;
    }
	for(int i=1;i<=cnt[k];i++){
		int s=from[k][i];
		vector<int> newcow;
		for(int j=1;j<=m;j++){
			if(g[s][j]&&!cover[j]){
				cover[j]=1;
				newcow.push_back(j);
			}
		}
		solve(tot+1);
		for(auto j:newcow){
			cover[j]=0;
		}
	}
}
bool cmp(int l,int r){
	return a[1][l]>a[1][r];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	int s[N];
	for(int i=1;i<=m;i++){
		s[i]=i;
	}
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(!ifc[s[i]])
		dfs(s[i],1,s[i]);
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j])
				from[j][++cnt[j]]=i;
	int reduce=0;
	for(int i=1;i<=m;i++)
		if(cnt[i]==0)
			reduce++;
	if(reduce){
		cout<<0<<"\n";
		cout<<reduce<<"\n";
		return 0;
	}
//	for(int k=1;k<=m;k++){
//		for(int i=1;i<=cnt[k];i++){
//			int s=from[k][i];
//			cout<<s<<" ";
//		}
//		cout<<"\n";
//	}
//	for(int i=1;i<=m;i++){
//	for(int j=1;j<=m;j++){
//		cout<<g[i][j]<<" ";
//	}
//	cout<<"\n";
//	}
	solve(0);
	cout<<1<<"\n";
	cout<<ans<<"\n";
	return 0;
}
