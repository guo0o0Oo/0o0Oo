#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
ll n,m,v;
pair<ll,ll> s[100010],t[100010];
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
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;cin>>T;
    while(T--){
        cin>>n>>m>>v;
        for(ll i=1;i<=m;i++){
            cin>>s[i].first>>s[i].second;
        }
        sort(s+1,s+n+1);
        bool flag=0;
        ll cnt=0;
        t[++cnt]=s[1];
        for(ll i=2;i<=m;i++){
            if(s[i].first==s[i-1].first){
                if(s[i].second!=s[i-1].second){flag=1;break;}
                continue;
            }
            t[++cnt]=s[i];
        }
        if(flag){
            cout<<0<<"\n";
            continue;
        }
        ll sum=(t[m].first-t[1].first-(m-1))%MOD;
        ll res=(qpow(v,n)-qpow(v,sum)*qpow(v-1,m-1)%MOD+MOD)%MOD;
        cout<<res<<"\n";
    }
    return 0;
}