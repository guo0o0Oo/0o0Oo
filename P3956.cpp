#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<pair<ll,ll>,pair<ll,ll> >;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll m,n;
ll g[110][110],done[110][110][3],dis[110][110][3],d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
priority_queue<pr,vector<pr>,greater<pr> > pq;
void bfs(ll x,ll y){
    dis[x][y][g[x][y]]=0;
    pq.push({{0,g[x][y]},{x,y}});
    while(!pq.empty()){
        pr t=pq.top();pq.pop();
        ll tx=t.second.first,ty=t.second.second,v=t.first.first,col=t.first.second;
        if(done[tx][ty][col])continue;
        for(ll i=0;i<4;i++){
            ll nx=tx+d[i][0],ny=ty+d[i][1];
            if(nx>0&&nx<=m&&ny>0&&ny<=m){
                if(g[nx][ny]==0){
                    if(g[tx][ty]==0)continue;
                    if(col==1){
                        if(dis[nx][ny][1]>v+2){
                            dis[nx][ny][1]=v+2;
                            pq.push({{v+2,1},{nx,ny}});
                        }
                        if(dis[nx][ny][2]>v+3){
                            dis[nx][ny][2]=v+3;
                            pq.push({{v+3,2},{nx,ny}});
                        }
                    }
                    if(col==2){
                        if(dis[nx][ny][2]>v+2){
                            dis[nx][ny][2]=v+2;
                            pq.push({{v+2,2},{nx,ny}});
                        }
                        if(dis[nx][ny][1]>v+3){
                            dis[nx][ny][1]=v+3;
                            pq.push({{v+3,1},{nx,ny}});
                        }
                    }
                }
                else{
                    if(g[nx][ny]==col){
                        if(dis[nx][ny][g[nx][ny]]>v){
                            dis[nx][ny][g[nx][ny]]=v;
                            pq.push({{v,g[nx][ny]},{nx,ny}});
                        }
                    }
                    else{
                        if(dis[nx][ny][g[nx][ny]]>v+1){
                            dis[nx][ny][g[nx][ny]]=v+1;
                            pq.push({{v+1,g[nx][ny]},{nx,ny}});
                        }
                    }
                    
                }
            }
        }
        done[tx][ty][col]=1;
        if(tx==m&&ty==m)break;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>m>>n;
    while(n--){
        ll x,y,c;
        cin>>x>>y>>c;
        g[x][y]=c+1;
    }
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=m;j++){
            for(ll k=0;k<=3;k++){
                dis[i][j][k]=inf;
            }
        }
    }
    bfs(1,1);
    ll ans=min(dis[m][m][1],dis[m][m][2]);
    if(ans==inf){
        cout<<"-1"<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }
    return 0;
}