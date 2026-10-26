#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,d[500010],c;
vector<ll> G[500010];
priority_queue<pr> pq;
void bf(){
    c=0;
    while(!pq.empty()){
        pr t=pq.top();pq.pop();
        ll u=t.second,w=t.first;
        if(d[u]!=w)continue;
        c++;
        for(ll v:G[u]){
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                pq.push({w+1,v});
            }
        }
    }
}
int main(){
    ll task,t;
    cin>>task>>t;
    while(t--){
        cin>>n>>m;
        for(ll i=1;i<=n;i++)G[i].clear();
        d[n]=0;
        for(ll i=1;i<=n-1;i++)d[i]=inf;
        for(ll i=1;i<=m;i++){
            ll u,v;cin>>u>>v;
            u=n+1-u;v=n+1-v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        while(!pq.empty())pq.pop();
        pq.push({0,n});
        bf();
        cout<<c<<"\n";
    }
}