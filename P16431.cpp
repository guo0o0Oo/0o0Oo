#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,c,k,a[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>c>>k;
    ll c;
    for(ll i=1;i<=n;i++)cin>>c,a[i]=a[i-1]+c;
    if(c*3<k){
        cout<<"-1\n";
        return;
    }
    ll ans=-1;
    for(ll i=0;i<=n;i++){
        ll l=lower_bound(a+i,a+n,a[i]*2)-a,r=lower_bound(a+i,a+n,a[i]*2+m)-a;
        while(l<r){
            ll mid=(l+r)>>1;
            if(a[n]-a[mid-1]-(a[mid]-a[i]))
        }
    }
    return 0;
}