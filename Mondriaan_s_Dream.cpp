#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[2][1<<11];
ll now,old;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,m;
    while(cin>>n>>m&&n){
        if(m>n)swap(n,m);
        memset(dp,0,sizeof(dp));
        now=0;old=1;
        dp[now][(1<<m)-1]=1;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                swap(old,now);
                memset(dp[now],0,sizeof(dp[now]));
                for(ll k=0;k<(1<<m);k++){
                    if(k&(1<<(m-1)))
                        dp[now][(k<<1)&(~(1<<m))]+=dp[old][k];
                    if(i&&(!(k&(i<<(m-1)))))
                        dp[now][(k<<1)|1]+=dp[old][k];
                    if(j&&(!(k&1))&&(k&(1<<(m-1))))
                        dp[now][((k<<1)|3)&(~(1<<m))]+=dp[old][k];
                }
            }
        }
        cout<<dp[now][(1<<m)-1]<<"\n";
    }
    return 0;
}