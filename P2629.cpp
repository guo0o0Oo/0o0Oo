#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,a[N<<1],s[N<<1];
deque<ll> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
    for(ll i=1;i<=2*n;i++)s[i]=s[i-1]+a[i];
    ll ans=n;
    q.push_back(0);
    for(ll i=1;i<2*n;i++){
        while(!q.empty()&&q.front()<i-n)q.pop_front();
        while(!q.empty()&&s[q.back()]>=s[i])q.pop_back();
        q.push_back(i);
        if(i>=n&&s[q.front()]-s[i-n]<0)ans--;
    }
    cout<<ans<<"\n";
    return 0;
}