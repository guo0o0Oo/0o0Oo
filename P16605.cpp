#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,r;
ll cnt(ll k){
    ll s=n,ans=0;
    while(s){
        ans+=s%k;
        s/=k;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        cin>>n>>r;
        if(r>=n){
            cout<<1<<"\n";
            continue;
        }
        ll ans=sup;
        for(ll i=2;i<=min(ll(sqrt(n)+1),r);i++){
            ans=min(cnt(i),ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}