#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,a[50010],fir[8],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    ll sum=0;
    for(ll i=1;i<=7;i++)fir[i]=inf;
    for(ll i=1;i<=n;i++){
        sum=(sum+a[i])%7;
        fir[sum]=min(fir[sum],i);
    }
    sum=0;
    for(ll i=1;i<=n;i++){
        sum=(sum+a[i])%7;
        ans=max(ans,i-fir[sum]);
    }
    cout<<ans<<"\n";
    return 0;
}