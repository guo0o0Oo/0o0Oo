#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
ll n,m,s;
char a[1010],b[1010];
ll dp[2][210][210][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=m;i++)cin>>b[i];
    int now=0,old=1;
    dp[0][0][0][0]=1;
    dp[1][0][0][0]=1;
    for(ll i=1;i<=n;i++){
        swap(now,old);
        for(ll j=1;j<=m;j++){
            for(ll k=1;k<=s;k++){
                if(a[i]==b[j]){
                    dp[now][j][k][0]=(dp[old][j][k][1]+dp[old][j][k][0])%MOD;
                    dp[now][j][k][1]=(dp[old][j-1][k][1]+dp[old][j-1][k-1][0]+dp[old][j-1][k-1][1])%MOD;
                }
                else{
                    dp[now][j][k][0]=(dp[old][j][k][1]+dp[old][j][k][0])%MOD;
                    dp[now][j][k][1]=0;
                }
            }
        }
    }
    cout<<(dp[now][m][s][0]+dp[now][m][s][1])%MOD;
    return 0;
}