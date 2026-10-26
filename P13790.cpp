#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll K1=998244353;
const ll K2=1e6+7;
const ll MOD1=91451419;
const ll MOD2=99198107;
string s;
ll n,haha1[1000010],haha2[1000010],pk1[1000010],pk2[1000010];
void init(){
    ll res=0;
    pk1[0]=1;
    pk2[0]=1;
    for(ll i=1;i<=n;i++){
        haha1[i]=(haha1[i-1]*K1%MOD1+s[i])%MOD1;
        haha2[i]=(haha2[i-1]*K2%MOD2+s[i])%MOD2;
        pk1[i]=pk1[i-1]*K1%MOD1;
        pk2[i]=pk2[i-1]*K2%MOD2;
    }
}
ll hahaha1(ll l,ll r){
    return (haha1[r]-haha1[l-1]*pk1[r-l+1]%MOD1+MOD1)%MOD1;
}
ll hahaha2(ll l,ll r){
    return (haha2[r]-haha2[l-1]*pk2[r-l+1]%MOD2+MOD2)%MOD2;
}
ll fd(ll pos,ll sz){
    ll l=0,r=n-pos;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(hahaha1(n-sz+1,pos+mid)==hahaha1(1,pos+sz-n+mid)&&hahaha2(n-sz+1,pos+mid)==hahaha2(1,pos+sz-n+mid))l=mid;
        else r=mid-1;
    }
    return pos+l;
}
ll solve(ll sz){
    ll pos=n-sz;
    pos=fd(pos,sz);
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();
    s='@'+s;
    init();
    ll ans;
    for(ll i=1;i<=n-1;i++){
    }
    return 0;
}