#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,k,cnt[N],s[N],dis[N];
priority_queue<ll,vector<ll>,greater<ll> > q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        ll a;cin>>a;
        cnt[a]++;
    }
    s[0]=cnt[0];
    for(ll i=1;i<=N;i++){
        s[i]=s[i-1]+cnt[i];
    }
    dis[0]=0;
    for(ll i=1;i<N;i++){
        dis[i]=dis[i-1]+s[i-1];
    }
    for(ll i=N-2;i>=0;i--){
        dis[i]=dis[i+1]-s[i]+(n-s[i]);
        q.push(dis[i]);
    }
    for(ll i=1;i<=N;i++){
        dis[0]+=n;
        q.push(dis[0]);
    }
    ll ans=0;
    for(ll i=1;i<=k;i++){
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<"\n";
    return 0;
}