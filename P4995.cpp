#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,a[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll l=0,r=n,ans=0;
    for(ll i=1;i<=n;i++){
        ans+=(a[l]-a[r])*(a[l]-a[r]);
        if(i&1)l++;
        else r--;
    }
    cout<<ans<<"\n";
    return 0;
}