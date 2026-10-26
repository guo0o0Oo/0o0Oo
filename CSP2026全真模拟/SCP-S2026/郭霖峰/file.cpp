#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,sum[2000010],b[2000010],now,ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll a;cin>>a;
        sum[a]++;
        now+=i;
    }
    for(ll i=2000000;i>=1;i--){
        sum[i]+=sum[i+1];
    }
    for(ll i=1;i<=m;i++){
        ll s;cin>>s;
        for(ll j=1;j<=s;j++){
            ll a;cin>>a;
            b[i]+=sum[a];
        }
    }
    sort(b+1,b+m+1);
    for(ll i=1;i<=m;i++){
        now+=b[i];
        ans+=now;
    }
    cout<<ans<<"\n";
}