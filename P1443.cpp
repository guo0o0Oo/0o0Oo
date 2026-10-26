#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,xx,yy;
ll dis[500][500],d[8][2]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
void bfs(ll x,ll y){
    queue<pr> q;
    q.push({x,y});
    dis[x][y]=0;
    while(!q.empty()){
        pr t=q.front();q.pop();
        ll tx=t.first,ty=t.second;
        ll dep=dis[tx][ty]+1;
        for(ll i=0;i<8;i++){
            ll nx=tx+d[i][0],ny=ty+d[i][1];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&dis[nx][ny]==-1){
                dis[nx][ny]=dep;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>xx>>yy;
    for(ll i=1;i<=n;i++)
    for(ll j=1;j<=m;j++)
    dis[i][j]=-1;
    dis[xx][yy]=1;
    bfs(xx,yy);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++)
            cout<<dis[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}