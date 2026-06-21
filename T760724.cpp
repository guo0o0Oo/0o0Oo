#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
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
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll a;
    cin>>a;
    ll k=1;
    for(ll i=1;i<=a;i++){k*=i;k%=MOD;}
    ll ans=(((k*(a-2)+1)%MOD)*Pow(k,MOD-2,MOD))%MOD;
    cout<<ans<<"\n";
    return 0;
}