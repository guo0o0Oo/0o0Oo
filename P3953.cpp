#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
vector< pair<ll,ll> > edge[N];
priority_queue< pair<ll,ll> , vector< pair<ll,ll> >, greater< pair<ll,ll> > > node;
ll dis[N];
void dijkstra(){
    node.push({0,1});
    while(!node.empty()){
        ll pos=node.top().second;
        ll len=node.top().first;
        node.pop();
        if(dis[pos]!=INF)continue;
        dis[pos]=len;
        for(auto i:edge[pos])
            if(dis[i.second]==INF)node.push({len+i.first,i.second});
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        ll n,m,k,p;
        cin>>n>>m>>k>>p;
        for(ll i=1;i<=n;i++)edge[i].clear();
        while(!node.empty())node.pop();
        memset(dis,INF,sizeof(dis));
        ll a,b,c;
        bool zero_edge=0;
        for(ll i=1;i<=m;i++){
            cin>>a>>b>>c;
            edge[a].push_back({c,b});
            edge[b].push_back({c,a});
            if(c==0)zero_edge=1;
        }
        if(zero_edge){
            cout<<-1<<"\n";
            continue;
        }
        cout<<1<<endl;
    }
    return 0;
}