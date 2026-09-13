#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,dep[200010],vis[200010];
vector<ll> edge[200010];
void dfs(ll node)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(ll i=1;i<=n;i++){
            edge[i].clear();
        }
        for(ll i=1;i<=m;i++){
            ll a,b;
            cin>>a>>b;
            edge[a].push_back(b);
        }
    }
    return 0;
}