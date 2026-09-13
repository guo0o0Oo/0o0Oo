#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[200];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=2;i<=n-1;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1])ans++;
    }
    cout<<ans;
    return 0;
}