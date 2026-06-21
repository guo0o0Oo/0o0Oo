#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[110][110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans+=a[(n+1)/2][i]+a[i][(n+1)/2]+a[i][i]+a[i][n-i+1];
    }
    ans-=a[(n+1)/2][(n+1)/2]*3;
    cout<<ans;
    return 0;
}