#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
ll n,k;
string s;
ll pw2(ll x){
    ll res=1,a=2;
    while(x){
        if(x&1)res=res*a%MOD;
        a=a*a%MOD;
        x>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n>>k>>s;
        ll p=1;
        for(ll i=s.size()-1;i>=0;i--){
            if(s[i]=='1')break;
            p++;
        }
        ll ans=0;
        for(ll i=k;i<p;i++){
            ans=(ans+pw2(i))%MOD;
        }
        cout<<ans<<"\n";
    }
    return 0;
}