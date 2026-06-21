#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1010;
const int mod=998244353;
ll a[N][N];
ll rght[N][N];
ll down[N][N];
int main(){
	ll t,id;scanf("%lld %lld",&t,&id);
	while(t--){
		char ch;
		ll n,m,c,f;scanf("%lld %lld %lld %lld",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ch;
				a[i][j]=ch-'0';
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(a[i][j]){
					down[i][j]=0;
					rght[i][j]=0;
					continue;
				}
				int d=1,r=1;
				if(i==n){down[i][j]=1-a[i][j];d=0;}
				if(j==m){rght[i][j]=1-a[i][j];r=0;}
				if(d)down[i][j]=down[i+1][j]+1;
				if(r)rght[i][j]=rght[i][j+1]+1;
			}
		}
		ll cans=0,fans=0;
		for(int j=1;j<m;j++){
			ll msl=0,sl=0;
			for(int i=1;i<=n;i++){
				if(down[i][j]==0){
					sl=0;
					msl=0;
				}
				if(rght[i][j]==0||rght[i][j]==1){
					msl=sl;
					continue;
				}
				cans+=msl*(rght[i][j]-1);
				fans+=msl*(rght[i][j]-1)*(down[i][j]-1);
				cans%=mod;
				fans%=mod;
				msl=sl;
				sl+=(rght[i][j]-1);
				sl%=mod;
			}
		}
		printf("%lld %lld\n",(cans*c)%mod,(fans*f)%mod);
	}
}
