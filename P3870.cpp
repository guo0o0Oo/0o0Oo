#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
int t[N<<2],tag[N<<2];
int ls(int p){return p*2;}
int rs(int p){return p*2+1;}
void pushup(int p){
	t[p]=t[ls(p)]+t[rs(p)];
}
void pushdown(int p,int pl,int pr){
	if(tag[p]){
		int mid=(pl+pr)>>1;
		tag[ls(p)]=!tag[ls(p)];
		t[ls(p)]=mid-pl+1-t[ls(p)];
		tag[rs(p)]=!tag[rs(p)];
		t[rs(p)]=pr-mid-t[rs(p)];
		tag[p]=0;
	}
}
void change(int p,int pl,int pr,int L,int R){
	pushdown(p,pl,pr);
	if(L<=pl&&pr<=R){
		tag[p]=1;
		t[p]=pr-pl+1-t[p]; 
		return ;
	}
	if(pl>R||pr<L){
		return ;
	}
	int mid=(pl+pr)>>1;
	change(ls(p),pl,mid,L,R);
	change(rs(p),mid+1,pr,L,R);
	pushup(p);
}
int ask(int p,int pl,int pr,int L,int R){
	pushdown(p,pl,pr);
	if(L<=pl&&pr<=R){
		return t[p];
	}
	if(pl>R||pr<L){
		return 0;
	}
	int mid=(pl+pr)>>1;
	return ask(ls(p),pl,mid,L,R)+ask(rs(p),mid+1,pr,L,R);
}
int main(){
	int n,m,c,a,b;
	cin>>n>>m;
	while(m--){
		cin>>c>>a>>b;
		if(c==0)change(1,1,n,a,b);
		else cout<<ask(1,1,n,a,b)<<"\n";
	} 
	return 0;
}
