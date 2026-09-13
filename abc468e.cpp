#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
ll n,a[500010],k[500010],ans;
ll qp(ll x,ll y){
    ll res=1,po=x;
    while(y){
        if(y&1)res=(res*po)%MOD;
        po=(po*po)%MOD;
        y>>=1;
    }
    return res;
}
ll inv(ll x){
    return qp(x,MOD-2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)k[1]=(k[1]+inv(i))%MOD;
    for(ll i=2;i<=(n+1)/2;i++)k[i]=(k[i-1]-inv(i-1)-inv(n-i+2)+MOD+MOD)%MOD;
    for(ll i=1;i<=(n+1)/2;i++)k[i]=(k[i]+k[i-1])%MOD,k[n-i+1]=k[i];
    for(ll i=1;i<=n;i++)ans=(ans+k[i]*a[i]%MOD)%MOD;
    cout<<ans<<"\n";
    return 0;
}