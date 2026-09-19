#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
const ll P=998244353;
ll n,a[N],m,q,mul[N],add[N][2],cnt[N],vis[N],in[N];
vector<ll> G1[N];
queue<ll> que;
void dfs(ll node){
    if(vis[node])return;
    for(ll i:G1[node]){
        dfs(i);
        mul[node]=mul[node]*mul[i]%P;
    }
    vis[node]=1;
    return;
}
void topol(){
    for(ll i=0;i<=m;i++){
        if(in[i]==0)que.push(i);
    }
    cnt[0]=1;
    while(!que.empty()){
        ll u=que.front();
        ll now=cnt[u];
        que.pop();
        for(ll i=G1[u].size()-1;i>=0;i--){
            ll v=G1[u][i];
            cnt[v]=(cnt[v]+now)%P;
            now=now*mul[v]%P;
            in[v]--;
            if(in[v]==0)que.push(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(ll i=1;i<=m;i++){
        ll op;cin>>op;
        if(op==1)cin>>add[i][0]>>add[i][1],mul[i]=1,vis[i]=1;
        else if(op==2)cin>>mul[i],vis[i]=1;
        else{
            ll k;cin>>k;
            for(ll j=1;j<=k;j++){
                ll node;cin>>node;
                G1[i].push_back(node);
                in[node]++;
            }
            mul[i]=1;
        }
    }
    cin>>q;
    mul[0]=1;
    for(ll i=1;i<=q;i++){
        ll node;cin>>node;
        G1[0].push_back(node);
        in[node]++;
    }
    dfs(0);
    topol();
    for(ll i=1;i<=n;i++)a[i]=a[i]*mul[0]%P;
    for(ll i=1;i<=m;i++)
        if(add[i][0])a[add[i][0]]=(a[add[i][0]]+add[i][1]*cnt[i]%P)%P;
    for(ll i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}