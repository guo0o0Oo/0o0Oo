#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll x[1010],y[1010],z[1010];
bool vis[1010],ans;
queue<ll> qe;
bool ifget(ll a,ll b,ll r){
    ll dis=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])+(z[a]-z[b])*(z[a]-z[b]);
    return dis<=4*r*r;
}
void init(ll n,ll h,ll r){
    for(ll i=1;i<=n;i++){
        if(z[i]-r<=0){
            qe.push(i);
            vis[i]=1;
        }
    }
}
void bfs(ll n,ll h,ll r){
    init(n,h,r);
    while(!qe.empty()){
        ll k=qe.front();
        if(z[k]+r>=h){
            ans=1;
            return;
        }
        for(ll i=1;i<=n;i++){
            if(!vis[i]&&ifget(k,i,r)){
                qe.push(i);
                vis[i]=1;
            }
        }
        qe.pop();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        while(!qe.empty())qe.pop();
        ans=0;
        ll n,h,r;
        cin>>n>>h>>r;
        for(ll i=1;i<=n;i++){
            cin>>x[i]>>y[i]>>z[i];
        }
        bfs(n,h,r);
        if(ans){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}