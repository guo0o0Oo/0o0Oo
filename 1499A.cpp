#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        ll n,k1,k2,w,b;
        cin>>n>>k1>>k2>>w>>b;
        ll s1=(k1+k2)/2;
        ll s2=(n+n-k1-k2)/2;
        if(s1>=w&&s2>=b)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}