#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
ll jm[110],jmr[110],dp[100][10000],n,m;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll a){
	return qpow(a,mod-2);
}
void init(){
	jm[0]=1;
	jmr[0]=1;
	for(int i=1;i<=100;i++){
		jm[i]=(jm[i-1]*i)%mod;
	}
	for(int i=1;i<=100;i++){
		jmr[i]=inv(jm[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=m;
	}
}
ll C(ll n,ll m){
	return ((jm[n]*jmr[n-m])%mod*jmr[m])%mod;
}
int main(){
	cin>>n>>m;
	init();
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m*(i-1)+1;j++){
			for(int k=0;k<=m;k++){
				if(k>j-1)break;
				dp[i][j]+=((dp[i-1][j-k]*C(m,k))%mod*qpow(j-k,k))%mod;
				dp[i][j]%=mod;
			}
		} 
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m*(i-1)+1;j++){
			ans+=dp[i][j];
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
