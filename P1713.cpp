#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}},maxl,minl=10000000000;
bool G[11][11];
void dfs(ll x,ll y,ll dep){
    if(x==1&&y==n){
        maxl=max(maxl,dep);
        minl=min(minl,dep);
        return;
    }
    G[x][y]=1;
    for(ll i=0;i<4;i++){
        if(1<=x+dir[i][0]&&x+dir[i][0]<=n&&1<=y+dir[i][1]&&y+dir[i][1]<=n&&!G[x+dir[i][0]][y+dir[i][1]]){
            dfs(x+dir[i][0],y+dir[i][1],dep+1);
        }
    }
    G[x][y]=0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll a,b;
    for(ll i=1;i<=m;i++){
        cin>>a>>b;
        G[a][b]=1;
    }
    dfs(n,1,1);
    cout<<maxl-minl<<"\n";
    return 0;
}