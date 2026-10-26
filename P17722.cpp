#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,sum[1000010],addb[1000010];
ll ans=0,now=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll a;cin>>a;
        sum[a]++;
        now+=i;
    }
    for(ll i=1000000;i>=1;i--){
        sum[i]+=sum[i+1];
    }
    for(ll i=1;i<=m;i++){
        ll s;cin>>s;
        for(ll j=1;j<=s;j++){
            ll a;cin>>a;
            addb[i]+=sum[a];
        }
    }
    sort(addb+1,addb+m+1);
    for(ll i=1;i<=m;i++){
        now+=addb[i];
        ans+=now;
    }
    cout<<ans<<"\n";
    return 0;
}