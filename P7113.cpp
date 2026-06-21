#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
unsigned long long n,m,edge[MAXN][6],ansp[MAXN],ansq[MAXN];
long long gcd(long long p,long long q){
	if(q==0)return p;
	return gcd(q,p%q);
}
long long lcm(long long p,long long q){
	return p/gcd(p,q)*q;
}
void ans_add(int node,long long p,long long q){
	long long data=gcd(ansp[node],ansq[node]);
	ansp[node]/=data;
	ansq[node]/=data;
	data=lcm(ansq[node],q);
	ansp[node]=ansp[node]*(data/ansq[node])+p*(data/q);
	ansq[node]=data;
	data=gcd(ansp[node],ansq[node]);
	ansp[node]/=data;
	ansq[node]/=data;
}
void solve(int node,long long p,long long q){
	long long data=gcd(p,q);
	p/=data;
	q/=data;
	if(edge[node][0]==0){
		ans_add(node,p,q);
		return;
	}
	for(int i=1;i<=edge[node][0];i++){
		solve(edge[node][i],p,q*edge[node][0]);
	}
}
int main(){
	memset(ansp,0,sizeof(ansp));
	for(int i=0;i<=MAXN;i++)ansq[i]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>edge[i][0];
		for(int j=1;j<=edge[i][0];j++){
			cin>>edge[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		solve(i,1,1);
	}
	for(int i=1;i<=n;i++){
		if(edge[i][0]==0){
			cout<<ansp[i]<<" "<<ansq[i]<<endl;
		}
	}
}
