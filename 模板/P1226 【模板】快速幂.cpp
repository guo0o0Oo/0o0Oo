#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll Pow(ll n,ll m,ll p){
	ll res=1;
	n%=p;
	while(m){
		if(m&1)res=res*n%p;
		n=(n*n)%p;
		m=m>>1;
	}
	return res;
}
int main(){
	ll a,b,p;
	cin>>a>>b>>p;
	printf("%lld^%lld mod %lld=%lld",a,b,p,Pow(a,b,p));
	return 0;
}

