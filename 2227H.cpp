#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,root,sze[200010],ans;
vector<ll> t[200010];
ll init(ll node,ll last,ll dep){
    if(node!=root&&t[node].size()==1){
        ans+=dep;
        sze[node]=1;
        return 1;
    }
    ll res=0;
    for(auto i:t[node]){
        if(i==last)continue;
        res+=init(i,node,dep+1);
    }
    sze[node]=res;
    return res;
}
ll dfs(ll node,ll last,ll dep){
    if(sze[node]<2)return 0;
    for(auto i:t[node]){
        if(i==last)continue;
        sze[node]-=dfs(i,node,dep+1);
    }
    ll k=sze[node]/2;
    ans-=k*dep*2;
    return k*2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll s;	cin>>s;
    while(s--){
        cin>>n;
        for(ll i=1;i<=n;i++)t[i].clear();
        for(ll i=1;i<=n;i++)sze[i]=0;
        root=0;
        ans=0;
        for(ll i=1;i<n;i++){
            ll a,b;cin>>a>>b;
            t[a].push_back(b);
            t[b].push_back(a);
        }
        for(ll i=1;i<=n;i++){
            if(t[i].size()==1){
                root=i;
                break;
            }
        }
        init(root,0,0);
        dfs(root,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}