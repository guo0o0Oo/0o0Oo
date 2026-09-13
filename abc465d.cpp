#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll x,y,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;cin>>t;
    while(t--){
        ll ans=0;
        cin>>x>>y>>k;
        while(x*k>y){
            x/=k;
            ans++;
        }
        while(x*k+x<y){
            x=x*k+x-1;
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}