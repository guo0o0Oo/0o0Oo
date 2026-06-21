#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=5e5+10;
ll n,m,a[N],s[N];
deque<ll> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)s[i]=a[i]+s[i-1];
    ll ans=inf;
    q.push_back(0);
    for(ll i=1;i<=n;i++){
        while(!q.empty()&&q.front()<i-m)q.pop_front();
        ans=max(ans,s[i]-s[q.front()]);
        while(!q.empty()&&s[i]<=s[q.back()])q.pop_back();
        q.push_back(i);
    }
    cout<<ans<<"\n";
    return 0;
}