#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=10010;
ll n,m,b;
struct edge{
    ll from,to,w;
    edge(ll a,ll b,ll c){from=a;to=b;w=c;}
};
vector<edge> e[N];
struct node{
    ll id,dis;
    node(ll a,ll b){id=a;dis=b;}
    bool operator < (const node&a)const{
        return dis>a.dis;
    }
};
priority_queue<node> q;
ll dis[N],f[N];
bool done[N];
void dijkstra(ll minf){
    for(ll i=1;i<=n;i++)dis[i]=sup,done[i]=0;
    while(!q.empty())q.pop();
    dis[1]=0;
    q.push(node(1,dis[1]));
    while(!q.empty()){
        node u=q.top();
        q.pop();
        if(done[u.id]||f[u.id]>minf)continue;
        done[u.id]=1;
        for(edge j:e[u.id]){
            if(done[j.to]||f[j.to]>minf)continue;
            if(dis[j.to]>u.dis+j.w){
                dis[j.to]=u.dis+j.w;
                q.push(node(j.to,dis[j.to]));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>b;
    for(ll i=1;i<=n;i++)cin>>f[i];
    for(ll i=1;i<=m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        e[a].push_back(edge(a,b,c));
        e[b].push_back(edge(b,a,c));
    }
    ll l=0,r=ll(1e9+10);
    while(l<r){
        ll mid=(l+r)>>1;
        dijkstra(mid);
        if(dis[n]<=b)r=mid;
        else l=mid+1;
    }
    if(l>1e9)cout<<"AFK\n";
    else cout<<l<<"\n";
    return 0;
}