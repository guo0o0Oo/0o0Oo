#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
ll a[N],m[N],st[N],ed[N],pos[N],beg[N],g[N];
void change(ll L,ll R,ll d){
	
	
	for(int i=1;i<=5;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n\n";
	
	
	ll p=pos[L],q=pos[R];
	if(p==q){
		for(int i=L;i<=R;i++){
			a[i]+=d;
			m[p]=max(a[i],m[p]);
		}
	}
	else{
		for(int i=p+1;i<=q-1;i++){
			add[i]+=d;
			m[i]+=d;
		}
		for(int i=L;i<=ed[p];i++){
			a[i]+=d;
			m[p]=max(a[i],m[p]);
		}
		for(int i=st[q];i<=R;i++){
			a[i]+=d;
			m[q]=max(a[i],m[p]);
		}
	}
	
	
	for(int i=1;i<=5;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n\n";
	
	
}
ll ask(int L,int R){
	ll p=pos[L],q=pos[R],ans=0;
	if(p==q){
		for(int i=L;i<=R;i++)ans=max(a[i]+add[p],ans);
	}
	else{
		for(int i=p+1;i<=q-1;i++)ans=max(m[i],ans);
		for(int i=L;i<=ed[p];i++)ans=max(a[i]+add[p],ans);
		for(int i=st[q];i<=R;i++)ans=max(a[i]+add[q],ans);
	}
	return ans;
}
int main(){
	ll n;
	cin>>n;
	int block=sqrt(n);
	int t=n/block;
	if(n%block)t++;
	for(int i=1;i<=t;i++){
		st[i]=(i-1)*block+1;
		ed[i]=i*block;
	}
	ed[t]=n;
	for(int i=1;i<=n;i++){
		pos[i]=(i-1)/block+1;
	}
	for(int i=1;i<=t;i++){
		for(int j=st[i];j<=ed[i];j++){
			cin>>a[j];
			a[j]+=a[j-1];
			m[i]=max(a[j],m[i]);
		}
	}
	ll m;
	cin>>m;
	while(m--){
		int ch;
		cin>>ch;
		if(ch==0){
			int x,y,k;
			cin>>x>>y>>k;
			change(x,y,k);
		}
		else{
			int x,y;
			cin>>x>>y;
			cout<<ask(x,y)<<"\n";
		}
	}
	return 0;
}

