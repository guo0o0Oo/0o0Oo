#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll K=998244353;
const ll MOD1=11451419;
const ll MOD2=19198106;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n;
string a[10010];
bool hahaha1[11451420],hahaha2[19198107];
ll haha1(const string &s){
    ll res=0;
    for(ll i=0;i<s.size();i++){
        res=(res*K+s[i])%MOD1;
    }
    return res;
}
ll haha2(const string &s){
    ll res=0;
    for(ll i=0;i<s.size();i++){
        res=(res*K+s[i])%MOD2;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll res=0;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++){
        ll ha1=haha1(a[i]),ha2=haha2(a[i]);
        if(!hahaha1[ha1]||!hahaha2[ha2]){
            res++;
            hahaha1[ha1]=1;
            hahaha2[ha2]=1;
        }
    }
    cout<<res<<"\n";
    return 0;
}