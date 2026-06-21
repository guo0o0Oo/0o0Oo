#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
struct node{
	int value,x,y;
};
bool operator < (const node&a,const node&b){
	return a.value>b.value;
}
int dp[N][N],farm[N][N];
priority_queue<node> pr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,x0,y0,x,y,maxx=INT_MIN,maxy=INT_MIN;
	cin>>n>>x0>>y0;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		maxx=max(maxx,x);maxy=max(maxy,y);
		farm[x][y]=1;
	}
	maxx++;maxy++;
	for(int i=0;i<=maxx;i++){
		for(int j=0;j<=maxy;j++){
			dp[i][j]=-1;
		}
	}
	pr.push({0,0,0});
	int pos[4][2]={{0,-1},{-1,0},{0,1},{1,0}},nx,ny;
	while(pr.top().x!=x0||pr.top().y!=y0){
		while(dp[pr.top().x][pr.top().y]!=-1)pr.pop();
		if(pr.top().x==x0&&pr.top().y==y0)break;
		node data=pr.top();pr.pop();
		dp[data.x][data.y]=data.value;
		for(int i=0;i<4;i++){
			nx=data.x+pos[i][0];ny=data.y+pos[i][1];
			if(0<=nx&&nx<=maxx&&0<=ny&&ny<=maxy&&dp[nx][ny]==-1){
				pr.push({data.value+farm[nx][ny],nx,ny});
			}
		}
	}
	cout<<pr.top().value<<"\n";
	return 0;
}
/*
9 4 4
3 3
3 4
3 5
4 3
4 5
5 3
5 4
5 5
1000 1000
*/
//注：不是标准迪杰斯特拉，常数巨大 
