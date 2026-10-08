#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,w[N],need[N];
vector<ll> G[N];
vector<pair<ll,ll> > chi[N];
bool cmp(const pair<ll,ll>& a,const pair<ll,ll>& b){
    if(a.first+b.second<b.first+a.second){
        return 0;
    }
    else if(a.first+b.second>b.first+a.second){
        return 1;
    }
    else return a.second<b.second;
}
void dfs(ll node,ll fa){
    for(ll i:G[node]){
        if(i==fa)continue;
        dfs(i,node);
        chi[node].push_back({need[i],w[i]});
    }
    if(chi[node].size()==0){
        need[node]=w[node];
        return;
    }
    sort(chi[node].begin(),chi[node].end(),cmp);
    ll cnt=0;
    for(ll i=0;i<chi[node].size();i++){
        need[node]=max(need[node],chi[node][i].first+cnt);
        cnt+=chi[node][i].second;
    }
    need[node]=max(need[node],w[node]+cnt);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=2;i<=n;i++){
        ll x;cin>>x;
        G[x].push_back(i);
        G[i].push_back(x);
    }
    for(ll i=1;i<=n;i++)cin>>w[i];
    dfs(1,0);
    for(ll i=1;i<=n;i++)cout<<need[i]<<" ";
    return 0;
}