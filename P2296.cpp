#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int> G[N],G2[N];
bool yes[N],vis[N],vis2[N];
int du[N];
void dfs(int s){
	if(vis2[s])return;
	vis2[s]=true;
	for(int i=0;i<G2[s].size();i++){
		du[G2[s][i]]--;
		if(du[G2[s][i]]==0)yes[G2[s][i]]=true;
		dfs(G2[s][i]);
	}
}
int bfs(int s,int t){
	queue<pair<int,int> > q;
	q.push({s,0});
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		if(vis[u.first]||!yes[u.first])continue;
		vis[u.first]=true;
		if(u.first==t)return u.second;
		for(int i=0;i<G[u.first].size();i++){
			int v=G[u.first][i];
			if(yes[v])q.push({v,u.second+1});
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G2[b].push_back(a);
		du[a]++;
	}
	int s,t;
	cin>>s>>t;
	yes[t]=1;
	dfs(t);
	cout<<bfs(s,t); 
	return 0;
}
