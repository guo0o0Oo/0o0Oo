#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll ma(ll n){
    ll res=0;
    while(n){
        res=max(res,n%10);
        n/=10;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll l=a+c,r=b+d;
        if(r-l+1>=10){
            cout<<9<<"\n";
            continue;
        }
        ll ans=0;
        for(ll i=l;i<=r;i++){
            ans=max(ans,ma(i));
        }
        cout<<ans<<"\n";
    }
    return 0;
}