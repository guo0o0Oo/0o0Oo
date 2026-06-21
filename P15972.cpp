#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
ll n,m,du[N];
set<ll> edge[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll x,y,ans=1;
    for(ll i=1;i<=m;i++){
        cin>>x>>y;
        if(x==y)continue;
        if(edge[x].find(y)==edge[x].end()){
            edge[x].insert(y);
            edge[y].insert(x);
            du[x]++;
            du[y]++;
            ans=max(ans,du[x]+1);
            ans=max(ans,du[y]+1);
        }
    }
    cout<<ans;
    return 0;
}