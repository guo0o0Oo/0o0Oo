#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<pair<ll,ll>,pair<ll,ll> >;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,g[100][100],x,y,direct,xx,yy,dis[100][100][5],d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[100][100][5];
queue<pr> q;
bool ifc(ll px,ll py){
    if(g[px][py]&&g[px][py+1]&&g[px+1][py]&&g[px+1][py+1])return 1;
    else return 0;
}
void bfs(){
    q.push({{0,direct},{x,y}});
    dis[x][y][direct]=0;
    vis[x][y][direct]=1;
    while(!q.empty()){
        pr t=q.front();q.pop();
        ll v=t.first.first,dir=t.first.second,tx=t.second.first,ty=t.second.second;
        if(tx==xx&&ty==yy)break;
        ll nx=tx,ny=ty;
        for(ll i=0;i<3;i++){
            if(ifc(nx+d[dir][0],ny+d[dir][1])){
                nx+=d[dir][0];
                ny+=d[dir][1];
                if(!vis[nx][ny][dir]){
                    dis[nx][ny][dir]=v+1;
                    vis[nx][ny][dir]=1;
                    q.push({{v+1,dir},{nx,ny}});
                }
            }
            else break;
        }
        if(!vis[tx][ty][(dir+1)%4]){
            dis[tx][ty][(dir+1)%4]=v+1;
            vis[tx][ty][(dir+1)%4]=1;
            q.push({{v+1,(dir+1)%4},{tx,ty}});
        }
        if(!vis[tx][ty][(dir+3)%4]){
            dis[tx][ty][(dir+3)%4]=v+1;
            vis[tx][ty][(dir+3)%4]=1;
            q.push({{v+1,(dir+3)%4},{tx,ty}});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>g[i][j];
            g[i][j]=1-g[i][j];
            for(ll k=0;k<4;k++)dis[i][j][k]=inf;
        }
    }
    cin>>x>>y>>xx>>yy;
    char ch;cin>>ch;
    if(ch=='E')direct=0;
    else if(ch=='S')direct=1;
    else if(ch=='W')direct=2;
    else direct=3;
    bfs();
    ll ans=inf;
    for(ll i=0;i<4;i++){
        ans=min(ans,dis[xx][yy][i]);
    }
    if(ans==inf)cout<<"-1\n";
    else cout<<ans<<"\n";
    return 0;
}