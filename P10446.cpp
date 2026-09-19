#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll a,b,p;
    cin>>a>>b>>p;
    __int128 c=a,d=b;
    ll ans=c*d%p;
    cout<<ans;
    return 0;
}