#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll dp[110][110],G[110][110],n,q;
ll ls[110],rs[110],lv[110],rv[110];
void init(ll node){
    ll flag=0;
    for(ll i=1;i<=n;i++){
        if(G[node][i]!=-1){
            if(flag){
                rs[node]=i;
                rv[node]=G[node][i];
                G[node][i]=-1;
                G[i][node]=-1;
                init(i);
            }
            else{
                ls[node]=i;
                lv[node]=G[node][i];
                G[node][i]=-1;
                G[i][node]=-1;
                flag=1;
                init(i);
            }
        }
    }
}
void dfs(ll node){
    if(ls[node]==0){
        dp[node][0]=0;
        for(ll i=1;i<=q;i++)dp[node][i]=inf;
        return;
    }
    dfs(ls[node]);dfs(rs[node]);
    for(ll i=1;i<=q;i++){
        dp[node][i]=max(dp[node][i],dp[ls[node]][i-1]+lv[node]);
        dp[node][i]=max(dp[node][i],dp[rs[node]][i-1]+rv[node]);
        for(ll j=0;j<=i-2;j++){
            dp[node][i]=max(dp[node][i],dp[ls[node]][j]+dp[rs[node]][i-2-j]+lv[node]+rv[node]);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    memset(G,-1,sizeof(G));
    for(ll i=1;i<=n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        G[x][y]=z;
        G[y][x]=z;
    }
    init(1);
    dfs(1);
    cout<<dp[1][q]<<"\n";
    return 0;
}