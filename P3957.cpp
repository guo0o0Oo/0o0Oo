#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=5e5+10;
ll n,d,k,x[N],a[N],dp[N];
deque<ll> q;
bool check(ll g){
    for(ll i=1;i<=n;i++)dp[i]=inf;
    dp[0]=0;
    q.clear();
    ll pos=0,l,r,res=inf;
    for(ll i=0;i<=n;i++){
        l=x[i]-d-g;r=min(x[i]-d+g,x[i]-1);
        while(x[pos]<l)pos++;
        while(!q.empty()&&x[q.front()]<l)q.pop_front();
        while(pos<=n&&l<=x[pos]&&x[pos]<=r){
            while(!q.empty()&&dp[q.back()]<dp[pos])q.pop_back();
            q.push_back(pos);
            pos++;
        }
        if(!q.empty()){
            dp[i]=dp[q.front()]+a[i];
            res=max(res,dp[i]);
        }
    }
    return res>=k;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>d>>k;
    for(ll i=1;i<=n;i++)cin>>x[i]>>a[i];
    ll l=0,r=N;
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    if(l==N)cout<<-1<<"\n";
    else cout<<l<<"\n";
    return 0;
}