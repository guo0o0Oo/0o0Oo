#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,c,a[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>c;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll i=n,j=n,ans=0;
    for(ll k=n;k>=1;k--){
        while(i>=1&&a[k]-a[i]<c)i--;
        while(j>=1&&a[k]-a[j]<=c)j--;
        if(i>=1&&a[k]-a[i]==c)ans+=i-j;
    }
    cout<<ans<<"\n";
    return 0;
}