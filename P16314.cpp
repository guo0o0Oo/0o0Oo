#include<bits/stdc++.h>
using namespace std;
using ll=int;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
vector<ll> G[1000010];
ll x,y;
ll f[1000010],d[1000010];//d[i]==1->同,d[i]==0->异
inline void initandread(){
    cin>>x>>y;
    string s;
    for(ll i=0;i<=y;i++)if(!G[i].empty())G[i].clear();
    for(ll i=1;i<=x;i++)f[i]=i,d[i]=1;
    for(ll i=1;i<=x;i++){
        cin>>s;
        for(ll j=1;j<=y;j++)if(s[j-1]=='1')G[j].push_back(i);
    }
}
ll root(ll a){
    if(f[a]!=a){
        ll old=f[a];
        f[a]=root(f[a]);
        d[a]=d[a]^d[f[a]];
    }
    return f[a];
}
bool unity(ll a,ll b,bool op){
    ll fa=root(a),fb=root(b);
    if(fa==fb){
        if(d[a]^d[b]!=op)return false;
        return true;
    }
    f[fa]=fb;
    d[fa]=op;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        initandread();
        for(ll i=1;i<=x/2;i++){
            if()
        }
    }
    return 0;
}