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
        if(k&1)res=res*a%MOD;
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
        if(n==1){
            cout<<0<<"\n";
            continue;
        }
        sort(s+1,s+m+1);
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
        if(cnt==1){
            ll res=qpow(v,2*(n-1));
            cout<<res<<"\n";
            continue;
        }
        ll sum=(t[cnt].first-t[1].first-(cnt-1)+MOD)%MOD;
        ll res=(qpow(v,2*(n-1))-qpow(v,sum)+MOD)%MOD;
        cout<<res<<"\n";
    }
    return 0;
}