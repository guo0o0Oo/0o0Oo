#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1010;
ll n,a[N][N],vis[N][N],now;//1shangu,2shanfeng,0wu
ll numfeng,numgu;
ll dir[8][2]={{-1,0},{-1,1},{-1,-1},{0,-1},{0,1},{1,0},{1,1},{1,-1}};
void dfs(ll x,ll y){
    if(vis[x][y])return;
    vis[x][y]=1;
    for(ll i=0;i<8;i++){
        ll nx=dir[i][0]+x,ny=dir[i][1]+y;
        if(nx<1||nx>n||ny<1||ny>n)continue;
        if(a[nx][ny]>a[x][y]){
            if(now==-1)now=1;
            else if(now==2)now=0;
        }
        if(a[nx][ny]<a[x][y]){
            if(now==-1)now=2;
            else if(now==1)now=0;
        }
        if(a[nx][ny]==a[x][y]){
            dfs(nx,ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll k,te=1;
    for(ll i=1;i<=n;i++)
    for(ll j=1;j<=n;j++){
        cin>>a[i][j];
        if(i==1&&j==1)k=a[i][j];
        else if(a[i][j]!=k)te=0;
    }
    if(te){
        cout<<1<<" "<<1<<"\n";
        return 0;
    }
    for(ll i=1;i<=n;i++)
    for(ll j=1;j<=n;j++){
        now=-1;
        dfs(i,j);
        if(now==1)numgu++;
        if(now==2)numfeng++;
    }
    cout<<numfeng<<" "<<numgu<<"\n";
    return 0;
}