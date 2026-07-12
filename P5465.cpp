#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=3e5+10;
ll n,q,l[N],f[N][20],g[N][20],p2[20];
void init(){
    p2[0]=1;
    for(ll i=1;i<20;i++)p2[i]=p2[i-1]<<1;
    f[n][0]=l[n];g[n][0]=n-f[n][0];
    for(ll i=n-1;i>=1;i--)f[i][0]=min(f[i+1][0],l[i]),g[i][0]=i-f[i][0];
    for(ll i=1;i<20;i++){
        for(ll j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]][i-1];
            g[j][i]=g[j][i-1]+g[f[j][i-1]][i-1]+(f[j][i-1]-f[j][i])*p2[i-1];
        }
    }
}
ll solve(ll x,ll to){
    if(l[x]<=to)return x-to;
    ll now=l[x],ans=0;
    for(ll i=19;i>=0;i--){
        if(f[now][i]>=to){
            ans+=g[now][i];
            now=f[now][i];
            ans+=(now-to)*p2[i];
        }
    }
    ans+=now-to+x-to;
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    l[1]=1;
    for(ll i=2;i<=n;i++)cin>>l[i];
    cin>>q;
    init();
    while(q--){
        ll a,b,c,k;
        cin>>a>>b>>c;
        k=b-a+1;
        ll res=solve(c,a)-solve(c,b+1);
        ll g=__gcd(res,k);
        cout<<res/g<<"/"<<k/g<<"\n";
    }
    return 0;
}