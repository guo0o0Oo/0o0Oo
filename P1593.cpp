#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=9901;
ll a,b,ans=1,p[50000];
bool ifnp[50000];
vector<ll> pri;
void init(){
    for(ll i=2;i<50000;i++){
        if(!ifnp[i])pri.push_back(i);
        for(ll j:pri){
            if(i*j>=50000)break;
            ifnp[i*j]=1;
            if(i%j==0)break;
        }
    }
}
ll qpow(ll x,ll k){
    x=x%MOD;
    ll res=1;
    while(k){
        if(k&1)res=res*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return res;
}
ll inv(ll x){
    return qpow(x,MOD-2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b;
    init();
    for(ll i:pri){
        while(a%i==0){
            a/=i;
            p[i]++;
        }
        if(p[i])p[i]*=b;
    }
    for(ll i:pri){
        if(p[i]){
            if((i-1)%MOD==0)ans=ans*((1+p[i])%MOD)%MOD;
            else{
                ans=ans*(qpow(i,p[i]+1)-1+MOD)%MOD;
                ans=ans*inv(i-1)%MOD;
            }
        }
    }
    if(a>1){
        if((a-1)%MOD==0)ans=ans*((1+b)%MOD)%MOD;
        else{
            ans=ans*(qpow(a,b+1)-1+MOD)%MOD;
            ans=ans*inv(a-1)%MOD;
        }
    }
    cout<<ans<<"\n";
    return 0;
}