#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
ll a[N],sum[N],cnt[N],st[N],ed[N],pos[N];
void change(ll L,ll R){
	ll p=pos[L],q=pos[R];
	if(p==q){
		if(cnt[p])
		for(int i=L;i<=R;i++){
			if(a[i]==1)continue;
			sum[p]=sum[p]-a[i];
			a[i]=sqrt(a[i]);
			if(a[i]==1)cnt[p]--;
			sum[p]+=a[i];
		}
	}
	else{
		for(int i=p+1;i<=q-1;i++){
			if(!cnt[i])continue;
			for(int j=st[i];j<=ed[i];j++){
				if(a[j]==1)continue;
				sum[i]=sum[i]-a[j];
				a[j]=sqrt(a[j]);
				if(a[j]==1)cnt[i]--;
				sum[i]+=a[j];
			}
		}
		if(cnt[p])
		for(int i=L;i<=ed[p];i++){
			if(a[i]==1)continue;
			sum[p]=sum[p]-a[i];
			a[i]=sqrt(a[i]);
			if(a[i]==1)cnt[p]--;
			sum[p]+=a[i];
		}
		if(cnt[q])
		for(int i=st[q];i<=R;i++){
			if(a[i]==1)continue;
			sum[q]=sum[q]-a[i];
			a[i]=sqrt(a[i]);
			if(a[i]==1)cnt[q]--;
			sum[q]+=a[i];
		}
	}
}
ll ask(int L,int R){
	ll p=pos[L],q=pos[R],ans=0;
	if(p==q){
		for(int i=L;i<=R;i++)ans+=a[i];
	}
	else{
		for(int i=p+1;i<=q-1;i++)ans+=sum[i];
		for(int i=L;i<=ed[p];i++)ans+=a[i];
		for(int i=st[q];i<=R;i++)ans+=a[i];
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
			sum[i]+=a[j];
			if(a[j]!=1){
				cnt[i]++;
			}
		}
	}
	ll m;
	cin>>m;
	while(m--){
		int ch;
		cin>>ch;
		if(ch==0){
			int x,y;
			cin>>x>>y;
			if(x>y)swap(x,y);
			change(x,y);
		}
		else{
			int x,y;
			cin>>x>>y;
			if(x>y)swap(x,y);
			cout<<ask(x,y)<<"\n";
		}
	}
	return 0;
}
