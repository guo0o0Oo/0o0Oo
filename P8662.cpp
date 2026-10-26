#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,flag,d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vis[2000][2000];
bool G[2000][2000];
void bfs(ll x,ll y){
    queue<pr> q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty()){
        pr t=q.front();q.pop();
        ll tx=t.first,ty=t.second;
        if(G[tx+1][ty]&&G[tx-1][ty]&&G[tx][ty+1]&&G[tx][ty-1])flag=1;
        for(ll i=0;i<4;i++){
            ll nx=tx+d[i][0],ny=ty+d[i][1];
            if(!vis[nx][ny]&&G[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            char ch;cin>>ch;
            G[i][j]=(ch=='#');
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(!vis[i][j]&&G[i][j]){
                flag=0;
                bfs(i,j);
                if(!flag)ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}