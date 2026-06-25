#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=3e5+10;
ll n,l[N],f[N][20],g[N][20];
void init(){
    f[n][0]=l[n];
    for(ll i=n;i>=1;i--)f[i][0]=min(f[i+1][0],l[i]),g[i][0]=i-f[i][0];
    for(ll i=1;i<=19;i++){
        for(ll j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]][i-1];
            g[j][i]=g[j][i-1]+g[f[j][i-1]][i-1]+(f[j][i-1]-f[j][i])*(1<<(i-1));
        }
    }
}
ll solve(ll x,ll to){
    if(l[x]<=to)return x-to;
    ll ans=0;
    for(ll i=19;i>=1;i--){

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>l[i];

    return 0;
}