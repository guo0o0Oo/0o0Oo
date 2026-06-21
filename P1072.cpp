#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll GCD(ll a,ll b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return GCD(b,a%b);
}
ll LCM(ll a,ll b){
	return (a*b)/GCD(a,b);
}
int main(){
	ll n,a0,a1,b0,b1,ans;
	cin>>n;
	while(n--){
		ans=0;
		cin>>a0>>a1>>b0>>b1;
		if(b1%a1){
			cout<<0<<"\n";
			continue;
		}
		for(ll i=1;i<=sqrt(b1);i++){
			if(b1%i==0){
				if(i*i==b1){
					if(GCD(i,a0)==a1&&LCM(i,b0)==b1){
						ans++;
					}
					continue;
				}
				i=b1/i;
				if(GCD(i,a0)==a1&&LCM(i,b0)==b1){
					ans++;
				}
				i=b1/i;
				if(GCD(i,a0)==a1&&LCM(i,b0)==b1){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
