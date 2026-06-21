#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=2;i<=n;i++){
        ans=ans*i+(i%2?-1:1);
    }
    cout<<ans<<"\n";
    return 0;
}