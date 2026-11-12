#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
vector<ll> dfn;
ll n,w[100010],ans;
vector<ll> G[100010];
void solve1(){
    ans=0;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>w[i];
    for(ll i=1;i<n;i++){
        ll a,b;cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(n<=10){
        solve1();
    }
    return 0;
}