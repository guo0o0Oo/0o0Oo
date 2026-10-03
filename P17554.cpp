#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n;
        while(n%2==0)n/=2;
        while(n%5==0)n/=5;
        ll ans=0;
        while(n)n/=10,ans++;
        cout<<ans<<"\n";
    }
    return 0;
}