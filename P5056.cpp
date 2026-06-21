#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1594323;
ll dp[2][N+1],n,m;
bool G[13][13];
void init(){
    char ch;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>ch;
            if(ch=='*')G[i][j]=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int old=0,now=1;
    dp[now][0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            swap(old,now);
            memset(dp[now],0,sizeof(dp[now]));
            for(ll k=0;k<=N;k++){
                if(G[i][j]){
                    if()
                }
            }
        }
    }
    return 0;
}