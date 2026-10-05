#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
pair<ll,ll> a[5010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+m+1);
    ll ans=0;
    for(ll i=1;i<=m;i++){
        if(n==0)break;
        ll g=min(a[i].second,n);
        ans+=g*a[i].first;
        n-=g;
    }
    cout<<ans<<"\n";
    return 0;
}