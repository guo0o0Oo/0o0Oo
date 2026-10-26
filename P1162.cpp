#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,G[100][100],vis1[100][100],vis2[100][100],d[4][2]={{1,0},{-1,0},{0,1},{0,-1}},flag;
void dfs(ll x,ll y){
    vis1[x][y]=1;
    if(x==n||x==1||y==n||y==1)flag=0;
    for(ll i=0;i<4;i++){
        ll tx=x+d[i][0],ty=y+d[i][1];
        if(!vis1[tx][ty]&&G[tx][ty])dfs(tx,ty);
    }
}
void col(ll x,ll y){
    vis2[x][y]=1;
    for(ll i=0;i<4;i++){
        ll tx=x+d[i][0],ty=y+d[i][1];
        if(!vis2[tx][ty]&&G[tx][ty])col(tx,ty);
    }
    G[x][y]=2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>G[i][j];
            G[i][j]=1-G[i][j];
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(!vis1[i][j]&&G[i][j]){
                flag=1;
                dfs(i,j);
                if(flag){
                    col(i,j);
                }
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(G[i][j]==1)cout<<0<<" ";
            else if(G[i][j]==0)cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<"\n";
    }
    return 0;
}