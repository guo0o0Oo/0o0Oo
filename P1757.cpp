#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll m,n,k;
ll v[110][1010],w[110][1010],dp[110][1010],sz[110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll a,b,c;
    cin>>m>>n;
    for(ll i=1;i<=n;i++){
        cin>>a>>b>>c;
        w[c][++sz[c]]=a;
        v[c][sz[c]]=b;
    }
    for(ll i=1;i<=100;i++){
        for(ll j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j]);
            for(ll k=1;k<=sz[i];k++){
                if(j>=w[i][k])dp[i][j]=max(dp[i-1][j-w[i][k]]+v[i][k],dp[i][j]);
            }
        }
    }
    cout<<dp[100][m]<<"\n";
    return 0;
}