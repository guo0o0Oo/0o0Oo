#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[10010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    ll flag=(a[2]>a[1]);
    ll ans=0;
    for(ll i=3;i<=n;i++){
        if((a[i]>a[i-1])!=flag){
            flag=(a[i]>a[i-1]);
            ans++;
        }
    }
    cout<<ans/2;
    return 0;
}