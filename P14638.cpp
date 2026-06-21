#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
const int N=5e4+10;
ull n,L,R;
ll res[N],a[N];
void print(){
	ull ans=0,data;
	for(ull i=1;i<=n;i++){
		data=res[i]>0?res[i]:res[i]+(1<<64);
		ans^=data*i;
	}
	cout<<ans<<"\n";
}
void solve(){
	int t=L;
	while(t<=R){
		int l=1,r=l+t-1,sum;
		while(r<=n){
			for(int i=l;i<=r;i++){
				res[i]=max(res[i],a[r]-a[l-1]);
			}
			l++;
			r++;
		}
		t++;
	}
	print();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	int q;cin>>q;
	while(q--)
	{
		for(int i=1;i<=n;i++){
			res[i]=LONG_LONG_MIN;
		}
		cin>>L>>R;
		solve();
	}
} 
