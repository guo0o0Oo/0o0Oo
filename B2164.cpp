#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
ll jm[5010],jmr[5010];
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
	for(int i=1;i<=5000;i++){
		jm[i]=(jm[i-1]*i)%mod;
	}
	for(int i=1;i<=5000;i++){
		jmr[i]=inv(jm[i]);
	}
}
ll C(ll n,ll m){
	return ((jm[n]*jmr[n-m])%mod*jmr[m])%mod;
}
int main(){
	init();
	int n,m;
	cin>>n>>m;
	cout<<C(n,m)<<endl;
	return 0;
} 
