#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,fa[2010],sum[2010],hp[2010],dp[2010][2010][3][3];
void dfs(ll pos){
    for(ll i=0;i<=n;i++){
        if(dp[fa[pos]][i][0][1]!=INF||dp[fa[pos]][i][0][0]!=INF)
        dp[pos][i][0][0]=min(dp[fa[pos]][i][0][1],dp[fa[pos]][i][0][0]);
        if(dp[fa[pos]][i][1][1]!=INF||dp[fa[pos]][i][1][0]!=INF)
        dp[pos][i][0][1]=min(dp[fa[pos]][i][1][1],dp[fa[pos]][i][1][0]);
        if(dp[fa[pos]][i-1][0][1]!=INF||dp[fa[pos]][i-1][0][0]!=INF)
        dp[pos][i][1][0]=min(dp[fa[pos]][i-1][0][1]-sum[i]-2*hp[i],dp[fa[pos]][i-1][0][0]);
        if(dp[fa[pos]][i-1][1][1]!=INF||dp[fa[pos]][i-1][1][0]!=INF)
        dp[pos][i][1][1]=min(dp[fa[pos]][i-1][1][1]-sum[i]-hp[i],dp[fa[pos]][i-1][1][0]);
    }
    for(ll i=1;i<=n;i++){
        if(fa[i]==pos){
            dfs(i);
            for()
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        memset(sum,0,sizeof(sum));
        memset(fa,0,sizeof(fa));
        memset(hp,0,sizeof(hp));
        memset(dp,INF,sizeof(dp));
        cin>>n;
        for(ll i=2;i<=n;i++)cin>>fa[i];
        for(ll i=1;i<=n;i++){
            cin>>hp[i];
            sum[fa[i]]+=hp[i];
        }
        for(ll i=1;i<=n;i++)dp[1][0][0][0]+=hp[i]*2;
        dp[1][0][0][0]-=hp[1];
        dfs(1);
    }
    return 0;
}