#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,sum[5010][5010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll x,y,v;
        cin>>x>>y>>v;
        sum[x][y]+=v;
    }
    for(ll i=0;i<=5000;i++)
        for(ll j=1;j<=5000;j++)
            sum[i][j]+=sum[i][j-1];
    for(ll i=1;i<=5000;i++)
        for(ll j=0;j<=5000;j++)
            sum[i][j]+=sum[i-1][j];
    ll mx=-inf;
    for(ll i=m-1;i<=5000;i++){
        for(ll j=m-1;j<=5000;j++){
            if(i>m-1&&j>m-1){
                mx=max(sum[i][j]-sum[i-m][j]-sum[i][j-m]+sum[i-m][j-m],mx);
            }
            else if(i>m-1){
                mx=max(sum[i][j]-sum[i-m][j],mx);
            }
            else if(j>m-1){
                mx=max(sum[i][j]-sum[i][j-m],mx);
            }
        }
    }
    cout<<mx<<"\n";
    return 0;
}