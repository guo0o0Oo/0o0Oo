#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
struct rel{
	int a,b,v;
	bool operator<(const rel& x)const{
		return v<x.v;
	}
};
int n,m,fa[N],vfa[N];
priority_queue<rel> pq;
int find(int x){
	if(x!=fa[x]){
		int t=find(fa[x]);
		vfa[x]^=vfa[fa[x]];
		fa[x]=t;
	}
	return fa[x];
}
void unite(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=find(fy);
	vfa[fx]=vfa[x]^vfa[y]^1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	int a,b,v;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>v;
		if(a>b)swap(a,b);
		pq.push({a,b,v});
	}
	while(!pq.empty()){
		int a=pq.top().a,b=pq.top().b;
		if(find(a)==find(b)&&vfa[a]==vfa[b]){
			cout<<pq.top().v<<"\n";
			return 0;
		}
		unite(a,b);
		pq.pop();
	}
	cout<<0<<"\n";
	return 0;
}

