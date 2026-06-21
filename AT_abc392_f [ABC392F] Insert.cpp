#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define lowbit(x) ((x)&-(x))
int tree[N],a[N],op[N],n;
void update(int x,int d){
	while(x<=N){
		tree[x]+=d;
		x+=lowbit(x);
	}
}
int ask(int x){
	int ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int find(int cnt){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(ask(mid)>=cnt)	r=mid;
		else	l=mid+1;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)update(i,1);
	for(int i=1;i<=n;i++){
		cin>>op[i];
	}
	for(int i=n;i>0;i--){
		int pos=find(op[i]);
		a[pos]=i;
		update(pos,-1);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
