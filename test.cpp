#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll MOD=1e9+7;
ll qpow(ll x,ll k){
    ll a=x,res=1;
    while(k){
        if(k&1){
            res=res*a%MOD;
        }
        a=a*a%MOD;
        k>>=1;
    }
    return res;
}
int main(){
	cout<<qpow(2,5);
    return 0;
}