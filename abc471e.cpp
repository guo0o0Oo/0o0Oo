#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=2e5+10;
const ll MOD=998244353;
ll n,k,a[N],sum,sum1,sum2,mut[N];
ll inv(ll a){
    ll res=1,po=a,b=MOD-2;
    while(b){
        if(b&1)res=res*po%MOD;
        po=po*po%MOD;
        b>>=1;
    }
    return res;
}
ll C(ll n,ll m){
    return mut[n]*inv(mut[m])%MOD*inv(mut[n-m])%MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    mut[0]=1;
    for(ll i=1;i<=n;i++)mut[i]=(mut[i-1]*i)%MOD;
    for(ll i=1;i<=n;i++)cin>>a[i],a[i]%=MOD;
    for(ll i=1;i<=n;i++)sum=(sum+a[i])%MOD,sum1=(sum1+a[i]*a[i]%MOD)%MOD;
    for(ll i=1;i<=n;i++)sum2=(sum2+a[i]*(sum-a[i]+MOD)%MOD)%MOD;
    if(k==1){cout<<sum1<<"\n";return 0;}
    ll ans=(sum1*C(n-1,k-1)%MOD+sum2*C(n-2,k-2)%MOD)%MOD;
    cout<<ans<<"\n";
    return 0;
}