#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
ll mult[2000010],invm[2000010];
ll inv(ll a){
    ll res=1,k=MOD-2;
    while(k){
        if(k&1)res=res*a%MOD;
        a=a*a%MOD;
        k>>=1;
    }
    return res;
}
void init(){
    mult[0]=1;
    for(ll i=1;i<=2000000;i++)mult[i]=mult[i-1]*i%MOD;
    invm[2000000]=inv(mult[2000000]);
    for(ll i=1999999;i>=1;i--)invm[i]=invm[i+1]*(i+1)%MOD;
    invm[0]=1;
}
ll C(ll m,ll n){
    return mult[n]*invm[n-m]%MOD*invm[m]%MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    ll T;	cin>>T;
    while(T--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a*2<=c){
            c-=2*a;
            cout<<C(a,a+b+c)*C(b,b+c)%MOD<<"\n";
        }
        else cout<<0<<"\n";
    }
    return 0;
}