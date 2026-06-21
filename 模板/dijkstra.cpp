#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=3e5+10;
struct edge{
	ll from,to,w;
	edge(ll a,ll b,ll c){from=a;to=b;w=c;}
};
vector<edge> e[N];
struct node{
	ll id,dis;
	node(ll b,ll c){id=b;dis=c;}
	bool operator < (const node&a)const{
		return dis>a.dis;
	}
};
ll n,m,s;
ll dis[N];
bool done[N];
priority_queue<node> q;
void dijkstra(ll s){
	for(ll i=1;i<=n;i++)dis[i]=sup,done[i]=false;
	dis[s]=0;
	while(!q.empty())q.pop();
	q.push(node(s,dis[s]));
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(done[u.id])continue;
		done[u.id]=true;
		for(edge y:e[u.id]){
			if(done[y.to])continue;
			if(dis[y.to]>y.w+u.dis){
				dis[y.to]=y.w+u.dis;
				q.push(node(y.to,dis[y.to]));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)e[i].clear();
	while(m--){
		ll u,v,w;cin>>u>>v>>w;
		e[u].push_back(edge(u,v,w));
	}
	dijkstra(s);
	for(ll i=1;i<=n;i++){
		if(dis[i]>=sup)cout<<"-1 ";
		else cout<<dis[i]<<" ";
	}
	return 0;
}