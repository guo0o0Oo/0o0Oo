#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
vector<ll> t[200010];
ll n,c[200010],num[200010],p2[200010];
ll build(ll k,ll last){
    ll res=0;
    for(auto i:t[k]){
        if(i==last)continue;
        res+=build(i,k);
    }
    num[k]=res;
    return res+1;
}
void init(){
    p2[0]=1;
    for(ll i=1;i<=n;i++)p2[i]=(p2[i-1]*2)%MOD;
}
ll dfs(ll k,ll last){
    ll res=1;
    if(c[k]&&t[k].size()==0)return 2;
    for(auto i:t[k]){
        if(i==last)continue;
        res=(res*dfs(i,k))%MOD;
    }
    if(c[k])res+=p2[num[k]];
    return res%MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>c[i];
    for(ll i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    build(1,0);
    init();
    cout<<dfs(1,0)<<"\n";
    return 0;
}