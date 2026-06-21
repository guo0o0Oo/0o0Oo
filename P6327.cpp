#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
double t[N<<2][2],tag[N<<2],a[N];//t[][0]=sin,t[][1]=cos
int ls(int p){return p*2;}
int rs(int p){return p*2+1;}
void pushup(int p){
	t[p][0]=t[ls(p)][0]+t[rs(p)][0];
	t[p][1]=t[ls(p)][1]+t[rs(p)][1];
}
void pushdown(int p){
	if(tag[p]){
		double newsin=t[p][0]*cos(tag[p])+t[p][1]*sin(tag[p]);
		double newcos=t[p][1]*cos(tag[p])-t[p][0]*sin(tag[p]);
		t[p][0]=newsin;
		t[p][1]=newcos;
		tag[ls(p)]+=tag[p];
		tag[rs(p)]+=tag[p];
		tag[p]=0;
	}
}
void change(int p,int pl,int pr,int L,int R,int d){
	if(L<=pl&&pr<=R){
		tag[p]+=d;
		return ;
	}
	pushdown(p);
	if(pl>R||pr<L){
		return ;
	}
	int mid=(pl+pr)>>1;
	change(ls(p),pl,mid,L,R,d);
	change(rs(p),mid+1,pr,L,R,d);
	pushup(p); 
}
double ask(int p,int pl,int pr,int L,int R){
	pushdown(p);
	if(L<=pl&&pr<=R){
		return t[p][0];
	}
	if(pl>R||pr<L){
		return 0;
	}
	int mid=(pl+pr)>>1;
	return ask(ls(p),pl,mid,L,R)+ask(rs(p),mid+1,pr,L,R); 
}
void build(int p,int pl,int pr){
	if(pl==pr){
		t[p][0]=sin(a[pl]);
		t[p][1]=cos(a[pl]);
		return ;
	}
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	pushup(p);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	int m;
	cin>>m;
	int op,l,r,v;
	while(m--){
		cin>>op;
		if(op==1){
			cin>>l>>r>>v;
			change(1,1,n,l,r,v);
		}
		else{
			cin>>l>>r;
			printf("%.1f\n",ask(1,1,n,l,r));
		}
	}
	return 0;
}
